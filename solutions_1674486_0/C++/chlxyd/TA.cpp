#include<stdio.h>
#include<string.h>
int T,n;
int m[1100];
int v[1100][1100];
int s[1100];
bool bj[1100];
bool dfs( int i ){
	bj[i] = true;
	for ( int j = 1 ;  j <= m[i] ; j ++){
		int k = v[i][j];
		if ( bj[k] )
			return true;
		if ( dfs(k) )
			return true;
	}
	return false;
}
bool solve(){
	for ( int i = 1 ; i <= n ; i ++)
		if ( s[i] ){
			memset(bj,false,sizeof(bj));
			if (dfs(i))
				return true;
		}
	return false;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	int ca=0;
	while ( T -- ){
		memset(bj,false,sizeof(bj));
		memset(m,0,sizeof(m));
		memset(s,true,sizeof(s));
		scanf("%d" , &n );
		for ( int i = 1 ; i <= n ; i ++){
			scanf("%d", &m[i] );
			for ( int j = 1 ; j <= m[i] ; j ++){
				scanf("%d",&v[i][j]);
				s[v[i][j]] = false ;
			}
		}
		printf("Case #%d: %s\n",++ca,solve()?"Yes":"No");
	}
}