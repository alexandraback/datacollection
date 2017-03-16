#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int J, P, S, K;
struct outfit
{
	public:
	int j, p, s;
	outfit(){}
	outfit(int jj, int pp, int ss) { j=jj; p=pp; s=ss; }
};

int C = 0; // comb
outfit O[64];
int cur[64];
int ans[64];

int ans_len;

void gen()
{
	C = 0;
	for (int j=1;j<=J;++j) {
		for (int p=1;p<=P;++p) {
			for (int s=1;s<=S;++s) {
				O[C++] = outfit(j,p,s);
			}
		}
	}
}

int check2(outfit o, int s, int len)
{
	int cnt = 0;
//	printf("check2 o:(%d, %d, %d)\n", o.j, o.p, o.s);
	
	for (int j=s;j<len;++j) {
		int match = 0;
		if (o.j == O[cur[j]].j) match ++;
		if (o.p == O[cur[j]].p) match ++;
		if (o.s == O[cur[j]].s) match ++;
		
//		printf("check2 -> (%d, %d, %d), match: %d\n", O[cur[j]].j, O[cur[j]].p, O[cur[j]].s, match);
		
		if (match >= 2) {
			cnt ++;
		}
	}
	return cnt;
}

bool check(int len) {
	for (int i=0;i<len;++i) {
		outfit t;
		t = O[cur[i]]; t.j = -1;
		if (check2(t, i+1, len) >= K) return false;
		t = O[cur[i]]; t.p = -1;
		if (check2(t, i+1, len) >= K) return false;
		t = O[cur[i]]; t.s = -1;
		if (check2(t, i+1, len) >= K) return false;
	}
	return true;
}

void dfs(int x, int len)
{
	if (len + C - x < ans_len) return;
	
	if (x >= C) {
		if (len > ans_len) {
			for (int i=0;i<len;++i) {
				ans[i] = cur[i];
			}
			ans_len = len;
		}
		return;
	}
	
	cur[len] = x;
	if (check(len+1)) {
		dfs(x+1, len+1);
	}
	dfs(x+1, len);
}


int solv()
{
	gen();
	ans_len = 0;
	dfs(0, 0);
	return ans_len;
}

void dump()
{
	for (int i=0;i<ans_len;++i) {
		printf("%d %d %d\n", O[ans[i]].j, O[ans[i]].p, O[ans[i]].s);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase) {
		cin >> J >> P >> S >> K;
		printf("Case #%d: %d\n", nCase, solv());
		dump();
		
		
	}
	return 0;
}
