#include <cstdio>
#include <vector>

using namespace std;

#define MAX 1005

vector<int> g[MAX];
int p[MAX], q[MAX], cnt[MAX];

void run( int C )
{
	int N;
	scanf( "%d", &N );
	for( int i = 0; i < N; i++ ) g[i].clear();
	for( int i = 0; i < N; i++ )
	{
		int parent;
		scanf( "%d", &p[i] );
		for( int j = 0; j < p[i]; j++ )
		{
			scanf( "%d", &parent );
			g[parent-1].push_back(i);
		}
	}

	int qptr = 0;
	for( int i = 0; i < N; i++ ) if( !p[i] ) q[qptr++] = i;
	for( int i = 0; i < N; i++ )
	{
		int x = q[i];
		for( int j = 0; j < g[x].size(); j++ )
		{
			int y = g[x][j];
			p[y]--;
			if( !p[y] ) q[qptr++] = y;
		}
	}

	bool ok = true;
	for( int i = 0; i < N; i++ )
	{
		for( int j = i; j < N; j++ ) cnt[q[j]] = 0;
		cnt[q[i]] = 1;
		for( int j = i; j < N; j++ )
		{
			int x = q[j];
			for( int k = 0; k < g[x].size(); k++ )
			{
				int y = g[x][k];
				cnt[y] += cnt[x];
				if( cnt[y] >= 2 )
				{
					ok = false;
					goto done;
				}
			}
		}
	}

	done:
	printf( "Case #%d: %s\n", C, ok ? "No" : "Yes" );
}

int main()
{
	int T;
	scanf( "%d", &T );
	for( int i = 1; i <= T; i++ ) run( i );
}
