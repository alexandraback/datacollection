#include<iostream>
#include<vector>
#include<iomanip>
#include<stdint.h>
using namespace std;

#define MAX_NUM 100000000
void check_sleepy( uint64_t n, int iterations, int casenum )
{
	vector<uint64_t> v;
	v.push_back(n);
	int bitsfound = 0;
	int targetbits = 0x3FF;
	for ( int iter_ct = 0 ; iter_ct < iterations; iter_ct++ )
	{
		for ( int i = 0 ; i < v.size() ; i++ )
		{
			uint64_t j = v[i];
			if ( i == v.size() - 1 )
			{
				while ( j )
				{
					bitsfound |= (1<<(j%10));
					j /= 10;
				}
			}
			else
			{
				for ( uint64_t tens = MAX_NUM/10; tens ; tens /= 10 )
				{
					bitsfound |= (1<<(j%10));
					j /= 10;
				}
			}
		}

		if ( bitsfound == targetbits )
		{

			cout << "Case #" << casenum << ": ";
			for ( int i = 0 ; i < v.size() ; i++ )
			{
				uint64_t j = v[v.size()-i - 1 ];
				if ( ! i )
				{
					uint64_t tens = MAX_NUM/10;
					while ( j/tens == 0 )
						tens /= 10;
					for ( ; tens ; j -= j/tens*tens, tens /= 10 )
						cout << j/tens;
				}
				else
				{
					for ( uint64_t tens = MAX_NUM/10; tens ; j -= j/tens*tens, tens /= 10 )
						cout << j/tens;
				}
			}
			cout << endl;
			break;
		}

		uint64_t n_prod;
		uint64_t n_carry = n ;
		for ( int i = 0 ; i < v.size() && n_carry; i++ )
		{
			n_prod = v[i] + n_carry;
			v[i] = n_prod % MAX_NUM;
			n_carry = n_prod / MAX_NUM;
		}
		if ( n_carry )
		{
			v.push_back(n_carry);
			uint64_t j = n_carry;
			while ( j )
			{
				bitsfound |= (1<<(j%10));
				j /= 10;
			}
		}
	}
	if ( bitsfound != targetbits )
	{
		cout << "Case #" << casenum << ": INSOMNIA" << endl;
	}

}
int main( int argc, char * argv[] )
{
	uint64_t t, n;
	cin >> t;
	int casenum = 1;
	while ( t-- )
	{
		cin >> n;
		check_sleepy( n, 500, casenum++ );
	}
}
