#include <stdio.h>
#define int long long

long long  t,k,c,s;

main(){
	scanf("%lld",&t);
	for(int tt=1;tt<=t;tt++){
		printf("Case #%lld: ",tt);
		scanf("%lld %lld %lld",&k,&c,&s);
		if(s*c<k) printf("IMPOSSIBLE\n");
		else{
			for(long long i=1;i<=k/c;i++){
				long long at=1;
				for(long long j=c*(i-1)+1;j<=c*i;j++){
					//printf("%d ",at);
					at=k*(at-1)+j;
				}
				printf("%lld ",at);
				//printf("\n");
			}
			if(k%c!=0){
				long long at=1;
				for(long long j=(k/c)*c+1;j<=k;j++){
				//	printf("%lld ",at);
					at=k*(at-1)+j;
				}
				for(long long i=c-(k%c) ;i>0;i--){
				//	printf("%lld ",at);
					at=k*(at-1)+1;
				}
				printf("%lld ",at);
			}
			printf("\n");
		}
	}
	return 0;
}
