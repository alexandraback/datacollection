#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MaxN= 111, inf= ~0u>>1;
int T, N, S, P, a[MaxN], opt[MaxN][MaxN];
int main(){
	scanf("%d", &T);
	for(int t= 1;t<= T;++ t){
		memset(opt, 0xff, sizeof opt);
		**opt= 0;
		scanf("%d%d%d", &N, &S, &P);
		for(int i= 1;i<= N;++ i)
			scanf("%d", a+i);
		for(int i= 1;i<= N;++ i)
			for(int j= 0;j<= min(i, S);++ j)
				opt[i][j]= max(
					opt[i-1][j] + (max(0, 3*P-2)<=a[i]),
					j ? opt[i-1][j-1] + (max(2, 3*P-4)<=a[i]) : -inf
				);
		printf("Case #%d: %d\n", t, opt[N][S]);
	}
	return 0;
}

