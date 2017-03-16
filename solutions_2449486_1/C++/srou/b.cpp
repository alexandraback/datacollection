#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char const *argv[]) {
	int T, N, M;
	int lawn[110][110];
	scanf("%d", &T);
	rep(t,0,T) {
		scanf("%d%d",&N,&M);
		rep (n, 0, N) {
			rep (m, 0, M) {
				scanf("%d",&(lawn[n][m]));
			}
		}
		bool ok = true;
		rep (n, 0, N) {
			rep (m, 0, M) {
				bool w1 = true, w2 = true;
				rep(i,0,N) {
					if(lawn[i][m]>lawn[n][m]) w1 = false;
				}
				rep (i, 0, M) {
					if(lawn[n][i]>lawn[n][m]) w2 = false;
				}
				ok = ok && (w1 || w2);
			}
		}
		printf("Case #%d: %s\n",t+1, ok?"YES":"NO");
	}
	return 0;
}