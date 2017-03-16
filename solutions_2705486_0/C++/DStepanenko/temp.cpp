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
const int MAXD = (int)(1e6 + 1e-6);

const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 9); 
const ld PI = 3.1415926535897932384626433832795; 
const int INF = 1e9;

char tmp[MAXN];
string s;
string dict[MAXD];
int a[MAXN][5], sz[MAXD];
bool ok[300][300];

int main()  { 
     
    freopen("input.txt","rt", stdin); 
	freopen("output.txt", "wt", stdout);   

	FILE* dick = fopen("dictionary.txt", "r");
	int m = 0;

	while (!feof(dick)) {
		fscanf(dick, "%s", &tmp);
		dict[m] = tmp;
		sz[m] = dict[m].size();
		++m;
	}

	fclose(dick);

	int tk;
	cin >> tk;

	forn(test, tk) {
		scanf("%s", &tmp);
		s = tmp;
		int n = s.size();

		forn(i, n + 1) {
			forn(p, 5) {
				a[i][p] = n + 1;
			}
		}

		a[0][4] = 0;

		int f, l, cnt;

		forn(i, n) {
			forn(j, m) {
				if (i + sz[j] > n) continue;
				f = MAXN;
				l = -1;
				cnt = 0;

				forn(k, sz[j]) {
					if (dict[j][k] != s[i + k]) {
						++cnt;
						l = k;

						if (f == MAXN) {
							f = k;
						}
					}
				}

				l = min(sz[j] - l - 1, 4);
				
				forn(p, 5) {
					if (a[i][p] > n) continue;
					if (f < MAXN) {
						if (p + f + 1 < 5) continue;
						a[i + sz[j]][l] = min(a[i + sz[j]][l], a[i][p] + cnt);
						continue;
					}

					l = min(p + sz[j], 4);
					a[i + sz[j]][l] = min(a[i + sz[j]][l], a[i][p] + cnt);
				}
			}			
		}

		int ans = n + 1;

		forn(p, 5) {
			ans = min(ans, a[n][p]);
		}
		printf("Case #%d: %d\n", test + 1, ans);
	}	
	

    return 0; 
}