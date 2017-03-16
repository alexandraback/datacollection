#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cmath>


using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;



#define REP(i, a) for (int i = 0; i < a; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REPD(i, a) for (int i = a - 1; i >= 0; i--)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define CLEAR(x, val) memset(x, val, sizeof(x))

int n;
vi adj[1010];
int flag[1010];
int c[1010];
bool adaa;

void ada (int node) {
	//cout << "node = " << node << endl;
	flag[node] = 1;
	int len = adj[node].size(), u;
	
	REP(i, len) {
		u = adj[node][i];
		if (flag[u] == 0) {
			ada(u);
		}	
		else if (flag[u] == 2)
			adaa = 1;
	}
	
	flag[node] = 2;
}

int main () {
		
		int tc;
		scanf("%d", &tc);
		
		FOR(i, 1, tc) {
			CLEAR(flag, 0);
			CLEAR(c, 0);
			
			scanf("%d", &n);
			REP(ii, n) {
				int sum, tmp;
				scanf("%d", &sum);
				adj[ii].clear();
				
				REP(j, sum) {
					scanf("%d", &tmp);
					adj[ii].pb(tmp - 1);
					c[tmp - 1]++;
					//cout << "a = " << ii + 1 << " b = " << tmp << endl;
				}
			}
			
			bool ans = 0;
			adaa= 0;
			REP(ii, n) {
				//if (c[ii] == 0) {
					//cout << "II = " << ii << endl;
					//CLEAR(flag, 0);
					if (flag[ii] == 0)
						ada(ii);
				//}
			}
			ans = adaa;
			printf("Case #%d: ", i);
			if (ans) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
}














