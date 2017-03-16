#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#define LL long long
using namespace std;
int T;
LL n,k;
int main(){
	scanf("%d",&T);
	for (int I=1;I<=T;I++){
		scanf("%lld%lld",&n,&k);
		if (k>1ll<<(n-2)){
			printf("Case #%d: IMPOSSIBLE\n",I);
		}else{
			printf("Case #%d: POSSIBLE\n",I);
			printf("0");
			if (k==(1ll<<(n-2)))
				for (int i=1;i<n;i++) printf("1");
			else{
				for (int i=n-3;i>=0;i--)
					printf("%d",!(!(k&(1ll<<i))));
				printf("0");
			}
			printf("\n");
			for (int i=2;i<n;i++){
				for (int j=1;j<=i;j++) printf("0");
				for (int j=i+1;j<=n;j++) printf("1");
				printf("\n");
			}
			for (int i=1;i<=n;i++) printf("0");
			printf("\n");
		}
	}
    return 0;
}

