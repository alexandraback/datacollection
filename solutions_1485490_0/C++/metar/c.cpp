#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long ulong;
typedef unsigned long long ull;

const int LEN = 112;

ll a[LEN], b[LEN];
int A[LEN], B[LEN];

int pA[LEN];
int pB[LEN];
int lA[LEN];
int lB[LEN];

ll dp[LEN][LEN];

int main() {
	//freopen("problem.in", "r", stdin);
	//freopen("problem.out", "w", stdout);
	int T, N, M;
	cin >> T;
	FOR(Ti,1,T) {
		cin >> N >> M;
		REP(i,LEN)
			pA[i] = pB[i] = lA[i] = lB[i] = -1;
		REP(i,N) {
			cin >> a[i] >> A[i];
			pA[i] = lA[A[i]];			
			lA[A[i]] = i;
		}
		REP(i,M) {
			cin >> b[i] >> B[i];
			pB[i] = lB[B[i]];
			lB[B[i]] = i;
		}
		REP(i,N)
			REP(j,M) {
				dp[i][j] = 0;
				if (A[i] == B[j]) {
					ll sA = a[i], sB = b[j];
					int k = i, m = j;
					while (k >= 0 && m >= 0) {
						if (k*m > 0)
							dp[i][j] = max(dp[i][j], dp[k-1][m-1]+min(sA, sB));
						else
							dp[i][j] = max(dp[i][j], min(sA, sB));
						if (sA > sB) {
							m = pB[m];
							if (m < 0)
								break;
							sB += b[m];
						} else if (sA < sB) {
							k = pA[k];
							if (k < 0)
								break;
							sA += a[k];
						}	else
							break;						
					}
				}
				if (j)
					dp[i][j] = max(dp[i][j], dp[i][j-1]);
				if (i)
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
		printf("Case #%d: %lld\n", Ti, dp[N-1][M-1]);
	}
	return 0;
}