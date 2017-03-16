#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<functional>
#include<cctype>
#include<bitset>
#include<sstream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

#define MAX 30001
int n;
int m;
int p[MAX];
int b[MAX];

/*Shortest path*/

int dist[MAX];
vector<pair<int, int> > v[MAX];


int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++){
		scanf("%d%d", &b[i], &p[i]);
	}
	for (int i = 0; i<m; i++){
		if (i == 1){
			continue;
		}
		int start = b[i];
		int cc = 0;
		for (int j = start + p[i]; j<n; j += p[i]){
			cc++;
			//	cout<<start<<" "<<j<<" "<<cc<<endl;
			v[start].push_back(make_pair(j, cc));
		}
		cc = 0;
		for (int j = start - p[i]; j >= 0; j -= p[i]){
			cc++;
			//		cout<<start<<" "<<j<<" "<<cc<<endl;
			v[start].push_back(make_pair(j, cc));
		}
	}
	memset(dist, -1, sizeof(dist));
	dist[b[0]] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0,b[0]));
	while (!q.empty()){
		int cost = -q.top().first;
		int bb = q.top().second;
		q.pop();
		if (dist[bb] != cost){
			continue;
		}
		if (bb == b[1]){
			continue;
		}
		for (int i = 0; i<v[bb].size(); i++){
			int go = v[bb][i].first;
			int nex = cost + v[bb][i].second;
			if (dist[go] == -1 || dist[go]>nex){
				dist[go] = nex;
				q.push(make_pair(-nex, go));
			}
		}
	}
	int ans = dist[b[1]];
	printf("%d\n", ans);
	return 0;
}