#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())

#define K 100

char key[K+10], target[K+10];
double ans;
char t[K+10];
int k, l, s;
int cnt[K+10];
int totCnt, maxCnt;

bool check(int k){
	rep(i, l) if (t[k+i] != target[i])
		return false;
	return true;
}

void dfs(int d){
	if (d == s){
		totCnt++;
		int tmp = 0;
		rep(i, s) if (check(i))
			tmp++;
		maxCnt = max(maxCnt, tmp);	
		cnt[tmp] ++;
		return;
	}
	rep(i, k){
	   t[d] = key[i];
	   dfs(d+1);
	}
}

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d%d%d", &k, &l, &s);
		scanf("%s%s", key, target);

		memset(cnt, 0, sizeof(cnt));
		maxCnt = totCnt = 0;

		dfs(0);	


		ans = 0;
		rep(i, maxCnt) ans+=(maxCnt - i)*((double)cnt[i]/totCnt);
		printf("Case #%d: %.10lf\n", te, ans);
	}
	return 0;
}

