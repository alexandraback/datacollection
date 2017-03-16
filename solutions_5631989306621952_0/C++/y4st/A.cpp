#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <deque>

using namespace std;

long T = 0;

/*
CAB

CA

JAM
MJA */

void solve()
{
	string s;
	cin >> s;
	deque<char> r;
	for( auto c : s )
	{
		if( r.empty() || c < r.front() )
			r.push_back(c);
		else
			r.push_front(c);
	}
	for( auto c : r )
		cout << c;
	
}

int main(int argc, char * argv[] )
{
	cin >> T;
	for( auto t=0; t<T; ++t )
	{
		cout << "Case #" << t+1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
