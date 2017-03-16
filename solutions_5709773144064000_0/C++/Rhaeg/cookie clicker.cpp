#include <cstdio>
#define SORT(A) sort(A.begin(),A.end())
#define fori(l,n) for(int l=1;l<=n;l++)
int main() {
	int I,IT,nada,ban;
	//int p,q,ii,jj,res,;
	double C,F,X;
//	int A[100][100],B[100],C[100];
    freopen("B-small-attempt0.in","r",stdin);
    freopen("cookie.out","w",stdout);
    
    double ta,t, v,t1,t2;
    I=1;
    scanf("%d", &IT); 
    
    while(I<=IT){
                 
       v=2;ta=0;
       scanf("%lf %lf %lf", &C, &F, &X); 
       
       if(C<X){
          ban=1;
          while(ban==1){
             t=C/v;
             t1=(X-C)/v;
             t2=X/(v+F);
             if(t2<t1){
                v=v+F;
             ta=ta+t;
             }
             else{
               ban=0;
               ta=ta+t+t1;
            }
          }
          
       }
       else{
          ta=X/v;
       }
       
       
      //RESPUESTA
    
          printf("Case #%d: %.7lf\n",I,ta);          
      
       I++;
    }

	return 0;
}

