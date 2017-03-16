#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1010

using namespace std;

int T, Ans1, Ans2, N;
double xx[MaxN], yy[MaxN];
bool flag[MaxN];

int main() {
	int i, j, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		Ans1 = Ans2 = 0;
		scanf("%d", &N);
		for(i = 1; i <= N; ++i) cin >> xx[i];
		for(i = 1; i <= N; ++i) cin >> yy[i];
		sort(xx + 1, xx + N + 1);
		sort(yy + 1, yy + N + 1);
		memset(flag, 0, sizeof(flag));
		for(i = N; i; --i)
			for(j = N; j; --j)
				if((!flag[j]) && xx[i] > yy[j]) {
					flag[j] = 1; ++Ans1; break;
				}
		Ans2 = N;
		memset(flag, 0, sizeof(flag));
		for(i = 1; i <= N; ++i)
			for(j = 1; j <= N; ++j)
				if((!flag[j]) && xx[i] < yy[j]) {
					flag[j] = 1; --Ans2;break;
				}
		printf("Case #%d: %d %d\n", ++T0, Ans1, Ans2);
	}
	return 0;
}
