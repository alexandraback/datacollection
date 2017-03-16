#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define forn(i,n) for (int (i)=0; (i)<(n); (i)++)

using namespace std;
const int INF=~(1<<31);
const double EPS=1e-9;
const double PI=3.141592653589793;

bool dfs(vector<vector<int> >&g,vector<bool>&u,int v) {
	u[v]=1;
	forn(i,g[v].sz) {
		int to=g[v][i];
		if (u[to]) return 1;
		else if (dfs(g,u,to)) return 1;
	}
	return 0;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q=1; q<=t; q++) {
		int n,k,a;
		scanf("%d",&n);
		vector<vector<int> >g(n);
		forn(i,n) {
			scanf("%d",&k);
			forn(j,k) {
				scanf("%d",&a);
				g[i].pb(a-1);
			}
		}
		bool b=0;
		forn(i,n) {
			vector<bool>u(n,0);
			if (dfs(g,u,i)) {
				printf("Case #%d: Yes\n",q);
				b=1;
				break;
			}
		}
		if (!b) {
			printf("Case #%d: No\n",q);
		}
	}	
	return 0;
}