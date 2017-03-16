#include<stdio.h>

FILE *input=freopen("input5.txt","r",stdin);
FILE *output=freopen("output.txt","w",stdout);

int main(){
	int a,b,n,m,k;
	int t;
	int tc=1;
	int i;
	int maxi;

	scanf("%d",&t);
	for(;t>0;t--){
		printf("Case #%d: ",tc++);
		scanf("%d%d%d",&n,&m,&k);
		maxi=-1;
		if(n==2)
			maxi=k;
		if(m==2)
			maxi=k;
		if(k<=n||k<=m){
			maxi=k;
		}
		for(a=1;a<=n-1;a++){
			for(b=1;b<=m-1;b++){
				for(i=0;i<=4;i++){
					if(a*b+2*a+2*b+i==k){
						if(maxi==-1||maxi>2*a+2*b+i)
							maxi=2*a+2*b+i;
					}
				}

			}
		}
		printf("%d\n",maxi);

	}
	return 0;
}