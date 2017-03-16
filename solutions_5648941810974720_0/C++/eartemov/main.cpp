//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "A-small-attempt0"
#pragma comment(linker, "/STACK:536870912")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-6;
const int HASH_POW = 29;
const long double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(0));
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	int CASE;
	cin >> CASE;
	for (int it = 1; it <= CASE; ++it)
	{
		string s;
		cin >> s;
		multiset <int> ans;

		int cnt[26];
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < s.length(); ++i)
			++cnt[s[i] - 'A'];

		while (cnt['Z' - 'A'])
		{
			ans.insert(0);
			--cnt['Z' - 'A'];
			--cnt['E' - 'A'];
			--cnt['R' - 'A'];
			--cnt['O' - 'A'];
		}
		while (cnt['W' - 'A'])
		{
			ans.insert(2);
			--cnt['T' - 'A'];
			--cnt['W' - 'A'];
			--cnt['O' - 'A'];
		}
		while (cnt['U' - 'A'])
		{
			ans.insert(4);
			--cnt['F' - 'A'];
			--cnt['O' - 'A'];
			--cnt['U' - 'A'];
			--cnt['R' - 'A'];
		}
		while (cnt['X' - 'A'])
		{
			ans.insert(6);
			--cnt['S' - 'A'];
			--cnt['I' - 'A'];
			--cnt['X' - 'A'];
		}
		while (cnt['G' - 'A'])
		{
			ans.insert(8);
			--cnt['E' - 'A'];
			--cnt['I' - 'A'];
			--cnt['G' - 'A'];
			--cnt['H' - 'A'];
			--cnt['T' - 'A'];
		}
		while (cnt['H' - 'A'])
		{
			ans.insert(3);
			--cnt['T' - 'A'];
			--cnt['H' - 'A'];
			--cnt['R' - 'A'];
			--cnt['E' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['F' - 'A'])
		{
			ans.insert(5);
			--cnt['F' - 'A'];
			--cnt['I' - 'A'];
			--cnt['V' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['S' - 'A'])
		{
			ans.insert(7);
			--cnt['S' - 'A'];
			--cnt['E' - 'A'];
			--cnt['V' - 'A'];
			--cnt['E' - 'A'];
			--cnt['N' - 'A'];
		}
		while (cnt['O' - 'A'])
		{
			ans.insert(1);
			--cnt['O' - 'A'];
			--cnt['N' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['I' - 'A'])
		{
			ans.insert(9);
			--cnt['N' - 'A'];
			--cnt['I' - 'A'];
			--cnt['N' - 'A'];
			--cnt['E' - 'A'];
		}
		for (int i = 0; i < 26; ++i)
			assert(cnt[i] == 0);

		cout << "Case #" << it << ": ";
		for (multiset <int>::iterator iter = ans.begin(); iter != ans.end(); ++iter)
			cout << *iter;
		cout << "\n";
	}

	my_return(0);
}