#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

int compare( const void* a, const void* b);
int compare_reverse( const void* a, const void* b);

// use:
//    qsort(p,D,sizeof(int),compare_reverse);

int T;
int R,C,W;
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
	if(C%W==0){
		return (C/W+W-1)+C/W*(R-1);
	}
	return C/W*(R-1)+C/W+W;
}



int main(void){
    int i,res,j,k,m,n;
    scanf("%d",&T);

    for(i=1;i<=T;i++){
        scanf("%d %d %d",&R,&C,&W);
        
        res=solve();
        printf("Case #%d: %d",i,res);
        
        //...
    }
    return 0;
}

//####################################################################################################
int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int compare_reverse( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return 1;
     else return -1;
}



