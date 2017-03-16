#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 100
int N;

int R, C, M;
int b[ MAXN ][ MAXN ];

struct cell{
	int x, y;
};
/*
void bfs(){
	int
	queue<int> qx;
	queue<int> qy;

	while(!qx.empty()) qx.pop();
	while(!qy.empty()) qy.pop();

	memset(b, 0, sizeof(b));

	forn(i, MAXN) {
		forn(j, MAXN) {
			b[i][j] = 1;	// mine
		}
	}

	// c
	qx.push(0);
	qy.push(0);
	b[0][0] = 0;

	while(!qx.empty()){
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();


	}

}*/

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		memset(b, 0, sizeof(b));

		scanf("%d%d%d", &R, &C, &M);
		printf("Case #%d:\n", casenum++);

		int left = R * C - M;
		int cnt = 0;
		int ansR = 0;
		int ansC = 0;


		if( R == 1 || C == 1 || left == 1) {
			forn(i, R) {
				forn(j, C) {
					if(i == 0 && j == 0) {
						printf("c");
						cnt++;
					} else if (cnt < left) {
						printf(".");
						cnt++;
					} else {
						printf("*");
					}

				}
				printf("\n");
			}
		}
		else {
			if (left <= 3) {
				printf("Impossible\n");
			}
			else {
				int q = 0;
				forn(i, R) {
					forn(j, C) {
						b[i][j] = 1;
					}
				}

				forn(i, MAXN) {
					if( i < 2 ) continue;
					if( i > R ) break;
					forn(j, MAXN) {
						if( j < 2 ) continue;
						if( j > C ) break;
						if( i * j < left ) continue;

						// verify the answer
						q = i * j - left;
						if(q != 0) {
							if((i + j - 1) - q < 4) continue;
							if(i == 2 || j == 2) continue;
						}

						ansR = i;
						ansC = j;

						forn(m, ansR) {
							forn(n, ansC) {
								b[m][n] = 0;
							}
						}

						if(q != 0) {
							forn(m, q) {
								if(ansR - m - 1 < 2) break;
								if(cnt > q) break;
								b[ansR - m - 1][ansC - 1] = 1;
								cnt++;
							}
							forn(m, q) {
								if(ansC - m - 1 < 2) break;
								if(cnt > q) break;
								b[ansR - 1][ansC - m - 1] = 1;
								cnt++;
							}
						}

						goto end;
					}
				}
end:
				if( ansR == 0 && ansC == 0 ) {
					//printf("Impossible %d %d %d\n", R, C, M);
					printf("Impossible\n");
				}
				else {
					b[0][0] = 2;
					forn(i, R) {
						forn(j, C) {
							if(b[i][j] == 2) {
								printf("c");
							} else if(b[i][j] == 1) {
								printf("*");
							} else if(b[i][j] == 0) {
								printf(".");
							}
						}
						printf("\n");
					}
				}
			}
		}

		//printf("%d\n", left);
		//printf("Case #%d: %.7lf\n", casenum++, ans);
		//

	}
	return 0;
}
