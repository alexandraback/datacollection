#pragma comment(linker, "/STACK:64000000")
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
#include <memory.h> 
using namespace std; 
 
#define forn(i, n) for(int i = 0; i < (int) (n); ++i) 
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i) 
 
#define ll long long 
#define ld long double 
#define PLL pair <ld, ld> 
#define PII pair <int, int> 
#define pb push_back 
#define sz size

const ld EPS = 1e-7; 

const int MAXN = 4100;

const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 9); 
const ld PI = 3.1415926535897932384626433832795; 
const int INF = 1e9;

ld a[MAXN][MAXN];

void outd(int test, ld ans) {
	printf("Case #%d: ", test + 1);
	cout << ans << endl;
}

int main()  { 
     
    freopen("input.txt","rt", stdin); 
	freopen("output.txt", "wt", stdout);   

	cout.precision(9);
	cout.setf(ios::fixed);

	int tk, n, x, y;
	cin >> tk;
	ld ans;

	forn(test, tk) {
		scanf("%d %d %d", &n, &x, &y);

		int lv = 0;
		x = abs(x);

		while (n > 4 * lv) {
			n -= 4 * lv + 1;
			++lv;
		}

		if ((x + y) / 2 < lv) {
			ans = 1;
			outd(test, ans);
			continue;
		}
		
		if (lv < (x + y) / 2) {
			ans = 0;
			outd(test, ans);
			continue;
		}


		//n
		//4 * lv + 1
		//2 * lv
		forn(i, 2 * lv + 1) {
			forn(j, 2 * lv + 1) {
				a[i][j] = 0;
			}
		}

		a[0][0] = 1;

		forn(c, 4 * lv + 1) {
			forn(i, c + 1) {
				if (i > 2 * lv + 1) break;

				int j = c - i;

				if (i == 2 * lv && j < 2 * lv) {
					a[i][j + 1] += a[i][j];
					continue;
				}
				if (j == 2 * lv && i < 2 * lv) {
					a[i + 1][j] += a[i][j];
					continue;
				}

				a[i][j + 1] += a[i][j] / 2;
				a[i + 1][j] += a[i][j] / 2;
			}
		}

		ans = 0;

		forn(j, n + 1) {
			int i = n - j;
			if (i > 2 * lv || j > 2 * lv || j < y + 1) continue;
			
			ans += a[i][j];
		}
		outd(test, ans);
	}
		
    return 0; 
}