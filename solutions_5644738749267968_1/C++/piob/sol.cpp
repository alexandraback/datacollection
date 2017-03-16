#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

typedef long double K;

int n;
K P[1010];
K Q[1010];

bool test(int k){
	int i = k;
	int j = 0;
	while(i < n) if(P[i] < Q[j]) return 0; else ++i, ++j;
	return 1;
}

int main(){
	int zz; scanf("%d", &zz);
	FWD(z,1,zz+1){
		scanf("%d", &n);
		FWD(i,0,n)
			scanf("%Lf", &P[i]);
		FWD(i,0,n)
			scanf("%Lf", &Q[i]);
		printf("Case #%d: ", z);
		sort(P, P+n);
		sort(Q, Q+n);
		int c = 0, j;
		while(!test(c)) ++c;
		printf("%d ", n-c);
		c = 0;
		j = 0;
		FWD(i,0,n){
			while(j < n && P[i] > Q[j]) ++j;
			if(j == n)
				++c;
			else
				++j;
		}
		printf("%d\n", c);
	}
	return 0;
}
