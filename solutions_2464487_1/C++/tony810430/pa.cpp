#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;



int main()
{
	freopen("A-large.in","r",stdin);
	freopen("pAAA.out","w",stdout);

	int T;
	long long r,t,k;


	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %I64d %I64d",&r,&t);
		k = 1LL;
		long long a=1,b=10000000000LL;
		int cnt = 500;
		while( b>=a+1 && cnt--){
			k = (a+b)/2;
			if( k*(2*k-1)+2*k*r > t )	b = k;
			else	a = k;
		}
		if( b*(2*b-1)+2*b*r <= t )
			printf("Case #%d: %I64d\n",cas,b);
		else
			printf("Case #%d: %I64d\n",cas,a);

	}


	return 0;
}
