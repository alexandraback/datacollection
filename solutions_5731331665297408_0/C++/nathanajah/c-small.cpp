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

vector <int> permutation;
string mini;
int t,n,m;
int i,j,k;
bool adj[10][10];
string zip[10];

int main()
{
	int cs = 0;
	scanf("%d",&t);
	while (t--) {
		permutation.clear();
		memset(adj,0,sizeof(adj));
		printf("Case #%d: ",++cs);
		scanf("%d %d",&n,&m);
		for (i=0;i<n;++i)
			zip[i] = GetString();
		for (i=0;i<m;++i) {
			int v1,v2;
			scanf("%d %d",&v1,&v2);
			--v1;--v2;
			adj[v1][v2] = true;
			adj[v2][v1] = true;
		}
		string mini = "";
		for (i=0;i<6*n;++i)
			mini.append(1,'9');
		for (i=0;i<n;++i)
			permutation.pb(i);
		do {
			bool can = true;
			string res = "";
			stack <int> positionNow;
			positionNow.push(permutation[0]);
			res += zip[permutation[0]];
			for (i=1;i<n;++i) {
				res += zip[permutation[i]];
				while (!positionNow.empty()) {
					if (adj[positionNow.top()][permutation[i]])
						break;
					positionNow.pop();
				}
				if (positionNow.empty()) {
					can = false;
					break;
				}
				positionNow.push(permutation[i]);
			}
			if (can && res < mini)
				mini = res;
		} while (next_permutation(permutation.begin(),permutation.end()));
		printf("%s\n",mini.c_str());
	}
}
