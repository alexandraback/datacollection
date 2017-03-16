#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <cassert>
#include <ctime>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define mp(x, y) make_pair(x, y)
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;

inline int ord(char c)
{
	return c - 'A';
}

void solve()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		string str;
		cin >> str;
		vector<int> cnt(26, 0);
		for (int i = 0; i < str.size(); ++i)
			cnt[ord(str[i])]++;
		vector<int> digits(10, 0);
		digits[0] = cnt[ord('Z')];
		cnt[ord('Z')] -= digits[0];
		cnt[ord('E')] -= digits[0];
		cnt[ord('R')] -= digits[0];
		cnt[ord('O')] -= digits[0];
		digits[6] = cnt[ord('X')];
		cnt[ord('S')] -= digits[6];
		cnt[ord('I')] -= digits[6];
		cnt[ord('X')] -= digits[6];
		digits[2] = cnt[ord('W')];
		cnt[ord('T')] -= digits[2];
		cnt[ord('W')] -= digits[2];
		cnt[ord('O')] -= digits[2];
		digits[8] = cnt[ord('G')];
		cnt[ord('E')] -= digits[8];
		cnt[ord('I')] -= digits[8];
		cnt[ord('G')] -= digits[8];
		cnt[ord('H')] -= digits[8];
		cnt[ord('T')] -= digits[8];
		digits[3] = cnt[ord('T')];
		cnt[ord('T')] -= digits[3];
		cnt[ord('H')] -= digits[3];
		cnt[ord('R')] -= digits[3];
		cnt[ord('E')] -= digits[3];
		cnt[ord('E')] -= digits[3];
		digits[7] = cnt[ord('S')];
		cnt[ord('S')] -= digits[7];
		cnt[ord('E')] -= digits[7];
		cnt[ord('V')] -= digits[7];
		cnt[ord('E')] -= digits[7];
		cnt[ord('N')] -= digits[7];
		digits[4] = cnt[ord('U')];
		cnt[ord('F')] -= digits[4];
		cnt[ord('O')] -= digits[4];
		cnt[ord('U')] -= digits[4];
		cnt[ord('R')] -= digits[4];
		digits[5] = cnt[ord('F')];
		cnt[ord('F')] -= digits[5];
		cnt[ord('I')] -= digits[5];
		cnt[ord('V')] -= digits[5];
		cnt[ord('E')] -= digits[5];
		digits[9] = cnt[ord('I')];
		cnt[ord('N')] -= digits[9];
		cnt[ord('I')] -= digits[9];
		cnt[ord('N')] -= digits[9];
		cnt[ord('E')] -= digits[9];
		digits[1] = cnt[ord('O')];
		cnt[ord('O')] -= digits[1];
		cnt[ord('N')] -= digits[1];
		cnt[ord('E')] -= digits[1];

		for (int i = 0; i < 26; ++i)
			assert(cnt[i] == 0);
		cout << "Case #" << tt << ": ";
		for (int i = 0; i <= 9; ++i)
			for (int j = 0; j < digits[i]; ++j)
				cout << i;
		cout << endl;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	solve();

	return 0;
}