#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const int N = 1e6 + 23;
const int mat[4][4] = {{1, 2, 3, 4},
			  {2, -1, 4, -3},
			  {3, -4, -1, 2},
			  {4, 3, -2, -1}};

struct tintin
{
	int ch;
	tintin(char s)
	{
		if (s == '1') ch = 1;
		else if (s == 'i') ch = 2;
		else if (s == 'j') ch = 3;
		else if (s == 'k') ch = 4;
		else ch = 1234;
	}
	tintin(int c) : ch(c) {}
	tintin operator * (const tintin& nxt) const
	{
		int fst = ch, snd = nxt.ch, sgn = 1;
		if (fst < 0) fst = -fst, sgn = -sgn;
		if (snd < 0) snd = -snd, sgn = -sgn;
		return tintin(sgn * mat[fst - 1][snd - 1]);
	}
};

string s, ss;

bool go()
{
	int n = s.size();
	tintin cur(1ll);
	int want = 2;
	for (int i = 0; i < n; i++)
	{
		cur = cur * tintin(s[i]);
		if (want == 4) continue;
		if (cur.ch == want)
			cur.ch = 1, want++;
	}
	if (want < 4 or cur.ch != want) return false;
	return true;
}

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";

		int k;
		cin >> k >> k >> ss;
		if (k > 12) k = k % 4 + 12;
		if (k > 12) k -= 4;
		s = "";
		while (k--) s += ss;
		bool ans = go();

		if (tt > 1) cout << "\n";
		cout << "Case #" << tt << ": " << (ans ? "YES" : "NO");
	}
	return 0;
}