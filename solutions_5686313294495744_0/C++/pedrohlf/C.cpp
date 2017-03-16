#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

pair<string,string> v[20];
bool r[20];
vector<int> G1[1005], G2[1005];
int dg1[1005], dg2[1005],aux;
bool vis1[1005], vis2[1005];
int ans;

void dfs1(int v){
	vis1[v] = 1;
	for(int x : G1[v]){
		dg1[v]--;
		if(!vis1[x]){dfs1(x);}
	}
}

void dfs2(int v){
	vis2[v] = 1;
	for(int x : G2[v]){
		dg2[v]--;
		if(!vis2[x]) dfs2(x);
	}
}

int main() {
	int t,i,n,j,tc=1;
	string s1,s2;

	cin >> t;
	while(t--){
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> v[i].ff >> v[i].ss;
		
		ans = 0;
		memset(r,0,sizeof(r));
		for(i = 0; i < n; i++){
			char flag = 0;
			for(j = 0; j < n; j++){
				if(j == i) continue;
				if(v[i].ff.compare(v[j].ff)	== 0){
					flag = 1;	
					break;
				}
			}
			for(j = 0; j < n && flag; j++){
				if(j == i) continue;
				if(v[i].ss.compare(v[j].ss)	== 0){
					flag++;
					ans++;
					break;
				}
			}
			if(flag < 2) r[i] = 1;
		}
		memset(dg1,0,sizeof(dg1));
		memset(dg2,0,sizeof(dg2));
		for(i = 0; i < n; i++){
			if(r[i]) continue;
			bool salvei1 = 0, salvei2 = 0;
			vector<int> x1,x2;

			for(j = 0; j < n; j++){
				if(i == j) continue;
				if(v[i].ff.compare(v[j].ff) == 0){
					if(r[j]) salvei1 = true;
					else x1.push_back(j);
				}
				if(v[i].ss.compare(v[j].ss) == 0){
					if(r[j]) salvei2 = true;
					else x2.push_back(j);
				}
			}
			if(!salvei1){G1[i] = x1;dg1[i]+=x1.size(); aux+=x1.size();}
			if(!salvei2){G2[i] = x2;dg2[i]+=x2.size(); aux+=x2.size();}
		}

		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		while(1){
			int tmp = 0, vert;
			for(j = 0; j < n; j++){
				if(r[j]) continue;
				if(tmp < dg1[j]+dg2[j]){
					tmp = dg1[j]+dg2[j];
					vert = j;
				}
			}
			if(!tmp) break;
			ans--;
			if(dg1[vert]){
				dfs1(vert);
			}
			if(dg2[vert]){
				dfs2(vert);
			}
			dg1[vert] = dg2[vert] = 0;
		}

		for(i = 0; i < n; i++){
			G1[i].clear();
			G2[i].clear();
		}
		printf("Case #%d: %d\n", tc++, ans);
	}

	return 0;
}
