#include <cmath>
#include <queue>
#include <deque>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000 + 10;

int ret, N;
int a[MAX_N];
int b[MAX_N];
int sta[MAX_N];

void inputData()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++ i)
		scanf("%d%d", &a[i], &b[i]);
}

void calcAns()
{
	int best, re, re2;
	int sum = 0, flag, get;
	ret = 0;
	memset(sta, 0, sizeof sta);
	
	for( ; sum < 2 * N; ) {
		flag = false;
		get = false;
		re2 = 0;
		best = 0;
		for(int i = 1; i <= N; ++ i) {
			if (sta[i] == 0) {
				if (sum >= b[i]) {
					flag = true;
					ret += 1;
					sum += 2;
					sta[i] = 2;
					get = true;
					break;
				} else if (sum >= a[i]) {
					flag = true;
					if (best < b[i]) {
						best = b[i];
						re = i;
					}
				}
			} else if (sta[i] == 1) {
				if (sum >= b[i]) {
					re2 = i;
					flag = true;
				}
			}
		}
		if (! flag) {
			puts("Too Bad");
			return;
		}
		if (get) continue;
		if (re2 != 0) {
			sta[re2] = 2;
			sum += 1;
			ret += 1;
			continue;
		}
		sum += 1;
		ret += 1;
		sta[re] = 1;
	}
	printf("%d\n", ret);
}

void solve(int t)
{
	printf("Case #%d: ", t);
	inputData();
	calcAns();
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T; 
	scanf("%d", &T);
	for(int i = 1; i <= T; ++ i) 
		solve(i);
	return 0;
}