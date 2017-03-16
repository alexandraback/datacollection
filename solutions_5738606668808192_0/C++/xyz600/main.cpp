#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli to_10( string num, lli base )
{
  lli ans = 0;
  for ( char ch : num )
  {
	ans = ans * base + (ch - '0');
  }
  return ans;
}

string from_10( lli num, lli base )
{
  stringstream ss;
  while ( num > 0 )
  {
	ss << (num % base);
	num /= base;
  }
  string ans = ss.str();
  reverse( ans.begin(), ans.end() );
  return ans;
}

string conv( string num, lli fb, lli ab )
{
  return from_10( to_10( num, fb), ab );
}

void prime( vector<lli> &ps, int N )
{
  ps.clear();
  vector<bool> is_prime( N + 1 );
  fill( is_prime.begin(), is_prime.end(), true );
  is_prime[ 0 ] = is_prime[ 1 ] = false;

  const int lim = sqrt( N );
  for( int i = 2; i <= lim; i++ )
  {
	if( is_prime[ i ] )
	{
	  for( int j = i * i; j <= N; j += i )
	  {
		is_prime[ j ] = false;
	  }
	}
  }
  for( int i = 0; i <= N; i++ )
  {
	if ( is_prime[ i ] )
	{
	  ps.push_back( i );
	}
  }
}

int get_divisor( const lli v, const vector<lli> &primes )
{
  const lli limit = sqrt( v );
  // if ( v == 205891132153789 ) cerr << limit << endl;
  for ( auto p : primes )
  {
	// if ( v == 205891132153789 ) cerr << v << ", " << p << ", " << ( v % p ) << endl;
	if ( v % p == 0 ) return p;
	if ( p > limit ) return -1;
  }
}

int main()
{
  // const int size = 6 - 2;
  const int size = 16 - 2;
  // const int size = 32 - 2;

  int T, N, J;
  cin >> T >> N >> J;
  
  cout << "Case #1:" << endl;

  vector<lli> primes;
  prime( primes, 100000000 ); // validate
  int counter = 0;
  for( int i = 0; i < (1 << size) && counter < J; i++ )
  {
	string input = from_10( (1 << (size + 1)) + (i << 1) + 1, 2 ); 	// validate

	vector<lli> base;
	for( int d = 2; d <= 10; d++ )
	{
	  lli v = get_divisor( to_10( input, d ), primes );
	  // if ( "1000000000100111" == input )
	  // {
	  // 	cerr << v << ", " << to_10( input, d ) << endl;
	  // }
	  if ( v != -1 )
	  {
		base.push_back( v );
	  }
	  else
	  {
		break;
	  }
	}
	if ( base.size() == 9 )
	{
	  counter++;
	  cout << input;
	  int d = 2;
	  for( auto v : base )
	  {
		cout << " " << v; // << ":" << to_10( input, d++ );
	  }
	  cout << endl;
	}
  }  
}
