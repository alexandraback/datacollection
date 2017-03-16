#include<cstdio>
#define MAX 205
#define eps 1e-7

int tab[MAX],t,n,i,j;
double S;

int main(){
    scanf("%d",&t);
    for(i=0; i<t; ++i){
	scanf("%d",&n);
	printf("Case #%d: ",i+1);
	S=0;
	
	for(j=0; j<n; ++j){
	    scanf("%d",&tab[j]);
	    S+=tab[j];
	}
	
	
	for(j=0; j<n; ++j){
	    double l=0,r=100;
	    while(l+eps<r){
		double ok=true;
		double s=(l+r)/2;
		double sum=0;
		double pom = tab[j] + (double)(s*S)/100;
		for(int k=0; k<n; ++k)
		    if(k==j) continue;
		    else{
			if(tab[k]>pom) continue;
			else
			    sum+=(pom-tab[k])/S;
		    }
		if(sum+s/100<1) l=s; else r=s;
	    }
	    printf("%lf ",(l+r)/2);
	}
	
	printf("\n");
    }
    return 0;
}