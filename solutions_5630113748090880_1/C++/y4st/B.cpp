#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <deque>

using namespace std;

long T = 0;
long N = 0;

void solve()
{
	cin >> N;
	array< int, 2500 > h;
	for( auto& s : h )
		s = 0;
	for( int i = 0 ; i < (2*N - 1) * N ; ++i )
	{
		int s;
		cin >> s;
		h[s]+=1;
	}
	vector<int> r;
	for( int i = 0 ; i < 2500 ; ++i )
		if( h[i] % 2 == 1 )
			r.push_back(i);
	sort( r.begin(), r.end() );
	for( auto s : r )
		cout << ' ' << s;
	
}

int main(int argc, char * argv[] )
{
	cin >> T;
	for( auto t=0; t<T; ++t )
	{
		cout << "Case #" << t+1 << ":";
		solve();
		cout << endl;
	}
	return 0;
}
