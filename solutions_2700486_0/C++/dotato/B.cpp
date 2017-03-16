#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

double ncr[710][710];

int main(){

	int test,c=1,i,j,x,y,n,level;
	int need[10005];
	double ans;
	
	need[0]=1;
	for( i=1 ; i<=10000 ; i++ ) need[i]=need[i-1]+(i<<2)+1;
	
	ncr[1][1]=0.5;
	for( i=2 ; i<710 ; i++ ){
		ncr[i][1]=ncr[i-1][1]*(double)i/2.0/(i-1);
		for( j=2 ; j<=i ; j++ ){
			ncr[i][j] = ncr[i][j-1]*(double)(i-j+1)/(double)(j);
		}
	}
	for( i=2 ; i<710 ; i++ ){
		for( j=i-1 ; j>0 ; j-- )
			ncr[i][j]+=ncr[i][j+1];	
	}
	
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %.6lf\n",c++,ans) ){
		scanf("%d%d%d",&n,&x,&y);
		level = abs(x)+abs(y);
		if( !n ) ans=0.0;
		else if( !level ) ans=1.0;
		else if( level&1 ) ans=0.0;
		else{
			level>>=1;
			if( n>need[level] ) ans=1.0;
			else if( n<=need[level-1] ) ans=0.0;
			else{
				y++;
				n-=need[level-1];
				level<<=1;
			
				// y=block height needed, n=remaining block, level=max height-1
				if( y>level ){
					if( n<(level<<1)+1 ) ans=0.0;
					else ans=1.0;	
				}
				else if( n>=level+y ) ans=1.0;
				else if( n<y ) ans=0.0;
				else{
					ans = ncr[n][y];
				}
			}			
		}
	}

	return 0;
}

