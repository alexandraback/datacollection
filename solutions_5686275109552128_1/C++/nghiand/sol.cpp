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

int calc(int i, int j){
	if (j >= i) return 0;
	return i / j + (i % j != 0 ? 1 : 0) - 1;
}

void process(int test){
	int n;
	cin >> n;
	vi a(n);
	int m = 0;
	REP(i, n){
		cin >> a[i];
		m = max(m, a[i]);
	}

	int res = oo;
	FOR(i, 1, m){
		int cnt = i;
		REP(j, n){
			cnt += calc(a[j], i);
		}
		res = min(res, cnt);
	}

	cout << "Case #" << test << ": " << res << endl;
	
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