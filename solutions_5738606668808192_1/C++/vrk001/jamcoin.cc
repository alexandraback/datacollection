#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<uint64_t> primes;
#define MAX_NUM 10
class bigint
{
public:
	bigint & operator += ( bigint & bg )
	{
		uint64_t n_carry = 0;
		for ( int i = 0 ; ; i++ )
		{
			if ( ! n_carry && i >= bg.v.size() )
				break;
			if ( i >= v.size() )
				v.push_back(0);
			n_carry = v[i] + ( ( i < bg.v.size() ) ? bg.v[i] : 0 )  + n_carry;
			v[i] = n_carry % MAX_NUM;
			n_carry = n_carry / MAX_NUM;
		}
		return *this;
	}
	bigint & operator += ( uint64_t m )
	{
		uint64_t n_prod;
		uint64_t n_carry = m ;
		for ( int i = 0 ; i < v.size() && n_carry; i++ )
		{
			n_prod = v[i] + n_carry;
			v[i] = n_prod % MAX_NUM;
			n_carry = n_prod / MAX_NUM;
		}
		if ( n_carry )
			v.push_back(n_carry);
		return *this;
	}
	bigint & operator *= ( uint64_t m )
	{
		uint64_t n_prod;
		uint64_t n_carry = 0 ;
		for ( int i = 0 ; i < v.size() ; i++ )
		{
			n_prod = m * v[i] + n_carry;
			v[i] = n_prod % MAX_NUM;
			n_carry = n_prod / MAX_NUM;
		}
		while ( n_carry )
		{
			v.push_back(n_carry%MAX_NUM);
			n_carry /= MAX_NUM;
		}
		return *this;
	}
	uint64_t operator % ( uint64_t m )
	{
		uint64_t n_carry = 0 ;
		for ( int i = v.size()-1  ; i >= 0 ; i-- )
		{
			n_carry = ( ( n_carry * MAX_NUM ) + v[i] ) % m;
		}
		return n_carry;
	}
	public:
	vector<uint64_t> v;

};
ostream & operator << ( ostream & ostr, bigint & bg )
{
	for ( int i = 0 ; i < bg.v.size() ; i++ )
	{
		uint64_t j = bg.v[bg.v.size()-i - 1 ];
		if ( ! i )
		{
			uint64_t tens = MAX_NUM/10;
			while ( j/tens == 0 )
				tens /= 10;
			for ( ; tens ; j -= j/tens*tens, tens /= 10 )
				ostr << j/tens;
		}
		else
		{
			for ( uint64_t tens = MAX_NUM/10; tens ; j -= j/tens*tens, tens /= 10 )
				ostr << j/tens;
		}
	}
	return ostr;
}

uint64_t max_prime = 2;
uint64_t divisor_of_sum( bigint & sum )
{
	for ( uint64_t i = 0 ; i < primes.size() && primes[i] <= 0xFFFF ; i++ )
		if ( sum % primes[i] == 0 )
			return primes[i];
	primes.push_back( sum.v[0] ); // BE CAREFUL HERE : REVISIT
	return (1);
}
void solve( uint64_t n, uint64_t count_jc )
{
	uint64_t i;
	for ( i = ( 1ULL << ( n - 1 ) ) | 1 ; count_jc && i < ( 1ULL << n ) ; i += 2 )
	{
		vector<uint64_t> divisors;
		//cout << endl;
		for ( int base = 2; base <= 10 ; base++ )
		{
			//cout << "Base=" << base << " ";
			uint64_t j = i;
			bigint sum;
			bigint coeff;
			coeff += 1;
			while ( j )
			{
				//if ( j & 1 ) 
					//cout << coeff << "x" << (j&1) << "=";
				if ( j & 1 )
					sum += coeff;
				j = j >> 1;
				coeff *= base;
			}
			//cout << sum << "(" << divisor_of_sum(sum) << "), ";
			if ( divisor_of_sum(sum) == 1 )
				break;
			divisors.push_back( divisor_of_sum(sum) );
			if ( base == 10 )
			{
				cout << sum;
				for ( int k = 0 ; k < divisors.size() ; k++ )
					cout << ' ' << divisors[k];
				cout << endl;
				count_jc--;
			}
		}
	}
}
int main( int argc, char * argv[] )
{
	uint64_t t, n, j;
	cin >> t;
	uint64_t last_i = 2;
	primes.push_back(2);
	for ( uint64_t i = 3; i < 100; last_i = i , i+= 2 )
	{
		uint64_t k;
		for ( k = 0 ; k < primes.size() ; k++ )
			if ( i % primes[k] == 0 )
				break;
		if ( k == primes.size() )
			primes.push_back(i);
	}

	for ( int casenum = 1 ; casenum <= t ; casenum++ )
	{
		cout << "Case #" << casenum++ << ":" << endl;
		cin >> n >> j;
		solve( n, j );
	}
}
