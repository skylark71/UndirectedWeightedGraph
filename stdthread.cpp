#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

const int size = 5;
vector<pair<int, int>> adj[size];

// To add an edge
void addEdge(int u, int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation ot graph
void printGraph(int start, int end)
{
	int v, w;
	int max =0;
	int u = 0;
	int m = 0;
	bool visit[size];

	for(int j=0; j<size;j++){
		visit[j] = false;
	}

	u = start;
	cout <<"Node:"<<start << " - ";
	while (u != end)
	{
	    if (visit[u]){
	        cout << "Node:"<< end << " Unreachable";
	        break;
	    }
		visit[u] = true;
		m+= max;
		max = 0;
		int temp = adj[u].back().first;
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
		{
			v = it->first;
			w = it->second;

			if (w>max && !visit[v]){
				max = w;
				u = v;
			}

			if (temp == v){
				cout << "Weight:"<< max << " - " << "Node:"<<u << " - ";
				break;
			}	
		}
	}
}

/*int main()
{
    auto begin = std::chrono::steady_clock::now();
    int start = 2;
    int till = 1;
	addEdge(0, 1, 5);
	addEdge(0, 2, 6);
	addEdge(2, 1, 4);
	std::thread thr(printGraph, start, till);
	thr.join();
	auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "\nThe time: " << elapsed_ms.count() << " ms\n";
	return 0;
}*/

// Driver code
int main()
{
    auto begin = std::chrono::steady_clock::now();
	int start = 0;
    int till = 4;
	addEdge(0, 1, 5);
	addEdge(0, 2, 10);
	addEdge(2, 1, 20);
	addEdge(1, 3, 40);
	addEdge(1, 4, 50);
	addEdge(0, 3, 60);
	addEdge(3, 4, 70);
	std::thread thr(printGraph, start, till);
	thr.join();
	auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "\nThe time: " << elapsed_ms.count() << " ms\n";
	return 0;
}
