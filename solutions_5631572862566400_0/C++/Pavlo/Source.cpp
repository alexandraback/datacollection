//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<complex>
#include<set>
#include<algorithm>
#include <iomanip>

using namespace std;

typedef unsigned long long      ui64;
typedef long long               i64;
typedef long long               LL;
typedef vector<int>             VI;
typedef vector<bool>            VB;
typedef vector<VI>              VVI;
typedef vector<string>          VS;
typedef pair<int, int>           PII;
typedef map<string, int>         MSI;
typedef set<int>                SI;
typedef set<string>             SS;
typedef complex<double>         CD;
typedef vector< CD >            VCD;
typedef map<int, int>            MII;
typedef pair<double, double>     PDD;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (2000000000)

#ifdef _DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

int f[10000];
int mas[10];

void solve(int t) {
	cout << "Case #" + std::to_string(t) + ": ";
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> f[i];
		f[i]--;
		mas[i] = i;
	}
	int ans = 0;
	do {		

		FOR(k, 2, n+1) {
			bool ok = true;
			FOR(j, 0, k) {
				int l = j == 0 ? mas[k-1] : mas[j - 1],
					r = j == k-1 ? mas[0] : mas[j + 1];
				//cout << j << l << r << endl;
				if (f[mas[j]] != l && f[mas[j]] != r) {
					ok = false;
				}
			}
			if (ok) {
				//cout << "------" << endl;
				/*FOR(j, 0, k) {
					int l = j == 0 ? mas[k-1] : mas[j - 1],
						r = j == k - 1 ? mas[0] : mas[j + 1];
					cout << mas[j] << l << r << endl;
					if (f[mas[j]] != l && f[mas[j]] != r) {
						ok = false;
					}
				}*/
				/*FOR(i, 0, k)
					cout << mas[i];
				cout << endl;*/
				ans = max(ans, k);
			}
		}
	} while (std::next_permutation(mas, mas + n));
	cout << ans << endl;
}

int main() {
	freopen("C-small-attempt0 (1).in","r",stdin);
	freopen("C-amsll.out","w",stdout);
	int t;
	cin >> t;
	FOR(i, 0, t) {
		solve(i+1);
	}
	return 0;
}
