#include<stdio.h>

int T,m[200][200],N,M;
bool yn,tag[200][200];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("pb.out","w",stdout);

	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %d %d\n",&N,&M);
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < M; j++ ){
				scanf(" %d",&m[i][j]);
				tag[i][j] = false;
			}
		}

		for( int v = 100; v >= 1; v-- ){
			for( int i = 0; i < N; i++ ){
				yn = true;
				for( int j = 0; j < M; j++ )
					if( m[i][j] > v )	yn = false;
				for( int j = 0; yn && j < M; j++ )
					if( m[i][j] == v )	tag[i][j] = true;
			}
			for( int j = 0; j < M; j++ ){
				yn = true;
				for( int i = 0; i < N; i++ )
					if( m[i][j] > v )	yn = false;
				for( int i = 0; yn && i < N; i++ )
					if( m[i][j] == v )	tag[i][j] = true;
			}
		}

		yn = true;
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ )
				if(!tag[i][j])	yn = false;

		if(yn)	printf("Case #%d: YES\n",cas);
		else	printf("Case #%d: NO\n",cas);
	}

	return 0;
}
