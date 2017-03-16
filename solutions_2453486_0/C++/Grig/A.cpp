#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int four = 4;
vector<string> v( four );

char X = 'X', Y = 'O', T = 'T';
map<char, int> mp;

bool check( char player )
{
	return mp[ player ] == 4 || mp[ player ] == 3 && mp[ T ] == 1;
}

string solve()
{
	for( string& s : v )
		cin >> s;

	int i, j;
	char c;

	string xwin = "X won", ywin = "O won", draw = "Draw", undef = "Game has not completed";

	for( i = 0; i < four; ++i )
	{
		mp.clear();
		for( j = 0; j < four; ++j )
			mp[ v[ i ][ j ]]++;
		if( check( X ))
			return xwin;
		if( check( Y ))
			return ywin;
	}

	for( j = 0; j < four; ++j )
	{
		mp.clear();
		for( i = 0; i < four; ++i )
			mp[ v[ i ][ j ]]++;
		if( check( X ))
			return xwin;
		if( check( Y ))
			return ywin;
	}

	mp.clear();
	for( i = 0; i < four; ++i )
		mp[ v[ i ][ i ]]++;
	if( check( X ))
		return xwin;
	if( check( Y ))
		return ywin;

	mp.clear();
	for( i = 0; i < four; ++i )
		mp[ v[ i ][ four - i - 1 ]]++;
	if( check( X ))
		return xwin;
	if( check( Y ))
		return ywin;

	for( i = 0; i < four; ++i )
		for( j = 0; j < four; ++j )
			if( v[ i ][ j ] == '.' )
				return undef;
	return draw;
}

int main()
{
	freopen( "A-small.in", "r", stdin );
	freopen( "A-small.out", "w", stdout );
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}