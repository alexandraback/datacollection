#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>

#define ll long long
#define ull unsigned ll
#define FOR( i, a, b ) for( i = a; i <= b; i++ )
#define REP( i, n ) for( i = 0; i < n ; i++ )
#define pb push_back
#define VI vector<int>
#define VVI vector< vector<int> >
#define VS vector<string>
#define VVS vector< vector<string> >

using namespace std;

int cal( int, int, int );

int main()
{
	int t;
	int a;
	int b;
	int i;
	int j;
	int ans;
	fstream fout( "Qual_C_small.out", ios::out );
	fstream fin( "C-small-attempt0.in", ios::in );
	fin >> t;
	FOR( i, 1, t ) {
		ans = 0;
		fin >> a >> b;
		FOR( j, a, b ) {
			ans = ans + cal( a, b, j );
		}
		fout << "Case #" << i << ": " << ans << "\n";
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}

int cal( int a, int b, int n )
{
	int x;
	int i = 0;
	if( n <=10 || n==100 || n ==1000) return 0;
	if( n <= 100 ) {
		x = (n%10)*10 + n/10;
		if( x > n && x <= b ) return 1;
	}
	x = (n%100)*10 + n/100;
	if( x > n && x <= b ) i++;
	x = (n%10)*100 + n/10;
	if( x > n && x <=b ) i++;
	return i;
}
