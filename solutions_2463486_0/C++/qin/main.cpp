#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;


vector<__int64> v;
int nv;

__int64 invert( __int64 v )
{
	__int64 vv = 0;
	while( v > 0 )
	{
		vv = vv * 10 + (v%10);
		v /= 10;
	}

	return vv;
}

int numd( int p )
{
	int num = 1;
	while( p> 0 )
	{
		num *= 10;
		p /= 10;
	}

	return num;
}

void preprocess()
{
	for( int i = 0; i <= 10; ++i )
		for( int j = 0; j <= 999; ++j )
		{
			__int64 nowv = 0;
			if( i == 10 )
				nowv = (__int64) j * numd(j) + invert(j);
			else
				nowv = (__int64) (j * 10 + i) * numd(j) + invert(j);
			nowv = nowv * nowv;
			if( invert(nowv) == nowv && nowv > 0 )
				v.push_back(nowv);
		}

	nv = (int) v.size();
	sort( v.begin(), v.end() );

	//for( int i = 0; i < (int) v.size(); ++i )
	//	printf( "%I64d ", v[i] );
}

int run_one_case()
{
	__int64 s, t;
	scanf( "%I64d %I64d", &s, &t );
	int cnt = 0;

	for( int i = 0; i < nv; ++i )
		if( v[i] >= s && v[i] <= t )
			++cnt;

	return cnt;
}

int main()
{
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );

	preprocess();

	int n_case;
	scanf( "%d", &n_case );

	for( int i = 0; i < n_case; ++i )
	{
		int result = run_one_case();
		printf( "Case #%d: %d\n", i+1, result );
	}
	return 0;
}