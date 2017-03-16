#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int a[ 1004 ];
map< int , int > H;
int n;

void print( int mask ){
    int sp = true;
    for(int i = 0; i < n; i++ ){
    	if(mask & ( 1<< i ) ){
	        if( sp ) sp = false;
    	    else  putchar(' ');
    	    printf("%d" , a[ i ] );
	    }
	}
	putchar(10);
}

int main(){
    int runs;
	scanf("%d",&runs);
    for( int r = 1 ; r <= runs; r++ ){
        printf("Case #%d:\n" , r );
		scanf("%d",&n);
		H.clear();
		for( int i = 0; i < n; i++)  cin >> a[i];
		for( int i = 0; i < ( 1 << n ) ; i++ ) {
			int tmp  = 0;
			for( int j = 0; j < n; j++)  if ( i & ( 1 << j ) ) tmp += a[j];
			if ( H.count( tmp ) ){
				print( i ) ;
				print( H[tmp] ) ;
				goto hell;
			}//marca
			H[tmp] = i;
		}
		printf("Impossible\n");
		hell: ;
	}
    return 0;
}
