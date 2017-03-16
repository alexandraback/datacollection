#include <cstdio>
#include <cstring>

int R, C, M, N;
char s[100][100];

int len[100], e;

bool dfs( int m, int a )
{
	if( a == 0 )
		return 1;

	for( int i = m; i > 1; --i )
	{
		if( e == 0 )
		{
			if( a - 2*i >= 0 && e+2 <= R )
			{
				len[e++] = i;
				len[e++] = i;
				if( dfs(i, a-2*i) )	return 1;
				e -= 2;
			}
		}
		else
		{
			if( a - i >= 0 && e+1 <= R )
			{
				len[e++] = i;
				if( dfs(i, a-i) )	return 1;
				e--;
			}
		}
	}

	return 0;
}

bool solve()
{
	if( N == 1 )
	{
		s[0][0] = 'c';
		return 1;
	}

	if( R == 1 )
	{
		for( int i = 0; i < N; ++i )
			s[0][i] = '.';
		s[0][0] = 'c';
		return 1;
	}

	if( C == 1 )
	{
		for( int i = 0; i < N; ++i )
			s[i][0] = '.';
		s[0][0] = 'c';
		return 1;
	}

	e = 0;
	if( dfs(C, N) )
	{
		for( int i = 0; i < e; ++i )
			for( int j = 0; j < len[i]; ++j )
				s[i][j] = '.';
		s[0][0] = 'c';
		return 1;
	}
	else
		return 0;
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cases = 1;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%d %d %d", &R, &C, &M);
	
		N = R*C-M;
		for( int i = 0; i < R; ++i )
		{
			for( int j = 0; j < C; ++j )
				s[i][j] = '*';
			s[i][C] = 0;
		}
		
		printf("Case #%d:\n", cases++);
		if( solve() )
		{
			for( int i = 0; i < R; ++i )
				printf("%s\n", s[i]);
		}
		else
		{
			puts("Impossible");
			//printf("%d %d %d\n", R, C, M);
		}
	}

	return 0;
}
