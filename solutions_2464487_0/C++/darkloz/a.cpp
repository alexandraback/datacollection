#include<cstdio>
#include<cmath>
#define LL long long 
#define D long double
#define eps 1e-6
#define sqr(x) ((x)*(x))
int cmp(D a, D b){
	if( fabs(a-b) < eps ) return 0;
	if( a< b )return -1;
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		LL r,p;
		scanf("%lld%lld",&r,&p);
		LL lo=0,hi=10e9;

		while(lo != hi){
			LL m = (lo+hi+1)/2;
			D M = m;  
			D e =  M*(2.L*r-1.L)+2.L*M*M ;
			LL qe = m*(2*r-1)+2*m*m;
			if( cmp(e,p)> 0 ){
				hi=m-1;
			}else{
				if( qe > p )
					hi=m-1;
				else
					lo=m;
			}
			
			
		}
		
		printf("Case #%d: %lld\n",i, lo ) ;
	}
	return 0;
}
