#include <stdio.h>


int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int n,cnt=100;
		int bit=0;
		scanf("%d",&n);
		int step=n;
		if(n==0){
			printf("Case #%d: INSOMNIA\n",T);
			continue;
		}
		while(cnt--){
			int tmp=n;
			while(tmp){
				bit|=(1<<(tmp%10));
				tmp/=10;
			}
			if(bit==0x3ff)
				break;
			n+=step;
		}
		printf("Case #%d: %d\n",T,n);
	}
	return 0;
}
