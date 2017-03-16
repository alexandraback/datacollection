#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
 
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define inf (1<<29)
#define eps (1e-9)
#define pb push_back
#define all(a) a.begin(),a.end()
#define myabs(a) ((a)<0?(-(a)):(a))
#define i64 __int64
typedef pair<int,int> pii;
#define MX 2000001
vector<int> a[ MX ];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int tc, cs = 1;
	cin >> tc;
	while( tc -- )
	{
	
		vector<int> v, ans1, ans2;	
		int N, p, i, k, paisi = 0, j;
		
		for(i = 0; i < MX ; i ++ ) a[ i ].clear();
		cin >> N;
		for(i = 0; i < N ; i ++ ) cin >> p, v.push_back( p );
		
		for(i = 0; i < (1 << N ) ; i ++ )
		{
			int sm = 0;
			for(j = 0; j < N ; j ++ )
				if( (1 << j ) & i )
					sm += v[ j ];
			if( a[ sm ].size() )
			{
				for(k = 0; k < a[ sm ].size(); k ++ )
					if( (a[ sm ][ k ] & i) == 0 )
					{
						for(j = 0; j < N ; j ++ )
							if( (1 << j ) & i )
								ans1.push_back( v[ j ] );
						
						for(j = 0; j < N ; j ++ )
							if( (1 << j ) & a[ sm ][ k ] )
								ans2.push_back( v[ j ] );
						paisi = 1;
						break;
					}
			}
			if( paisi ) break;
			a[ sm ].push_back( i );
		}
		cout <<"Case #"<<cs++<<":"<<endl;
		if( paisi )
		{
			cout << ans1[ 0 ];
			for( i = 1; i < ans1.size() ; i ++ )  cout << " " << ans1[ i ];
			cout << endl;

			
			cout << ans2[ 0 ];
			for( i = 1; i < ans2.size() ; i ++ )  cout << " " << ans2[ i ];
			cout << endl;
		}
		else cout <<"Impossible"<<endl;
	}
	return 0;
}