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
#define N 10000
#define X 26

char s[N+10];
int c[N];


char digit[10][20] = {"ZERO", "ONE", "TWO", 
	"THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> ans;


bool dfs(int i, int n){

	if (i>9) return false;
	if (n==0){
		for (int j=0; j<ans.size(); ++j)
			printf("%d", ans[j]);
		puts("");
		return true;
	}


	int len = strlen(digit[i]);
	bool ok = true;
	for (int j=0; j<len; ++j)
		if (c[digit[i][j]]==0){
			ok = false;
			break;
		}

	if (ok){
		for (int j=0; j<len; ++j)
			--c[digit[i][j]];
		ans.push_back(i);

		if (dfs(i, n-len)) return true;

		ans.pop_back();
		for (int j=0; j<len; ++j)
			++c[digit[i][j]];
	}

	if (dfs(i+1, n)) return true;
	return false;
}

void solve(){
	ans.clear();
	memset(c, 0, sizeof(c));
	int n = strlen(s);
	for (int i=0; i<n; ++i)
		++ c[s[i]];
	dfs(0, n);
}

int main(){
	int ts;
	scanf("%d\n", &ts);
	for (int te=1; te<=ts; ++te){
		scanf("%s", s);
		printf("Case #%d: ", te);
		solve();
	}
	return 0;
}
