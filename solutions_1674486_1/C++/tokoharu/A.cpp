#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;


const int NUM = 1000;


int main() {
	int t;
	int T;
	cin>>t;
	T=t;
	for(;t;t--) {
		vector<int>start;
		int n;
		cin>>n;
		vector<int>graph[NUM];
	//	for(int a=0; a<NUM; a++) graph[a].clear();
		for(int a=0; a<n ; a++) {
			int p;
			cin>>p;
			for(int b=0; b<p; b++) {
				int q;
				cin>>q;
				graph[q-1].push_back(a);
			}
			if(p==0) start.push_back(a);
		}
		
		
		bool ok = false;
		for(int z=0; z<start.size(); z++ ) {
			
			
			queue<int>data;
			data.push(start[z]);
			
			
			bool used[1000];
			for(int a=0; a<1000; a++) used[a] = false;
		
			while(!data.empty() && !ok) {
				int p = data.front();
				data.pop();
			//	cout<<p<<endl;
				
				for(int a=0; a<graph[p].size(); a++) {
					data.push(graph[p][a]);
					if(used[graph[p][a]]) ok = true;
					used[graph[p][a]] = true;
					
				}
			}
		}
		
		if(ok) cout<<"Case #"<<T-t+1<<": "<<"Yes"<<endl;
		else cout<<"Case #"<<T-t+1<<": "<<"No"<<endl;
		
	}
	return 0;
	
}


