#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v[100];
int zip[100], id[100], b[100];
pair<int, int> a[100];

bool chk( int* p, int N )
{
	int st[100], t = 0;
	st[++t] = p[0];
	for( int i = 1; i < N; ++i )
	{
		int x = p[i];
		do
		{
			int y = st[t];
			bool ok = 0;
			for( int j = 0; !ok && j < v[y].size(); ++j )	if( v[y][j] == x )
				ok = 1;
			if( ok )
			{
				st[++t] = x;
				break;
			}
		} while(--t);
		if( t == 0 )	return 0;
	}
	return 1;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int T, cases = 1;
	int N, M, x, y;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%d %d", &N, &M);
		for( int i = 1; i <= N; ++i )
		{
			v[i].clear();
			scanf("%d", &zip[i]);
			id[i] = zip[i];
		}
		sort(zip+1, zip+N+1);
		for( int i = 1; i <= N; ++i )
		{
			for( int j = 1; j <= N; ++j )	if( id[i] == zip[j] )
				id[i] = j;
		}

		while( M-- )
		{
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}

		for( int i = 0; i < N; ++i )	a[i] = make_pair(id[i+1], i+1);
		sort(a, a+N);
		do
		{
			for( int i = 0; i < N; ++i )	b[i] = a[i].second;
			if( chk(b, N) )
			{
				printf("Case #%d: ", cases++);
				for( int i = 0; i < N; ++i )	printf("%d", zip[a[i].first]);
				puts("");
				break;
			}
		} while( next_permutation(a, a+N) );
	}

	return 0;
}