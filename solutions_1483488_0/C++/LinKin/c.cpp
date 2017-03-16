#include<stdio.h>
#include<string.h>

#define MAX 2000007

long W[77];
long Digit[MAX+7];
long A,B;
long Visit[MAX+7];

int main( void )
{
	long i,j,Icase,k = 0;
	
	freopen("Cin.txt","r",stdin );
	freopen("Cout.txt","w",stdout );
	
	W[0] = 1;
	for( i=1;i<=8;i++ ){
		W[i] = W[i-1]*10;
	}
	for( i=1;i<=MAX;i++ ){
		Digit[i] = Digit[i/10] + 1;
	}
	
	scanf("%ld",&Icase );
	while( Icase-- ){
		scanf("%ld%ld",&A,&B );
		long long Ans = 0;
		memset( Visit,0,sizeof(Visit));
		for( i=A;i<=B;i++ ){
			long D = Digit[i];
			long v = i;
			for( j=1;j<D;j++ ){
				v = (v%W[D-1])*10 + (v/W[D-1]);
				if( Digit[v]!=D || v<A || v>=i ) continue;
				if( Visit[v]!=i ){
					Ans++;
					Visit[v] = i;
				}
			}
		}
		printf("Case #%ld: %I64d\n",++k,Ans );
	}
	
	//scanf("%*ld");
	
	return 0;
}
	
