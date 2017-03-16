#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int k,c,s;
		scanf("%d %d %d",&k,&c,&s);
		if((k+c-1)/c>s){
			printf("Case #%d: IMPOSSIBLE\n",T);
		}else{
			printf("Case #%d:",T);
			for(int i=0; i<k; ){
				long long tmp=0;
				for(int j=0; j<c; j++,i++){
					if(i>=k) i=k-1;
					tmp*=k;
					tmp+=i;
				}
				printf(" %I64d",tmp+1);
			}
			puts("");
		}
	}
	return 0;
}
