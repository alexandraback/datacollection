#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include <iomanip>

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<LL> vLL;

const int nmax = 59;

char mp[nmax][nmax];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	FOR(test, 1, T) {
		printf("Case #%d:\n", test);
		int R, C, M;
		cin >> R >> C >> M;
		if (M == R * C - 1) {
			REP(i, R) {
				REP(j, C) {
					if (i == 0 && j == 0)
						printf("c");
					else
						printf("*");
				}
				printf("\n");
			}
			continue;
		}

		if (R == 1 || C == 1) {
			REP(i, R) {
				REP(j, C) {
					if (i + j == 0)
						printf("c");
					if (i + j > 0 && i + j < R * C - M)
						printf(".");
					if (i + j >= R * C - M)
						printf("*");
				}
				printf("\n");
			}
			continue;
		}

		bool ok = false;
		FOR(i, 2, R) {
			FOR(j, 2, C) {
				int mn = i * 2 + j * 2 - 4;
				int mx = i * j;
				int m = R * C - M;
				if (mn <= m && m <= mx) {
					ok = true;
					int cnt = m - mn;
					REP(I, R) {
						REP(J, C) {
							if (I + J == 0) {
								printf("c");
								continue;
							}
							if (I < i && J < j) {
								if (I < 2 || J < 2) {
									printf(".");
									continue;
								}
								if (cnt == 0)
									printf("*");
								else
									printf("."), --cnt;
								continue;
							}
							printf("*");
						}
						printf("\n");
					}
				}
				if (ok)
					break;
			}
			if (ok)
				break;
		}
		if (!ok) {
			printf("Impossible\n");
		}
	}
	return 0;
}

