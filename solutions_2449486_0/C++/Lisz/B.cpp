#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int mp[105][105];
bool ok[105][105];

bool judge( ){
	for( int i=1;i<=n;i++ )
		for( int j=1;j<=m;j++ )
			if( !ok[i][j] )
				return false;
	return true ;
}

int main(){
	freopen("B-small-attempt1.in","rt",stdin);
	freopen("B-small-attempt1.out","wt",stdout);
	int cas , casn = 1 ;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		memset(ok,false,sizeof(ok));
		for( int i=1;i<=n;i++ )
			for( int j=1;j<=m;j++ )
				scanf("%d",&mp[i][j]);
		for( int i=1;i<=n;i++ ){
			int Max = - 1;
			for( int j=1;j<=m;j++ )
				Max = max( Max , mp[i][j] );
			for( int j=1;j<=m;j++ )
				if( mp[i][j] == Max )
					ok[i][j]=true ;
		}
		for( int j=1;j<=m;j++ ){
			int Max = -1 ;
			for( int i=1;i<=n;i++ )
				Max = max( Max , mp[i][j] );
			for( int i=1;i<=n;i++ )
				if( mp[i][j] == Max )
					ok[i][j]=true ;
		}
		printf("Case #%d: ",casn++ );
		puts(judge()?"YES":"NO");
	}
	return 0;
}
