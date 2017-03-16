#ifndef _HEAD_H_
#define _HEAD_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())
#define SQR(x) ((x)*(x))

using namespace std;

template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }
#endif
#define N 20

char s[N+10], t[N+10];
char x[N+10], y[N+10];
char u[N+10], v[N+10];
int ans;

int get(char *s, int n){
	int ret = 0;
	for (int i=0; i<n; ++i)
		ret = ret*10 + s[i] - '0';
	return ret;
}

void dfs(int i, int n){
	if (i == 2*n){
		int diff = get(x, n) - get(y, n);
		if (abs(diff) < ans){
			ans = abs(diff);
			memcpy(u, x, sizeof(x));
			memcpy(v, y, sizeof(y));
		}
		return;
	}


	char *a, *b;
	int p = i;
	if (i<n){
		a = s;
		b = x;
	} else {
		a = t;
		b = y;
		p -= n;
	}

	if (a[p] == '?'){
		for (int j = 0; j<=9; ++j){
			b[p]  = '0' + j;
			dfs(i+1, n);
		}
	}
	else 
		dfs(i+1, n);

}

void solve(){
	int n = strlen(s);
	ans = INT_MAX;
	memcpy(x, s, sizeof(s));
	memcpy(y, t, sizeof(t));
	dfs(0, n);
	printf("%s %s\n", u, v);
}

int main(){
	int ts;

	scanf("%d\n", &ts);
	for (int te=1; te<=ts; ++te){
		scanf("%s%s", s, t);
		printf("Case #%d: ", te);
		solve();
	}
	return 0;
}
