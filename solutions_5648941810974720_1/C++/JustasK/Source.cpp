#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:167772160000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional>
#include <climits>
#include <cstring>

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<long double,long double> pdd;
#define forn(N)          for(int i = 0; i<(int)N; i++)
#define fornj(N)         for(int j = 0; j<(int)N; j++)
#define fornk(N)         for(int k = 0; k<(int)N; k++)
#define forn1(N)          for(int i = 1; i<=(int)N; i++)
#define fornj1(N)         for(int j = 1; j<=(int)N; j++)
#define fornk1(N)         for(int k = 1; k<=(int)N; k++)
#define PI 3.1415926535897932384626433
#define v vector
#define ll long long
#define print(n) printf("%d ", (n));
#define printll(n) printf("%I64d", (n));
#define printline() printf("\n");
#define read(n) scanf("%d", &n);
#define read2(n, m) scanf("%d%d", &n, &m);
#define readll(n) scanf("%I64d", &n);
#define mp make_pair
using namespace std;

map<char, int>cnt;
void upd(string a, int b) {
	forn(a.length())cnt[a[i]] -= b;


}


int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(File".in", "r", stdin); freopen(File".out", "w", stdout);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int t; cin >> t;
	fornk1(t) {
		cnt.clear();
		int ans[10];
		forn(10)ans[i] = 0;
		string s; cin >> s;
		
		forn(s.length())cnt[s[i]]++;
		
		int x = cnt['G'];
		ans[8] += x;
		upd("EIGHT", x);
		x = cnt['X'];
		ans[6] += x;
		upd("SIX", x);


		x = cnt['H'];
		ans[3] += x;
		upd("THREE", x);

		x = cnt['W'];
		ans[2] += x;
		upd("TWO", x);

		x = cnt['Z'];
		ans[0] += x;
		upd("ZERO", x);

		x = cnt['R'];
		ans[4] += x;
		upd("FOUR", x);

		x = cnt['O'];
		ans[1] += x;
		upd("ONE", x);

		x = cnt['F'];
		ans[5] += x;
		upd("FIVE", x);

		x = cnt['V'];
		ans[7] += x;
		upd("SEVEN", x);

		x = cnt['E'];
		ans[9] += x;
		upd("NINE", x);

		for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second != 0)
				int asdf = 15;

		}

		cout << "Case #" << k << ": ";
		forn(10)fornj(ans[i])cout << i;
		cout << endl;


	}

	return 0;

}
