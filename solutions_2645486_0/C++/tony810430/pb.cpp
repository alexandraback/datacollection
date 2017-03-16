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


int v[20];
int T,R,E,N;
int ans;

void dfs(int lv,int e,int sum)
{
	if( lv == N ){
		ans = max(ans,sum);
	}else{
		for( int i = 0; i <= e; i++ ){
			dfs(lv+1,min(E,e-i+R),sum+i*v[lv]);
		}
	}
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("pb.out","w",stdout);


	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %d %d %d",&E,&R,&N);
		for( int i = 0; i < N; i++ )
			scanf(" %d",&v[i]);
		ans = 0;
		dfs(0,E,0);
		printf("Case #%d: %d\n",cas,ans);
	}


	return 0;
}
