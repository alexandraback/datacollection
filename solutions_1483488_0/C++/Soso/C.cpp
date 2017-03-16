#include<cstdio>
int a,b,T,k,r,q,kk,ac,kkk,x=0,d[50],ok;
int main(){
	scanf("%d",&T);
	for (int o=1; o<=T; o++){
		scanf("%d%d",&a,&b);
		kk=1;
		while (kk<=a) kk*=10;
		kk/=10; kkk=kk;
		ac=0;
		for (int i=a; i<=b; i++){
			k=10; kk=kkk; x=0;
			while (i/k){
				  r=i%k; q=i/k;
				  if (r*kk+q>i&&r*kk+q<=b){
			   	  	 ok=1;
					 for (int j=1; j<=x; j++){
						 if (r*kk+q==d[j]) ok=0;
					 }
					 if (ok){
					 	d[++x]=r*kk+q;
			   	  	 	++ac;
					 }
		 		  }
				  k*=10; kk/=10;
			}
		}
		printf("Case #%d: %d\n",o,ac);
	}
	return 0;
}
