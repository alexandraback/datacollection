#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#endif

using namespace std;

	// lambda : [] (int a, int b) -> bool { body return }
	// string r_str = R"(raw string)"

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define BASE 73
#define NMAX 10000
#define NMAX2 20001
#define MOD1 1000000007
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define CRLINE Duxar(__LINE__);
#define SHOWME(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define ENTER putchar('\n');

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};

int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Duxar(int _this_line) {
#ifndef ONLINE_JUDGE
	printf("\n . . . . . . . . . . . . . Passed line - %d\n", _this_line);
#endif
}

template <class T>
void ReadNo(T &_value) {
	T _sign = 1;
	char ch;
	_value = 0;
	while(!isdigit(ch = getchar())) {
		(ch == '-') && (_sign = -1);
	}
	do {
		_value = _value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	_value *= _sign;
}

template <class T>
void AddNr(T &a, T b) {
	a = a + b;
	while (a >= MOD1) {
		a -= MOD1;
	}
	while (a < 0) {
		a += MOD1;
	}
}

int V, ans;


void next_poss(int step, bitset<31> vals, bitset<31> init, int val) {
	int i, j;
	
	if (step > 7) {
		return;
	}
	
	for (i = 1; i <= V; ++i) {
		if (vals[i] == 0) {
//			cout << vals.to_string() << '\n';
			break;
		}
	}
	
	if (i == V + 1) {
		ans = min(step, ans);
		return;
	}
	
	for (i = val + 1; i <= V; ++i) {
		if (init[i] == 0) {
			bitset<31> vals2(vals);
			for (j = V; j; --j) {
				if (vals2[j] && j + i <= V) {
					vals2[j + i] = 1;
				}
			}
			vals2[i] = 1;
			init[i] = 1;
			next_poss(step + 1, vals2, init, i);
			init[i] = 0;
		}
	}

}

void solve() {
	int C, D, x, i, j;
	ReadNo(C); ReadNo(D); ReadNo(V);
	ans = MOD1;
	bitset<31> init, vals;
	
	for (i = 1; i <= D; ++i) {
		ReadNo(x);
		for (j = V; j; --j) {
			if (vals[j] && j + x <= V) {
				vals[j + x] = 1;
			}
		}
		init[x] = 1;
		vals[x] = 1;
	}
	
	next_poss(0, vals, init, 0);
	
	cout << ans << '\n';
	
}

int main(int nargs, char **args){
	
	if (nargs > 1) {
		freopen(args[1], "r", stdin);
	}
	else {
		freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
	}
	
	int T;
	ReadNo(T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	
	
	
	return 0;
}


