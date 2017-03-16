//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "B-small-attempt0"
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
		string s, t, ss, tt;
		cin >> s >> t;
		ss = s;
		tt = t;
		while (s.length() < 3)
			s = "0" + s;
		while (t.length() < 3)
			t = "0" + t;

		bool can1[1000], can2[1000];
		memset(can1, false, sizeof can1);
		memset(can2, false, sizeof can2);
		for (int i = 0; i < 1000; ++i)
		{
			if (s[2] != '?' && i % 10 != s[2] - '0')
				continue;
			if (s[1] != '?' && (i / 10) % 10 != s[1] - '0')
				continue;
			if (s[0] != '?' && i / 100 != s[0] - '0')
				continue;
			can1[i] = true;
		}
		for (int i = 0; i < 1000; ++i)
		{
			if (t[2] != '?' && i % 10 != t[2] - '0')
				continue;
			if (t[1] != '?' && (i / 10) % 10 != t[1] - '0')
				continue;
			if (t[0] != '?' && i / 100 != t[0] - '0')
				continue;
			can2[i] = true;
		}

		int delta = 999, ans1 = 0, ans2 = 999;
		for (int i = 0; i < 1000; ++i)
		{
			for (int j = 0; j < 1000; ++j)
			{
				if (can1[i] && can2[j])
				{
					if ((abs(i - j) < delta) || (abs(i - j) == delta && i < ans1)
						|| (abs(i - j) == delta && i == ans1 && j < ans2))
					{
						delta = abs(i - j);
						ans1 = i;
						ans2 = j;
					}
				}
			}
		}

		cout << "Case #" << it << ": ";
		if (ss.length() == 3)
		{
			cout << ans1 / 100 << (ans1 / 10) % 10 << ans1 % 10 << " ";
			cout << ans2 / 100 << (ans2 / 10) % 10 << ans2 % 10 << "\n";
		}
		else if (ss.length() == 2)
		{
			cout << ans1 / 10 << ans1 % 10 << " ";
			cout << ans2 / 10 << ans2 % 10 << "\n";
		}
		else
		{
			cout << ans1 << " " << ans2 << "\n";
		}
	}

	my_return(0);
}