#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		int K,C,S;
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d:",cs);
		if(S*C<K) puts(" IMPOSSIBLE");
		else{
			for(int j=0;j<K;j+=C){
				long long r=0;
				for(int k=j;k<K&&k<j+C;k++){
					r=r*K+k;
				}
				printf(" %lld",r+1);
			}
			puts("");
		}
	}
	return 0;
}