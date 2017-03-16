#include <cstdio>
#include <cstring>
using namespace std;
int T,K,C,S,j;
long long rv;
int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d",&K,&C,&S);
		printf("Case #%d:",t);
		if (C*S<K){
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i=C;i<K+C;i+=C){
			if (i<=K)
				j=i;
			else
				j=K;
			rv=0;
			for (int d=0;d<C && d<K;d++){
				rv = rv*K + j-d-1;
			}
			printf(" %lld",rv+1);
		}
		printf("\n");
	}	
}
/*
C = 2 K = 3
XYZ -> XYXYYYZZZ
i = 2
j = 2
-> 0 1 => 1*(K^(C-1)) + 0*(K^(C-2)) = 1*K + 0*1 = 3 (4)
i = 4
j = 3
-> 1 2 => 2*K + 1*1 = 7 (8)
i=6>=5

C = 3 K =2
XY -> XXYY -> XXXXYYYY
i = 3
j = 2
-> 0 1 = 0 0 1  => 0*K^2 + 0*K + 1 = 1 (2)
i = 6>=5

C = 3 K = 3
XYZ -> XXXYYYZZZ -> XXXXXXXXXYYYYYYYYYZZZZZZZZZ
i = 3
j = 3
-> 012 => 2*K^2 + 1*K + 0 = 21 (22)
i=6 >= 6
012 345 
*/
