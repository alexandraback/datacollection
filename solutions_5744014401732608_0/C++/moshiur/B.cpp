#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int INT(){int x;scanf("%d",&x);return x;}

#define CLR(A,X) memset((A),(X),sizeof((A))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)

int B;
LL M;

int main() {
	int T=INT();
	REP(t,1,T) {
		B=INT();
		cin>>M;
		
		printf("Case #%d:", t);
		if ((1LL << (B-2)) < M) {
			puts(" IMPOSSIBLE");
		} else {
			puts(" POSSIBLE");
			int ans[55][55];

			FOR(i,B)FOR(j,B) ans[i][j]=int(i>0 && i<j);
			LL pwr[55];
			pwr[B-1] = 0;
			pwr[B-2] = 1;
			for (int b = B-3; b >= 1; --b) pwr[b] = 2LL * pwr[b+1];
			FOR(j,B) {
				if (j > 0 && ((M-1)&pwr[j]) > 0) {
					ans[0][j] = 1;
				}
			}
			ans[0][B-1] = 1;

			FOR(i,B){
				FOR(j,B) printf("%d", ans[i][j]); puts("");
			}
		}
	}
	return 0;
}
