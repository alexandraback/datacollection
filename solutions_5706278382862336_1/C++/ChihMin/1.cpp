#include <cstdio>
#include <cstdlib>
#include <algorithm>


using namespace std;

long long int gcd( long long int x , long long int y ) {
	if( x > y )  swap( x , y ) ;
	if( x == 0 )	return y ;
	return gcd( y%x , x ) ;	
}

int main(){
	
	int T ; 
	scanf("%d",&T ) ; 
	
	int CASE = 0 ; 
	while( T-- ){
		long long int a ,b ; 
		scanf("%lld/%lld",&a,&b); 
		
		long long int g = gcd ( a , b );
		a /= g ; 
		b /= g ; 
		
		bool ok = 1 ;
		long long int tmp = b ;  
		while( tmp > 1 ){
			if( tmp % 2 ){
				ok = 0 ; 
				break; 	
			}
			tmp /= 2 ; 
		}
		
		if( !ok ) printf("Case #%d: impossible\n",++CASE); 
		else{	
			long long int ans = 1 ;
			
			for( ; (double)a/(double)b < 0.5 ; b = b/2 , ans++ ); 
			printf("Case #%d: %lld\n",++CASE,ans); 
		}
	}	
	
	
	return 0; 
} 
