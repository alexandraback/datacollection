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
typedef string result_type;
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
	// solution code here
	solver() {}

   int n, m;
   vector<string> v;
   
   char g[ 10 ][ 10 ];

	void read()
	{
      cin >> n >> m;
      v.resize( n );
      for( auto& s : v )
         cin >> s;

      int x, y, i;

      memset( g, 0, sizeof( g ));

      for( i = 0; i < m; ++i )
      {
         cin >> x >> y;
         g[ x - 1 ][ y - 1 ] = g[ y - 1 ][ x - 1 ] = 1;
      }
	}

	result_type solve()
	{
      vector<int> perm;
      int i, j;
      for( i = 0; i < n; ++i )
         perm.push_back( i );

      vector<int> pv( n );
      string s, tmp;
      int t;
      do
      {
         t = 1;
         pv[ perm[ 0 ]] = -1;
         for( i = 1; i < n; ++i )
         {
            for( j = perm[ i - 1 ]; j != -1; j = pv[ j ] )
               if( g[ perm[ i ]][ j ] )
                  break;
            if( j < 0 )
               break;
            pv[ perm[ i ]] = j;
         }
         
         if( i == n )
         {
            tmp = "";
            for( j = 0; j < n; ++j )
               tmp += v[ perm[ j ]];
            if( s.empty())
               s = tmp;
            else
               s = min( s, tmp );
         }
      }
      while( next_permutation( perm.begin(), perm.end()));
		return s;
	}
};


mutex result_locker;
vector<result_type> results;
vector<thread> threads;
vector<solver> solvers;

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
   cout << results[ test_num ] << endl;
}

void process() 
{ 
   open_files( "c-small-0.in", "c-small-0.out" );
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