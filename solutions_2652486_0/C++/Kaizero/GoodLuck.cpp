#include<stdio.h>
int main()
{
	int T,R,N,M,K,i,j,w[10],l,m,k;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d%d%d",&T,&R,&N,&M,&K);
	printf("Case #1:\n");
	for(i=1;i<=R;i++){
		for(j=1;j<=K;j++)scanf("%d",&w[j]);
		for(j=2;j<=5;j++){
			for(k=2;k<=5;k++){
				for(l=2;l<=5;l++){
					for(m=1;m<=K;m++){
						if(w[m]!=1 && w[m]!=k && w[m]!=j && w[m]!=l && w[m]!=k*j && w[m]!=k*l && w[m]!=j*l &&w[m]!=j*k*l)break;
					}
					if(m==K+1){
						printf("%d%d%d\n",j,k,l);
						break;
					}
				}
				if(l!=6)break;
			}
			if(k!=6)break;
		}
		if(j==6)printf("111\n");
	}
	return 0;
}