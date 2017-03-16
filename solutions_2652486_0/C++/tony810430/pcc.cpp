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

int T,R,N,M,K,V;
int v[10];

void go()
{
	for( int i = 2; i <= 5; i++ ){
		for( int j = i; j <= 5; j++ ){
			for( int k = j; k <= 5; k++ ){
				int x;
				for( x = 0; x < K; x++ )
					if( (i*j*k)%v[x] != 0 )	break;
				if( x == K ){
					printf("%d%d%d\n",i,j,k);
					return ;
				}
			}
		}
	}
}

int main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("pc.out","w",stdout);



	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		printf("Case #%d:\n",cas);
		scanf(" %d %d %d %d",&R,&N,&M,&K);
		while(R--){
			for( int i = 0; i < K; i++ )
				scanf(" %d",&v[i]);
			go();
		}

	}

	return 0;
}
