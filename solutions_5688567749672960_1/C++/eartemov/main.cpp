/*
ID: eoart2
PROG: transform
LANG: C++
*/
//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <cassert>
#include <random>

const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-10;
const int HASH_POW = 7;
const double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

const long long steps[15] = {0ll, 10ll, 29ll, 138ll, 337ll, 1436ll, 3435ll, 14434ll,
	34433ll, 144432ll, 344431ll, 1444430ll, 3444429ll, 14444428ll, 34444427ll};

int length(long long num)
{
	int ans = 0;
	while (num)
	{
		++ans;
		num /= 10;
	}
	return ans;
}

string IntToStr(long long n)
{
	string ans = "";
	while (n)
	{
		ans = char('0' + n % 10) + ans;
		n /= 10;
	}
	return ans;
}

long long StrToInt(string s)
{
	long long ans = 0;
	for (int i = 0; i < s.length(); ++i)
		ans = 10*ans + (s[i] - '0');
	return ans;
}

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	#endif

	int CASE;
	scanf("%d", &CASE);
	for (int t = 1; t <= CASE; ++t)
	{
		long long n;
		scanf("%lld", &n);
		long long ans = 0;
		if (n <= 20)
			ans = n;
		else
		{
			bool add1 = false;
			if (n % 10 == 0)
			{
				add1 = true;
				--n;
			}
			ans += steps[length(n) - 1];
			string s = IntToStr(n);
			int k1 = s.length()/2, k2 = s.length() - k1;
			string s1 = "", s2 = "";
			for (int j = 0; j < k1; ++j)
				s1 += s[k1 - 1 - j];
			for (int j = 0; j < k2; ++j)
				s2 += s[k1 + j];
			ans += StrToInt(s1) + StrToInt(s2);
			if (StrToInt(s1) == 1)
				--ans;
			if (add1)
				++ans;
		}
		printf("Case #%d: %lld\n", t, ans);
	}

	my_return(0);
}