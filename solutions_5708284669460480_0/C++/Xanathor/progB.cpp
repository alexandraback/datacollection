#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

int compare( const void* a, const void* b);
int compare_reverse( const void* a, const void* b);

// use:
//    qsort(p,D,sizeof(int),compare_reverse);

int T;
int K,L,S;
unsigned char kb[1000];
 double probk[1000];
unsigned char target[1000];



int compare_long_double( const void* a, const void* b)
{
     long double int_a = * ( (long double*) a );
     long double int_b = * ( (long double*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}



double solve(){
	double res;
	int i,j;
	int found=0;
	for(i=1;i<L;i++){
		if(target[i]==target[0]){
			for(j=i+1;j<L;j++){
				if(target[j]!=target[j-i])	break;
			}
			if(j==L){
				found=i+1;
				break;
			}
		}
	}
	int len=0;
	if(found==0){
		len=S/L;
	}else{
		len=S/found;
	}
	//printf("%d:",len);
	double prob=1.0;
	int k=0;
	for(i=0;i<L;i++){
		prob*=probk[target[i]];
	}
	//printf("%f:",prob);
	res=(prob==0.0?0.0:len*(1.0-prob));
	return res;

}



int main(){
    int i,res,j,k,m,n;
    scanf("%d",&T);

    for(i=1;i<=T;i++){
        scanf("%d %d %d",&K,&L,&S);
		for(j=0;j<1000;j++){
			kb[j]=0;
			probk[j]=0.0;
			target[j]=0;
		}
		scanf("%s",&kb);
/*		for(j=0;j<K;j++){
			printf("%c",kb[j]);
		}
*/		for(j=0;j<K;j++){
			probk[kb[j]]++;
		}
		for(j=0;j<1000;j++){
			probk[j]/=( double)K;
		}
		scanf("%s",&target);
        // ...
        printf("Case #%d: %f\r\n",i,solve());
        
		
        
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



