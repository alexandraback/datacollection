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

const long long MOD = 1000003;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-6;
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

int multi[8][8] = {{0, 1, 2, 3, 4, 5, 6, 7},
				   {1, 4, 3, 6, 5, 0, 7, 2},
				   {2, 7, 4, 1, 6, 3, 0, 5},
				   {3, 2, 5, 4, 7, 6, 1, 0},
				   {4, 5, 6, 7, 0, 1, 2, 3},
				   {5, 0, 7, 2, 1, 4, 3, 6},
				   {6, 3, 0, 5, 2, 7, 4, 1},
				   {7, 6, 1, 0, 3, 2, 5, 4}};

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	#endif

	int CASE;
	cin >> CASE;
	for (int T = 1; T <= CASE; ++T)
	{
		int l, x;
		string s;
		cin >> l >> x >> s;
		int res = 0, cur = 0;
		bool has1 = false, has3 = false;
		for (int i = 0; i < l*x; ++i)
		{
			if (s[i % l] == 'i')
				cur = 1;
			else if (s[i % l] == 'j')
				cur = 2;
			else
				cur = 3;
			res = multi[res][cur];
			if (!has1 && res == 1)
				has1 = true;
			if (has1 && res == 3)
				has3 = true;
		}
		if (has1 && has3 && res == 4)
			cout << "Case #" << T << ": YES\n";
		else
			cout << "Case #" << T << ": NO\n";
	}

	my_return(0);
}
