#include <stdio.h>
typedef long long ll;
int main(){
	ll T,i,j,k,t,A,N,m[1000];
	scanf("%lld",&T);
	for(i=1;i<=T;i++){
		scanf("%lld%lld",&A,&N);
		printf("Case #%lld: ",i);
		for(j=0;j<N;j++){
			scanf("%lld",&m[j]);
			t=m[j];
			k=j;
			while(k>0&&(m[k-1]>t)){
				m[k]=m[k-1];
				m[--k]=t;
			}
		}
	 	ll g,t,v;
		g=N;t=0;
		if(A==1){printf("%lld\n",g);continue;}
		for(j=0;j<N;j++){
			//printf("\tj%lldm%lldA%lldt%lldg%lld\n",j,m[j],A,t,g);
			while(A<=m[j]){
				v=t+(N-j);
				if(v<g)g=v;
				A+=(A-1);t++;
			}
			A+=m[j];
		}
		if(t<g)g=t;
		printf("%lld\n",g);
	}
	return 0;
}
