#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T, N, S, p;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas){
		scanf("%d %d %d", &N, &S, &p);
		int good = 0, pending = 0, ti;
		int gain[3][2] = {
				{0, 1}, {1, 1}, {1, 2}
		};
		for(int i = 0; i < N; ++i){
			scanf("%d", &ti);
			int gain0 = ti > 0 ? gain[ti % 3][0] : 0;
			int gain1 = ti > 0 ? gain[ti % 3][1] : 0;
			if(ti / 3 + gain0 >= p)
				++good;
			else if(ti / 3 + gain1 >= p)
				++pending;
		}
		int res = good + min(S, pending);
		printf("Case #%d: %d\n", cas, res);
	}

	return 0;
}
