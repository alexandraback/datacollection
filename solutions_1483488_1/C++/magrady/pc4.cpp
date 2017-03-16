#include<stdio.h>
int u[10000001];
int s[101],S;
main(){
	int i,j,k;
	int T,TN=0;
	int a,b,c,d,e;
	int cnt;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d",&a,&b);
		cnt=0;
		for(i=a;i<=b;i++){
			for(S=0,j=1,k=10;;j++,k*=10)if(i%k==i)break;
			for(c=j,d=k/10,j=1,k=10;j<c;j++,k*=10,d/=10)
				if((e=(i%k*d+i/k))<=b&&e>=a&&e>i)
					if(!u[e])u[e]=1,s[S++]=e,cnt++;
			while(S--)u[s[S]]=0;
		}
		printf("Case #%d: %d\n",T,cnt);	
	}
}
