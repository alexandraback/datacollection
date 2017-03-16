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
	freopen("A-small-attempt0.in","r",stdin);
	freopen("pa.out","w",stdout);

	int T,r,t,k;


	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %d %d",&r,&t);
		k = 1;
		while(true){
			if( k*(2*k-1)+2*k*r > t )	break;
			k++;
		}
		printf("Case #%d: %d\n",cas,k-1);

	}


	return 0;
}
