#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

int compare( const void* a, const void* b);
int compare_reverse( const void* a, const void* b);

// use:
//    qsort(p,D,sizeof(int),compare_reverse);

int T;
long long C,D,V;
long long coins[1000];
long long coins2[1000];
long x[3010],y[3010];
long double tang[3010];

int compare_long_double( const void* a, const void* b)
{
     long double int_a = * ( (long double*) a );
     long double int_b = * ( (long double*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}



int solve(){
	long long i,k,j, count,res=0,res2=0;
	coins[D]=V+1;
	D++;
	long long DD=D;
	for(k=0;k<DD;k++){
		for(i=coins[k]-1;i>=(k>0?coins[k-1]:0);i--){
			count=i;
			//printf("%d : ",i);
			for(j=D-1;j>=0;j--){
				if(count>=coins[j]){
					count-=coins[j];
					//printf("%d-",coins[j]);
				}
				if(count==0)	break;
			}
			if(count!=0){
				res++;  D++; coins[D-1]=i; 
				//printf("*%d*");
				qsort(coins,D,sizeof(long long),compare);}
			//printf("\n\r");
		}
	}
	D=DD-1;
	for(i=1;i<=V;i++){
		count=i;
		//printf("%d : ",i);
		for(j=D-1;j>=0;j--){
			if(count>=coins2[j]){
				count-=coins2[j];
				//printf("%d-",coins2[j]);
			}
			if(count==0)	break;
		}
		if(count!=0){
			res2++;  D++; coins2[D-1]=i; 
			//printf("*%d*");
			qsort(coins2,D,sizeof(long long),compare);}
		//printf("\n\r");
	}
	
	return (res<res2?res:res2);
}



int main(){
    int i,res,j,k,m,n,c;
    scanf("%d",&T);

    for(i=1;i<=T;i++){
        scanf("%d %d %d",&C,&D,&V);
		for(j=0;j<D;j++){	scanf("%d",&c); coins[j]=c; coins2[j]=c;}
        printf("Case #%d: %d\n",i,solve());
      
       
        //...
    }
    return 0;
}

//####################################################################################################
int compare( const void* a, const void* b)
{
     long long int_a = * ( (long long*) a );
     long long int_b = * ( (long long*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int compare_reverse( const void* a, const void* b)
{
     long long int_a = * ( (long long*) a );
     long long int_b = * ( (long long*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return 1;
     else return -1;
}



