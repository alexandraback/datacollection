#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <thread>
#include <mutex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// globals
typedef pair<int, int> result_type;
const bool use_multi = true;
//


template<class T>
void read( T& container )
{
	for( typename T::value_type& x : container )
		cin >> x;
}

template<class T>
void print( T& container, const string& separator = " " )
{
	for( typename T::value_type& x : container )
		cout << x << separator;
}

void open_files( const char* in, const char* out )
{
	freopen( in, "r", stdin );
	freopen( out, "w", stdout );
}

struct solver
{
   int n;
   vector<double> v[ 2 ];
	// solution code here
	solver() {}

	void read()
	{
      cin >> n;
      v[ 0 ].resize( n );
      v[ 1 ].resize( n );
      int i, t;
      for( t = 0; t < 2; ++t )
      {
         for( i = 0; i < n; ++i )
            cin >> v[ t ][ i ];
         sort( v[ t ].begin(), v[ t ].end());
      }
	}

	result_type solve()
	{
      result_type res( 0, 0 );
      int i = 0, j = 0, t;
      for( i = 0; i < n; ++i )
      {
         for( ; j < n && v[ 1 ][ j ] < v[ 0 ][ i ]; ++j );
         if( j == n )
            ++res.second;
         else
            ++j;
      }
      j = n - 1, t = 0;
      for( i = 0; i < n; ++i )
      {
         if( v[ 0 ][ i ] > v[ 1 ][ t ] )
         {
            ++res.first;
            ++t;
         }
         else if( v[ 0 ][ i ] < v[ 1 ][ j ] )
            --j;
      }

		return res;
	}
};


mutex result_locker;
vector<result_type> results;
vector<thread> threads;
vector<solver> solvers; // change this for result type

void run( int test_num )
{
	result_type res = solvers[ test_num ].solve();
	result_locker.lock();
	results[ test_num ] = res;
	result_locker.unlock();
}

void print_result( int test_num )
{
	cout << "Case #" << test_num + 1 << ": "; // default
	// print code here
   cout << results[ test_num ].first << ' ' << results[ test_num ].second << endl;
}

void process() 
{ 
   open_files( "d-small-1.in", "d-small-1.out" );

	// preparations
	int test_count;
	cin >> test_count;
	threads.resize( test_count );
	results.resize( test_count );
	solvers.resize( test_count );

	// input
	for( int i = 0; i < test_count; ++i )
		solvers[ i ].read();

	// detach threads if necessary
	if( use_multi )
	{
		for( int i = 0; i < test_count; ++i )
			threads[ i ] = thread( run, i );
		for( int i = 0; i < test_count; ++i )
			threads[ i ].join();
	}
	else
	{
		for( int i = 0; i < test_count; ++i )
			run( i );
	}
	for( int i = 0; i < test_count; ++i )
		print_result( i );
}

int main() { process(); return 0; }