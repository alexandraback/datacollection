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

char st[1000010];
int pos[1000010];
int L;
int n;

bool is_yn( char ch )
{
	return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
}

__int64 solve_it()
{
	pos[L] = -1;
	int cnt = 0;
	__int64 rst = 0;
	for( int i = L-1; i >= 0; --i )
	{
		if( is_yn(st[i]) )
		{
			cnt = 0;
			pos[i] = pos[i+1];
		}
		else
		{
			++cnt;
			if( cnt >= n )
				pos[i] = i;
			else
				pos[i] = pos[i+1];
		}
		if( pos[i] != -1 )
			rst += L-(pos[i]+n)+1;
	}
	return rst;
}

int main()
{
	freopen( "A-large.in", "r", stdin );
	freopen( "out.txt", "w", stdout );

	int T;

	scanf( "%d", &T );
	for( int i = 1; i <= T; ++i )
	{
		scanf( "%s %d", &st, &n );
		L = strlen( st );
		__int64 rst = solve_it();
		printf( "Case #%d: %I64d\n", i, rst ); 
	}

	return 0;
}