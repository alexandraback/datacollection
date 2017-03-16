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

string a;
string b;
string s;
string _s;
int ansAbs = 1e9;
int sum = 1e9;
int j = 1e9;
string ans;

void solve(int i) {
	if (i == s.length()) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < s.length() / 2; ++i)
			a *= 10, a += s[i] - '0';
		for (int i = s.length() / 2; i < s.length(); ++i)
			b *= 10, b += s[i] - '0';
		if (abs(a - b) < ansAbs) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		if (abs(a - b) == ansAbs && a + b < sum) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		if (abs(a - b) == ansAbs && a + b == sum && b < j) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		return;
	}
	if (_s[i] != '?') {
		s[i] = _s[i];
		solve(i+1);
		return;
	}
	for (int j = 0; j < 10; ++j) {
		s[i] = j + '0';
		solve(i+1);
	}
}

void task(){
	ansAbs = 1e9;
	sum = 1e9;
	j = 1e9;
	cin >> a >> b;
	s = a + b;
	_s = a + b;
	solve(0);
	cout << ans;
}
