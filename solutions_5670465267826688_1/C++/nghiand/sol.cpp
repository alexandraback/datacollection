#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <time.h>
#pragma comment(linker, "/STACK:134217728")

#define LL long long
#define LD long double

#define REP(i,n) for (int i = 0; i < (n); i++)
#define REP2(i,n) for (int i = 0; i <= int(n); i++)
#define FOR(i,a,b) for (int i = int(a); i <= int(b); i++)
#define FORB(i,a,b) for (int i = int(a); i >= int(b); i--)

#define mp(u,v) make_pair(u, v)
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAXN 20
#define MAXT 3600
#define oo 1000000001
#define MODULE 1000000007

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

const int d[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int calc(int u, int v){
	int x = (u * v) < 0 ? -1 : 1;
	return x * d[abs(u) - 1][abs(v) - 1];
}

int num(char c){
	switch (c){
	case 'i': return 2;
	case 'j': return 3;
	case 'k': return 4;
	}
	return 1;
}

void process(int test){
	LL l, x;
	string s, str;
	cin >> l >> x;
	cin >> str;

	if (x <= 6){
		REP(i, x) s += str;

		l = s.length();

		vi a(l);
		a[0] = num(s[0]);

		int res = (a[0] == 2 ? 1 : 0);

		FOR(i, 1, l - 1){
			a[i] = calc(a[i - 1], num(s[i]));
			if (a[i] == 2 && res == 0) res = 1;
			if (a[i] == 4 && res == 1) res = 2;
		}
		if (a[l - 1] == -1 && res == 2) res = 3;

		cout << "Case #" << test << ": " << (res == 3 ? "YES" : "NO") << endl;
	}
	else{
		REP(i, 4) s += str;
		
		int k = ((LL)x * l - 1) % s.length();

		l = s.length();

		vi a(l);
		a[0] = num(s[0]);

		int res = 0;
		if (a[0] == 2) res = 1;
		if (a[0] == 4) res = 2;

		FOR(i, 1, l - 1){
			a[i] = calc(a[i - 1], num(s[i]));
			if (a[i] == 2) res |= 1;
			if (a[i] == 4) res |= 2;
		}

		cout << "Case #" << test << ": " << (res == 3 && a[k] == -1 ? "YES" : "NO") << endl;
	}
}

int main(){
	//make();
	freopen("in.txt", "rt", stdin);
	//freopen("in.txt", "rt", stdin);
	freopen("out", "wt", stdout);
	//START
	//ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	FOR(i, 1, test)
		process(i);
	//END
	return 0;
}

#endif