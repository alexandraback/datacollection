
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#include <time.h>
#include <fstream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void main()
{
	int t;
	ifstream in;
	in.open( "C-small-attempt0.in", ios_base::in );
	in>>t;
	for( int i = 1; i <= t; ++i )
	{
		int n, m, k;
		int ans = 1;
		in>>n>>m>>k;
		ofstream out;
		out.open( "C.txt", ios_base::app );
		out<<"Case #"<<i<<": ";
		ans = k - k / 3 + !( !( k % 3 ) ) - 1;
		out<<ans<<endl;
	}
	in.close();
	///system( "pause" );
}
