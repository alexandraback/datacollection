#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>
#include <numeric>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> inline void relaxmin(T& a, const T& b) { if (a > b) a = b; }
template<typename T> inline void relaxmax(T& a, const T& b) { if (a < b) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> int sign(T x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; } 

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

struct tribe {
	int t_idx;
	int t_w;
	int t_e;
	int t_s;
};

void Solve(int caseNo)
{
	int N;
	scanf("%d", &N);

	vector<int64> dd(N);
	vector<int64> nn(N);
	vector<int64> ww(N);
	vector<int64> ee(N);
	vector<int64> ss(N);
	vector<int64> delta_dd(N);
	vector<int64> delta_pp(N);
	vector<int64> delta_ss(N);
	forn(i,N) {
		cin >> dd[i];
		cin >> nn[i];
		cin >> ww[i];
		cin >> ee[i];
		cin >> ss[i];
		cin >> delta_dd[i];
		cin >> delta_pp[i];
		cin >> delta_ss[i];
	}

	//vector<int64> dates;
	map<int64, vector<tribe>> attacks;
	forn(i,N) {
		int64 day = dd[i];
		int64 s = ss[i];
		int64 w = ww[i];
		int64 e = ee[i];
		forn(j, nn[i]) {
			if (attacks.count(day) == 0) {
				tribe tr;
				tr.t_idx = j;
				tr.t_w = w;
				tr.t_e = e;
				tr.t_s = s;
				vector<tribe> v;
				v.push_back(tr);
				attacks[day] = v;
			} else {
				vector<tribe>& v = attacks[day];
				tribe tr;
				tr.t_idx = j;
				tr.t_w = w;
				tr.t_e = e;
				tr.t_s = s;
				v.push_back(tr);
			}
			day += delta_dd[i];
			s += delta_ss[i];
			w += delta_pp[i];
			e += delta_pp[i];
		}
	}

	const int shift = 400;
	vector<int> wall(1000);

	int64 ans = 0;
	for(map<int64, vector<tribe>>::iterator it = attacks.begin(); it != attacks.end(); ++it) {
		int64 day = it->first;
		vector<tribe> v = it->second;

		forn(i, v.size()) {
			// Check attack
			tribe tr = v[i];
			for(int64 x = 2*tr.t_w; x <= 2*tr.t_e; x++) {
				if (wall[x+shift] < tr.t_s) {
					ans++;
					break;
				}
			}
		}

		// Build wall
		forn(i, v.size()) {
			// Check attack
			tribe tr = v[i];
			for(int x = 2*tr.t_w; x <= 2*tr.t_e; x++) {
				if (wall[x+shift] < tr.t_s) {
					wall[x+shift] = tr.t_s;
				}
			}
		}
	}

	printf("Case #%d: %d\n", caseNo, ans);
	//printf( "%2.1f\n", ans );
}


int main()
{
	//if (freopen("c:\\_temp\\C.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\C.out", "wt", stdout) == NULL) throw 2;

	if (freopen("c:\\_temp\\C-small-attempt0.in", "rt", stdin) == NULL) throw 1;
	if (freopen("c:\\_temp\\C-small-attempt0.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\C_test.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\C_test.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\C-large.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\C-large.out", "wt", stdout) == NULL) throw 2;

	int caseCount;
	scanf("%d%", &caseCount);
	clock_t totalNow = clock();

	forab(i, 1, caseCount) {
		clock_t now = clock();
		cerr << "case " << i << "...";

		Solve(i);
		fflush(stdout);

		cerr << "Done!; Elapsed ms:" << (double)(clock() - now) * 1000 / CLOCKS_PER_SEC << "\n";
	}
	cerr << "Total elapsed seconds:" << (double)(clock() - totalNow) / CLOCKS_PER_SEC << "\n";

	exit(0);
}
