#include <cstdio>

int i,j,k,t,T,d,p[1010],b[1000];

int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		for(i=0;i<1010;i++){
			p[i]=0;
			b[i]=0;
		}
		scanf("%d",&d);
		for(i=0;i<d;i++){
			scanf("%d",&j);
			p[j]++;
		}
		for(j=1000;p[j]==0;j--);
		for(i=j;i>1;i--){
			b[i]+=p[i]+b[i+1];
			p[i/2]+=p[i];
			p[(i+1)/2]+=p[i];
		}
		k=1000;
		for(i=j;i;i--){
			if(i+b[i+1]<k){
				k=i+b[i+1];
			}
		}
		printf("Case #%d: %d\n",t,k);
	}
	return 0;
}
