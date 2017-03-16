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

const string str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


string s2[] = {
"ZERO",
"SIX",
"SEVEN",
"FIVE",
"FOUR",
"THREE",
"EIGHT",
"TWO",
"NINE",
"ONE"};

string s;
int b[256];
vi ans;

void solve(int i) {
	map<char, int> mp;
	for (char c: str[i])
		mp[c]++;
	while (1) {
		int ok = 1;
		for (pii p: mp)
			if (b[p.first] < p.second)
				ok = 0;
		if (!ok)
			return;
		ans.push_back(i);
		for (pii p: mp)
			b[p.first] -= p.second;
	}
}

void task(){
	cin >> s;
	ans.clear();
	memset(b, 0, sizeof(b));
	for (char c: s)
		++b[c];
	solve(0);
	solve(6);
	solve(7);
	solve(5);
	solve(4);
	solve(3);
	solve(8);
	solve(2);
	solve(9);
	solve(1);
	sort(ALL(ans));
	for (int x: ans)
		cout << x;
}
