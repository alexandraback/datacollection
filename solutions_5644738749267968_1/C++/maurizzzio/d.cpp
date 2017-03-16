#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int cas, n;
	cin >> cas;
	F(z, cas) {
		cin >> n;
		vector<double> a(n), b(n);
		F(i, n) cin >> a[i];	
		F(i, n) cin >> b[i];

		sort(ALL(a));
		sort(ALL(b));

		// war
		vector<int> used(n, 0);
		int warPoints = 0;
		F(i, n) {
			int j = 0;
			for (j = 0; j < n; j += 1) {
				if (b[j] > a[n - i - 1] && !used[j]) {
					used[j] = 1;
					break;
				}
			}
			if(j == n)  {
				F(j, n) if (!used[j]) { used[j] = 1; break; }
				warPoints += 1;
			}
		}

		// cheat war
		vector<int> used2(n, 0);
		int cheatPoints = 0;
		F(i, n) {
			int j = 0;
			for (j = 0; j < n; j += 1) {
				if (a[j] > b[i] && !used2[j]) {
					cheatPoints += 1;
					used2[j] = 1;
					break;
				}
			}
			if(j == n)  {
				F(j, n) if (!used2[j]) { used2[j] = 1; break; }
			}
		}		
	
		printf("Case #%d: %d %d\n", z + 1, cheatPoints, warPoints);
		
	}
	return 0;
}