#include <cstdio>
#include <cstdlib>
#include <algorithm>


using namespace std;

int gcd( int x ,int y ) {
	if( x > y )  swap( x , y ) ;
	if( x == 0 )	return y ;
	return gcd( y%x , x ) ;	
}

int main(){
	
	int T ; 
	scanf("%d",&T ) ; 
	
	int CASE = 0 ; 
	while( T-- ){
		int a ,b ; 
		scanf("%d/%d",&a,&b); 
		
		int g = gcd ( a , b );
		a /= g ; 
		b /= g ; 
		
		bool ok = 1 ;
		int tmp = b ;  
		while( tmp > 1 ){
			if( tmp % 2 ){
				ok = 0 ; 
				break; 	
			}
			tmp /= 2 ; 
		}
		
		if( !ok ) printf("Case #%d: impossible\n",++CASE); 
		else{	
			int ans = 1 ;
			
			for( ; (double)a/(double)b < 0.5 ; b = b/2 , ans++ ); 
			printf("Case #%d: %d\n",++CASE,ans); 
		}
	}	
	
	
	return 0; 
} 
