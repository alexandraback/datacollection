#include <stdio.h>

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=0;casenum<testcases;casenum++){
		printf("Case #%d: ",casenum+1);
		long long k,c,s;
		scanf("%lld%lld%lld",&k,&c,&s);
		if(c*s<k)puts("IMPOSSIBLE");
		else{
			int cnt=0;
			for(int i=0;;i++){
				long long sum=0;
				for(int j=0;j<c;j++){
					sum=sum*k+((cnt+j)%k);
				}
				if(i>0)printf(" ");
				printf("%lld",sum+1);
				cnt+=c;
				if(cnt>=k)break;
			}
			puts("");
		}
	}
}