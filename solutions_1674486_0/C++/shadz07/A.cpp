#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000000000LL
#define INF 2123123123
#define pb push_back
using namespace std;

int cek[1005];
vi edge[1005];

int ff(int x, int y) {
	if (x == y)
		return 1;
	
	if (cek[x] != -1)
		return cek[x];
	
	int sz = edge[x].size();
	int &ret = cek[x] = 0;
	
	REP(i, sz)
		ret += ff(edge[x][i], y);
	
	return ret;
}

int main()
{
	int a, n, m, T;
	
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%d", &n);
		
		FORU(i, 1, n) {
			scanf("%d", &m);
			
			edge[i].clear();
			
			REP(j, m) {
				scanf("%d", &a);
				
				edge[i].pb(a);
			}
		}
		
		bool ada = false;
		
		for (int i = 1; (i <= n) && (!ada); ++i) {
			for (int j = 1; (j <= n) && (!ada); ++j) {
				if (i != j) {
					memset(cek, -1, sizeof(cek));
					ada = (ff(i, j) > 1);
				}
			}
		}
		
		printf("Case #%d: ", tc);
		
		if (ada)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
