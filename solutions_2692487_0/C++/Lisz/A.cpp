#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define INF 0x3fffffff
#define MAXN 1000005
__int64 a[MAXN];
int main(){
	freopen("A-small-attempt4.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int cas , casn = 1 ;
	scanf("%d",&cas);
	__int64 n , o ;
	while(cas--){
		__int64 Min = INF ;
		scanf("%I64d%I64d",&n,&o);
		for( int i=1;i<=o;i++ ){
			scanf("%I64d",&a[i]);
		}
		sort(a+1,a+1+o);
		__int64 num = 0 ;
		for(int i=1;i<=o;i++){
			if( a[i]<n ){
				n+=a[i];
			}else{
				if( n == 1 ){
					
					Min = min( Min , num + o -i +1 );num = INF ;
					break;
				}
				Min = min( Min , num + o - i + 1 ) ;
				n+=n-1;
				num ++ ;
				i--;
			}
		}
		printf("Case #%d: %I64d\n",casn++,min(num,Min));
	}
	return 0;
}