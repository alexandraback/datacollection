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

const int MAXN = 200;

const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 9); 
const ld PI = 3.1415926535897932384626433832795; 
const int INF = 1e9;

int a[MAXN];

int main()  { 
     
    freopen("input.txt","rt", stdin); 
	freopen("output.txt", "wt", stdout);   

	int tk, x, n;
	cin >> tk;

	forn(test, tk) {
		scanf("%d %d", &x, &n);

		forn(i, n) {
			scanf("%d", &a[i]);
		}

		sort(a, a + n);

		int j = 0, cnt = 0;
		int ans = n;

		while (j < n) {
			if (a[j] < x) {
				x += a[j];
				++j;
				continue;
			}
			ans = min(ans, cnt + n - j);

			if (x == 1) break;

			while (a[j] >= x) {
				x += x - 1;
				++cnt;
			}
		}
		
		if (j == n) {
			ans = min(ans, cnt);
		}

		printf("Case #%d: %d\n", test + 1, ans);
	}
		
    return 0; 
}