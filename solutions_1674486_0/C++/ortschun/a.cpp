#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
const int MAXN = 10005;
int cap[MAXN][MAXN], tmpcap[MAXN][MAXN], N, M, q[MAXN], sz = 0, prev[MAXN];
int bfs(int src, int snk){
	memset(prev, -1, sizeof prev);
	sz = 0;
	prev[src] = -2;
	q[sz ++] = src;
	for(int t = 0; t != sz; t ++){
		int from = q[t];
		for(int i = 0; i < N; i ++) if(prev[i] == -1 && cap[from][i] > 0){
			prev[i] = from;
			q[sz ++] = i;
		}
	}
	
	if(prev[snk] == -1) return -1;
	for(int from = snk; from != src; from = prev[from]){
		cap[prev[from]][from] --;
		cap[from][prev[from]] ++;
	}
	return 1;
}
int max_flow(int src, int snk){
	int ret = 0, tot = 0;
	REP(i, N){
		REP(j, N){
			cap[i][j] = tmpcap[i][j];
		}
	}
	while((tot = bfs(src, snk)) != -1){
		ret ++;
	}
	return ret;
}
int main() {
	//freopen("a.in", "r", stdin); 
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	freopen("A-small-attempt2.in", "r", stdin); freopen("A-small-attempt2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("A-small-attempt3.out", "w", stdout);
	
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		memset(cap, 0, sizeof cap);
		memset(tmpcap, 0, sizeof tmpcap);
		cin>>N;
		REP(i, N){
			cin>>M;
			REP(j, M){
				int a; cin>>a;
				cap[a - 1][i] = tmpcap[a - 1][i] = 1;
			}
		}
		bool ret = false;
		for(int i = 0; i < N; i ++){
			for(int j = 0; j < N; j ++) if(i != j) {
				if(max_flow(i, j) >= 2){
					ret = true;
				}
			}
		}
		
		printf("Case #%d: ", t);
		if(ret){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
