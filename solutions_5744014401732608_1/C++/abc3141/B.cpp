#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int T;
int B;
ll M;
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d%lld",&B,&M);
		ll X=1;
		for(int i=0;i<B-2;i++){
			X*=2;
		}
		if(M>X){
			printf("Case #%d: IMPOSSIBLE\n",cas);
			continue;
		}
		else if(M==X){
			printf("Case #%d: POSSIBLE\n",cas);
			for(int i=0;i<B;i++){
				for(int j=0;j<B;j++){
					if(i>=j)printf("0");
					else printf("1");
				}
				printf("\n");
			}
		}
		else{
			printf("Case #%d: POSSIBLE\n",cas);
			for(int i=0;i<B;i++){
				for(int j=0;j<B;j++){
					if(i!=B-1&&j!=B-1){
						if(i>=j)printf("0");
						else printf("1");
					}
					else if(i==B-1){
						printf("0");
					}
					else{
						if(i==0)printf("0");
						else if((M>>(i-1))&1)printf("1");
						else printf("0");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
