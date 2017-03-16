#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;

const int N = 300;
const int INF = 2147483647;

int cap[N*N], dis[N];
int S = 249, D = 250, f; 

struct A{
	int th, rth, to;
	A(){}
	A(int a, int b, int c): th(a), rth(b), to(c) {}
}edge;

vector<A>G[N];

void add(int x, int y, int v){
//	cout << x << ' ' << y <<endl;
	edge = A(f, f+1, y);
	G[x].pb(edge);
	edge.to = x; swap(edge.th, edge.rth);
	G[y].pb(edge);
	cap[f] = v;
	f += 2;
}

bool bfs(){
	memset(dis, -1, sizeof(dis));
	queue<int>q;
	dis[S] = 0;
	q.push(S);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i = 0; i < G[x].size(); ++i){
			A& e = G[x][i];
			if(dis[e.to] < 0 && cap[e.th] > 0){
				dis[e.to] = dis[x] + 1;
				q.push(e.to);
			}
		}
	}
	if(dis[D] != -1) return 1;
	return 0;
}

int find(int x, int low){
	int a;
	if(x == D) return low;
	for(int i = 0; i < G[x].size(); ++i){
		A& e = G[x][i];
		if(cap[e.th] > 0 && dis[e.to] == dis[x] + 1 && (a = find(e.to, min(low, cap[e.th])))){
			cap[e.th] -= a;
			cap[e.rth] += a;
			return a;
		}
	}
	return 0;
}

int mf(){
	int res = 0;
	while(bfs()){
		int ex;
		while((ex = find(S, INF))) res += ex;
	}
	return res;
}

void init(){
	f = 0;
	memset(cap, 0, sizeof(cap));
	for(int i = 0; i < N; ++i) G[i].clear();
}

struct AA{
	int a, b, c;
};

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		init();
		int a, b, c, k;
		scanf("%d%d%d%d", &a, &b, &c, &k);
		for(int i = 0; i < a; ++i){
			for(int j = 0; j < b; ++j){
				add(S, 10*i+j, k);
			}
		}
		for(int i = 0; i < b; ++i){
			for(int j = 0; j < c; ++j){
				add(110+i*10+j,D,1);
			}
		}
		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				for(int k = 0; k < c; ++k)
						add(10*i+j, 110+10*j+k, 1);
		mf();
		map<int, int>mm;
		vector<AA>ans;
		for(int i = 0; i < 249; ++i){
			for(auto j : G[i]){
				if(j.to < i || j.to == D || j.to == S) continue;
			//	cout << i << ' ' << j.to <<endl;
				if(cap[j.th] == 0 && cap[j.rth] == 1){
					int x, y, z;
					x = i/10;
					y = i%10;
					z = j.to-110-y*10;
					// cout << i << ' ' << j.to <<endl;
					if(mm[x+y*20] == k ||
						mm[x+z*400] == k||
						mm[y*20+z*400] == k) continue;
					else{
						ans.pb({x+1, y+1, z+1});
					}
				}
			}
		}
		printf("Case #%d: %d\n", tt, ans.size());
		for(auto i : ans){
			printf("%d %d %d\n", i.a, i.b, i.c);
		}
	}
}