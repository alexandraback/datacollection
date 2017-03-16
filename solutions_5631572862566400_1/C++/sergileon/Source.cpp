#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;
int a[1111];
vector<int> p[1111];
int used[1111];
int Time = 11;
int go(int v, int s, int cnt) {
	if (used[v] == Time) {
		return 0;
	}
	used[v] = Time;
	if (v == s) {
		return cnt;
	}
	go(a[v], s, cnt + 1);
}
int go2(int v, int nv) {
	int res = 0;
	for (int i = 0; i < p[v].size(); i++) {
		if (p[v][i] == nv)
			continue;
		res = max(res, 1 + go2(p[v][i], - 1));
	}
	return res;
}
int main()
{
	freopen("input.in","r",stdin); 
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d",&t);
	int numberTest = 1;
	while (t--) {
		for (int i = 0; i < 1111; i++) {
			p[i].clear();
		}
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
			p[a[i]].push_back(i);
		}
		int answ = -1;
		int answ2 = 0;
		for (int i = 0; i < n; i++) {
			Time++;
			answ = max(go(a[i], i, 1),answ);
			if (a[a[i]] == i) {
				answ2 += 1 + go2(i,a[i]);
			}
		}
		printf("Case #%d: %d\n",numberTest++,max(answ,answ2));
	}
	return 0;
}