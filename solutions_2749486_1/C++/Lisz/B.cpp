#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("B-large.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int cas , casn = 1 ;
	scanf("%d",&cas);
	while(cas--){
		int x,y ;
		scanf("%d%d",&x,&y);
		x = abs(x) , y = abs(y);
		printf("Case #%d: ",casn++);
		int cnt = 0 ;
		int step = 1 ;
		int Min = min( x, y ) , Max = max( x , y );
		while( cnt < Min ){
			cnt += step ;
			step ++ ;
		}
		cnt -= Min ;
		while( cnt < Max ){
			cnt += step ;
			step ++ ;
		}
		int ans = min( (step-1)+(cnt-Max)*2,(Max-(cnt-(step-1)))*2+step-2);
		printf("%d\n",ans);
	}
	return 0;
}