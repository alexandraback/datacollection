#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
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
typedef double result_type;
const bool use_multi = false;
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
   double c, f, x;

	// solution code here
	solver() {}

	void read()
	{
      cin >> c >> f >> x;
	}

	result_type solve()
	{
      double rate = 2;
      double cur_time = 0;
      double to_spend = x / 2;
      double to_farm, next_spend;
      const double eps = 1e-14;
      while( 1 )
      {
         to_farm = c / rate;
         next_spend = x / ( rate + f );
         if( to_farm + next_spend < to_spend - eps )
         {
            cur_time += to_farm;
            rate += f;
            to_spend = next_spend;
         }
         else
            break;
      }
		return cur_time + to_spend;
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
   cout << fixed << setprecision( 7 ) << results[ test_num ] << endl;
}

void process() 
{ 
   open_files( "b-large.in", "b-large.out" );
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