#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

int cnt[256];

inline void dec(const string &s) {
	for(char c : s) {
		cnt[c]--;
	}
}

string solve(const string &s) {
	memset(cnt, 0, sizeof(cnt));
	for(char c : s) {
		cnt[c]++;
	}
	string res;
	while(cnt['Z']) {
		res += '0';
		dec("ZERO");
	}
	while(cnt['W']) {
		res += '2';
		dec("TWO");
	}
	while(cnt['U']) {
		res += '4';
		dec("FOUR");
	}
	while(cnt['O']) {
		cerr << cnt['O'];
		res += '1';
		dec("ONE");
	}
	while(cnt['R']) {
		res += '3';
		dec("THREE");
	}
	while(cnt['F']) {
		res += '5';
		dec("FIVE");
	} 
	while(cnt['V']) {
		res += '7';
		dec("SEVEN");
	}
	while(cnt['S']) {
		res += '6';
		dec("SIX");
	}
	while(cnt['N']) {
		res += '9';
		dec("NINE");
	}
	while(cnt['E']) {
		res += '8';
		dec("EIGHT");
	}
	sort(res.begin(), res.end());
	return res;
}


int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	//string tst = "ZEROONETWOTHREEFOURFIVESIXSEVENEIGHTNINE";
	cin.ignore();
	for(int test = 1; test <= T; ++test) {
		string s;
		getline(cin, s);
		cout << "Case #" << test << ": " << solve(s) << endl;		
	}
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}