#include <stdio.h>

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		long long n;
		scanf("%lld",&n);
		if(n==0)puts("INSOMNIA");
		else{
			int chk[10]={};
			int cnt=0;
			for(int i=1;;i++){
				long long m=n*i;
				for(;m>0;){
					long long d=m%10;
					if(chk[d]==0){chk[d]=1;cnt++;}
					m/=10;
				}
				if(cnt==10){printf("%lld\n",n*i);break;}
			}
		}
	}
}