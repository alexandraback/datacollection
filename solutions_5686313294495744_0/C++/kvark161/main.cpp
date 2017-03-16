// Smile please :)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#undef KVARK

#ifdef KVARK
	#include "../h/debug.h"
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#define dbg4(...) (void(1));
#define dbg5(...) (void(1));
#define dbgp(...) (void(1));
#define dbg_arr(...) (void(1));
#define dbg_vec(...) (void(1));
#endif

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<vector<long long> > vvl;
typedef vector<long long> vl;
typedef long long int llint;

#define ALL(v) (v.begin()), (v.end())
#define SZ(v) ((int)((v).size()))
#define endl "\n"

void task();

int main(){
#ifdef KVARK
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("src/gcj_input.txt", "r", stdin);
	freopen("src/gcj_output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(0));
#endif
//	ios_base::sync_with_stdio(0);

	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i+1);
		task();
		printf("\n");
	}

#ifdef KVARK_DEBUG
//	my_debug::printProcessInfo();
#endif
	return 0;
}
const int INF = 0x3f3f3f3f;
const int N = 3e5+10;
const int M = 3e5+10;

int n;
string a[N];
string b[N];

void task(){
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	int ans = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		set<string> s[2];
		for (int i = 0; i < n; ++i)
			if ((mask & (1 << i))) {
				s[0].insert(a[i]);
				s[1].insert(b[i]);
			}
		set<pair<string, string>> p;
		for (const string& s1: s[0])
			for (const string& s2: s[1])
				p.insert(pair<string, string>(s1, s2));
		int ok = 1;
		for (int i = 0; i < n; ++i)
			if ((mask & (1 << i)) == 0) {
				if (p.count(pair<string, string>(a[i], b[i])) == 0) {
					ok = 0;
					break;
				}
			}
		if (ok) {
			int c = 0;
			for (int i = 0; i < n; ++i)
				c += (mask & (1 << i)) == 0;
			ans = max(c, ans);
		}
	}
	cout << ans;
}
