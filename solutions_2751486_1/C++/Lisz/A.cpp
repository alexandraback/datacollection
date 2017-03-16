#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[1000006];
__int64 ans ;
int main(){
	int cas , casn = 1 ;
	freopen("A-large(2).in","rt",stdin);
	freopen("out.out","wt",stdout);
	scanf("%d",&cas);
	while( cas-- ){
		int L = 0 ,limit;
		scanf("%s%d",str,&limit);
		int len = strlen(str);
		ans = 0 ;
		int tt = 0 ;
		for( int i=0;i<len;i++ ){
			if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' )tt = 0 ;
			else tt ++ ;
			if( tt >= limit ){
				ans += ((__int64)i-limit+1-L+1)*(len-i);
				L = i - limit + 2 ;
			}
		}
		printf("Case #%d: %I64d\n",casn ++ , ans );
	}
	return 0;
}