#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <utility>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int) (n); ++i)
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i)

#define ll long long
#define ld long double
#define PLL pair <ld, ld>
#define PII pair <int, int>
#define pb push_back
#define sz size

const ld EPS = 1e-9;
const int MAXN = 200;
const int INF = (int)(2e9 + 1e-9);

int a[MAXN];
int cnt[MAXN][MAXN];

void up(int &a, int b){
	a = max(a, b);
}

int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);    

	int tk;
	scanf("%d\n", &tk);

	fore(tn, 1, tk + 1){
		int n, s, p;
		cin >> n >> s >> p;

		forn(i, n){
			scanf("%d", &a[i]);
		}

		memset(cnt, 255, sizeof cnt);

		cnt[0][0] = 0;

		forn(i, n){
			forn(j, s + 1){
				if (cnt[i][j] == -1) continue;

				fore(b, a[i] / 3, a[i] / 3 + 3){
					fore(x, b - 2, b + 1){
						int y = a[i] - x - b;

						if (y > x || y < 0 || b - y > 2) continue;

						int ds = (int)(b - y == 2);

						int dans = (int)(b > p - 1);

						up(cnt[i + 1][j + ds], cnt[i][j] + dans);
					}
				}
			}
		}

		printf("Case #%d: %d\n", tn, cnt[n][s]);
	}
	
	return 0;
}

