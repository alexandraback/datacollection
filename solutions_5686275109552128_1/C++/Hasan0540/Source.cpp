#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, v[1000];
bool check(int t, int s){
	int rem = t - s;
	for (int i = 0; i < n; ++i){
		s -= (v[i] - 1) / rem;
		if (s < 0)
			return false;
	}
	return true;
}
bool check(int t){
	for (int s = 0; s < t;++s)
	if (check(t, s))
		return true;
	return false;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; ++T){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		int l = 1, m, r = 1000, res = 1000;
		while (l <= r){
			m = (l + r) / 2;
			if (check(m)){
				res = m;
				r = m - 1;
			}else
				l = m + 1;
		}
		printf("%d\n", res);
	}
	return 0;
}