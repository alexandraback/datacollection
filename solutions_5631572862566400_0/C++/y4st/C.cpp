#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

long T = 0;

// 1 2 3   4 5 6 7 8 9 10
// 7 8 10 10 9 2 9 6 3 3
// 

array< bool, 1000 > seen;

int N;

int cycleLength( vector<int>& v, int i )
{
	cerr << "cycle " << i;
	std::vector<int> c;
	c.push_back( i );


	for( auto& b : seen )
		b=false;
	int l=1;
	seen[i] = true;
	int j=v[i];
	while( ! seen[j] )
	{
		c.push_back(j);
		seen[j] = true;
		cerr << ' ' << j; 
		j = v[j];
		++l;
	}
	if( j == i)
	{

	}
	else if( c.size() >=2 && j == c[ c.size() - 2 ] )
	{
		//reverse friends
		bool found;
		do
		{
			found = false;
			for( int i = 1 ; i <= N ; ++i )
			{
				if( !seen[i] && v[i] == c.back() )
				{
					seen[i] = true;
					cerr << ' ' << i;
					c.push_back( i );
					found = true;
					l+=1;
					break;
				}
			}
		}while(found);
	}
	else
		l=0;
	cerr << endl;
	return l;
}

void solve()
{
	cin >> N;
	vector<int> v;
	v.push_back(0); // offset
	for( int i = 0 ; i < N ; ++i )
	{
		int f;
		cin >> f;
		v.push_back(f);
	}
	int r=0;
	for( int i = 1 ; i <= N ; ++i )
	{
		int l = cycleLength( v, i );
		if(l > r)
			r=l;
	}
	cout << r;
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
