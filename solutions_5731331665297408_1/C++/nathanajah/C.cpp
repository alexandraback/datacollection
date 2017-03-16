//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE
vector <int> adj[55];
string zip[55];
int t,n,m;
int i,j,k;
bool sudah[55];
bool sudah2[55];
string res;
vector <int> pathnow;
vector <int> tmppath;
set <int> candidates;
bool adjmatr[105][105];

void dfs2(int x) {
	int i;
	for (i=0;i<SZ(adj[x]);++i) {
		if (!sudah[adj[x][i]] && !sudah2[adj[x][i]]) {
			sudah2[adj[x][i]] = true;
			dfs2(adj[x][i]);
		}
	}
}

bool can(int x) {
	int i;
	for (i=0;i<n;++i)
		sudah2[i] = false;
	sudah2[x] = true;
	dfs2(x);
	for (i=0;i<SZ(tmppath);++i)
		dfs2(tmppath[i]);
	for (i=0;i<n;++i)
		if (!sudah2[i] && !sudah[i])
			return false;
	return true;
}

int main()
{
	scanf("%d",&t);
	int cs = 0;
	while (t--) {
		printf("Case #%d: ",++cs);
		pathnow.clear();
		tmppath.clear();
		candidates.clear();
		memset(sudah,0,sizeof(sudah));
		res = "";
		scanf("%d %d",&n,&m);
		for (i=0;i<n;++i)
			adj[i].clear();
		memset(adjmatr,0,sizeof(adjmatr));
		for (i=0;i<n;++i)
			zip[i] = GetString();
		for (i=0;i<m;++i) {
			int v1,v2;
			scanf("%d %d",&v1,&v2);
			--v1;--v2;
			adj[v1].pb(v2);
			adj[v2].pb(v1);
			adjmatr[v1][v2] = true;
			adjmatr[v2][v1] = true;
		}
		int nummin = 0;
		for (i=0;i<n;++i) {
			if (zip[i] < zip[nummin])
				nummin = i;
		}
		res = zip[nummin];
		sudah[nummin] = true;
		pathnow.push_back(nummin);
		for (i=1;i<n;++i) {
			candidates.clear();
			tmppath = pathnow;
			for (j=0;j<SZ(pathnow);++j) {
				for (k=0;k<SZ(adj[tmppath[SZ(tmppath)-1]]);++k) {
					if (!sudah[adj[tmppath[SZ(tmppath)-1]][k]] && candidates.find(adj[tmppath[SZ(tmppath)-1]][k]) == candidates.end()) {
						if (can(adj[tmppath[SZ(tmppath)-1]][k]))
							candidates.insert(adj[tmppath[SZ(tmppath)-1]][k]);
					}
				}
				tmppath.pop_back();
			}
			vector <int> candlist;
			candlist.clear();
			for (set<int>::iterator it = candidates.begin(); it!=candidates.end(); it++) {
				candlist.push_back(*it);
			}
			int nummin = candlist[0];
			for (j = 0; j< SZ(candlist);++j) {
				if (zip[candlist[j]] < zip[nummin])
					nummin = candlist[j];
			}
			while (!adjmatr[pathnow[SZ(pathnow)-1]][nummin])
				pathnow.pop_back();
			pathnow.push_back(nummin);
			res+=zip[nummin];
			sudah[nummin] = true;
		}
		printf("%s\n",res.c_str());
	}
}
