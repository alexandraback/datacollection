#include<iostream>
#include<vector>

using namespace std;

#define LIM 100000005

vector< unsigned > primes;
bool seen[LIM];

void sieve(){
	primes.push_back( 2 );
	for( int j = 3; j < LIM; j += 2 ){
		if( seen[ j ] ) continue;
		primes.push_back( j );
		for( int i = j+j; i < LIM; i += j )
			seen[ i ] = true;
	}
}

bool isPrime( long long n ){
	for( int i = 0; i < int( primes.size() ); i++ ){
		if( primes[ i ] == n ) return true;
		if( (n % primes[ i ] ) == 0 ) return false;
		if( n < primes[ i ] ) break;	
	}
	return true;
}

int getDivisor( long long n ){
	for( int i = 0; i < int( primes.size() ); i++ ){
		if( (n % primes[ i ] ) == 0 ) 
			return primes[ i ];
	}
	return 0;
}

void printBase2( long long n , int N){
	while( true ){
		if( (1LL<<N)&n ) cout << 1;
		else cout << 0;
		N--;	
		if( N < 0 ) 
			break;
	}
	//cout << endl;
}

long long convert( long long n, int base ){
	long long res = 0;
	long long addbase = 1;
	while( n ){
		if( n&1 ) res += addbase;
		addbase *= base;
		n >>= 1;
	}
	return res;
}

int main(){
	sieve(); //cout << primes.size() << endl;
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		cout << "Case #" << kase << ":" << endl;
		long long N, J;
		cin >> N >> J;
		for( long long num = (1LL << (N-2)); J > 0 && num < (1LL << (N-1)); num++ ){
			long long num2 = (1LL << (N-1))|(num << 1)|1LL;
			vector< long long > cs;
			bool ok = true;
			for( int base = 2, p = 0; base < 11; base++, p++ ){	
				cs.push_back( convert( num2 , base ) );
				if( isPrime( cs[ p ] ) ){
					ok = false; 
					break;
				}
			}
			if( ok ){
				J--;
				printBase2( num2 , N-1 );
				for( int base = 2, p = 0; base < 11; base++, p++ ){
					cout << " " << getDivisor( cs[ p ] );
				}
				cout << endl;
			}
		}	
	}
}
