#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <utility>
#include <deque>
#include <list>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define forl(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<=int(b); ++i)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define ll long long
#define pii pair <int,int>
#define sz(a) a.size()
#define np next_permutation

const int INF = (int)1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
bool ineedoutputfile = true;
vector < vector <int> > g;
bool used[1001];
int cnt;
void dfs(int s, int y) {
	if (s==y) {
		cnt++;
		return;
	}
	used[s]=true;
	for(int i=0; i<g[s].size(); i++)
		if(!used[g[s][i]])
			dfs(g[s][i],y);
}
int main () {
#ifndef ONLINE_JUDGE
		freopen("input.txt","rt",stdin);
	if (ineedoutputfile)
		freopen("output.txt","wt",stdout);
#endif
	int testcases;
	cin >> testcases;
	for(int r = 1; r <=testcases; r++) {
		g.clear();
		printf("Case #%d: ",r);
		bool ok = false;
		int N;
		scanf("%d",&N);
		g.resize(N);
		forn(i,N) {
			int t;
			scanf("%d",&t);
			forn(j,t) {
				int a;
				scanf("%d",&a);
				a--;
				g[i].pb(a);
			}
		}
		forn(i,N) {
			forn(j,N) {
				if (i==j)
					continue;
				memset(used,0,sizeof(used));
				cnt=0;
				dfs(i,j);
				if(cnt>=2)
					ok = true;
			}
		}
		if (ok)
			puts("Yes");
		else
			puts("No");
	}
}
