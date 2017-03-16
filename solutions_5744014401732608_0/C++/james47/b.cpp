/*************************************************************************
    > File Name: b.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  8 18:13:56 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int T, cas = 0;
int b; ll m;
int ans[60][60];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %lld", &b, &m);
		int mi = 0; ll f = 1;
		while(f < m){
			mi ++;
			f <<= 1;
		}
		printf("Case #%d: ", ++cas);
		if (mi > b-2){
			puts("IMPOSSIBLE");
			continue;
		}
		else{
			puts("POSSIBLE");
		}
		if ((1ll << (b-2)) == m){
			for (int i = 0; i < b; i++)
				for (int j = i+1; j < b; j++)
					ans[i][j] = 1;
		}
		else{
			memset(ans, 0, sizeof(ans));
			for (int i = 0; i <= mi; i++)
				for (int j = i+1; j <= mi; j++){
					ans[i][j] = 1;
				}
			for (int i = mi; i >= 0; i--){
				ll cnt = 0;
				if (i == 0) cnt = 1;
				else cnt = 1ll << (i-1);
				if (m >= cnt){
					ans[i][b-1] = 1;
					m -= cnt;
				}
			}
		}

		for (int i = 0; i < b; i++){
			for (int j = 0; j < b; j++)
				printf("%d", ans[i][j]);
			puts("");
		}
	}
	return 0;
}
