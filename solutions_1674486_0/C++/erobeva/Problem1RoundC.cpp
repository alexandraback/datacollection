/*
 *  Problem1RoundC.cpp
 *  GoogleCodeJamPractice
 *
 *  Created by Elina Robeva on 5/6/12.
 *  Copyright 2012 Stanford University. All rights reserved.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <vector>
#include <iomanip>
#include <queue>
#include <set>
using namespace std;


int main() {
	freopen("/Users/erobeva/Downloads/A-small-attempt0 (4).in","r",stdin);
	freopen("/Users/erobeva/Downloads/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOut.txt", "w", stdout);
	int T;
	cin >> T;
	
	for(int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<int> M(N);
		vector<int> sources(N, -1);
		int num_sources = 0;
		vector<vector<int> > graph(N);
		vector<vector<int> > grid(N);
		for(int j = 0; j < N; ++j) {
			
			cin >> M[j];
			vector<int> gr(M[j]);
			vector<int> grid1(N, 0);
			for(int t = 0; t < M[j]; ++t) {
				int a;
				cin >> a;
				gr[t] = a-1;
				grid1[a-1]++;
			}
			graph[j] = gr;
			grid[j] = grid1;
		}
		
		for(int j = 0; j < N; ++j){
			int sum = 0;
			for(int k = 0; k < N; ++k){
				sum += grid[k][j];
			}
			if(sum == 0) {
				sources[num_sources] = j;
				num_sources++;
			}
		}
		
		int yes = 0;
		for(int s = 0; s < num_sources; ++s){
			int j = sources[s];
				queue<int> qu;
				set<int> seen;
				qu.push(j);
				seen.insert(j);
				int num_edges = 0;
				int num_vertices = 1;
				while(!qu.empty() && yes != 1){
					int x = qu.front();
					qu.pop();
					for(int l = 0; l < M[x]; ++l) {
						if(seen.find(graph[x][l]) == seen.end()) {
							seen.insert(graph[x][l]);
							num_edges++;
							num_vertices++;
							qu.push(graph[x][l]);
						} else {
							num_edges++;
							yes = 1;
							break;
						}
					}
				}
				if(num_vertices - num_edges < 1){
					yes = 1;
					break;
				}
			
		}
		if(yes == 1) {
			cout << "Case #" << i + 1 << ": " << "Yes" << endl;
		} else {
			cout << "Case #" << i + 1 << ": " << "No" << endl;
		}
	}

}