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

int get_reverse(int x) {
	int ans = 0;
	while (x) {
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}

void solve() {
	int N, i;
	vector <int> values;
	ReadNo(N);
	
	values.resize(N + 1, MOD1);
	values[1] = 1;
	for (i = 1; i < N; ++i) {
		if (values[i] != 0) {
			values[i + 1] = min(values[i + 1], values[i] + 1);
			int rev = get_reverse(i);
			if (rev <= N) {
				values[rev] = min(values[rev], values[i] + 1);
			}
		}
	}
	cout << values[N];
	ENTER
}

int main(int nargs, char **args){
	
	if (nargs > 1) {
		freopen(args[1], "r", stdin);
	}
	else {
		freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/input", "r", stdin);
		freopen("/Users/duxar/Workplace/Xcode Projects/Selectie/Selectie/output.txt", "w", stdout);
	}
	
	int T;
	ReadNo(T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	

	
	return 0;
}


