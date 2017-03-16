// Compile with TDM-GCC-64 5.1 with c++11 features

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// operator<< by http://stackoverflow.com/questions/25114597/how-to-print-int128-in-g
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

unsigned int getdivisor(__int128 x) {
	unsigned int n = 100000;  // limit time of execution at the expense of imperfect calculations.
	if (x < static_cast<__int128>(100000) * static_cast<__int128>(100000))
		unsigned int n = floor(sqrt(static_cast<int64_t>(x)));
	for (unsigned int i = 2; i <= n; i+=1) {
		if (x % i == 0 && x > i)
			return i;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int N;
	std::cin >> N;
	std::string str;
	std::getline(std::cin, str);

	for (int i=0; i < N; i++) {
		std::cout << "Case #" << (i+1) << ":";
		cout << '\n';

		int n, j;
		cin >> n >> j;

		int numCoins = 0;
		unsigned int start = 1 << (n-1);
		for (unsigned int x = 1; x < start; x += 2) {
			unsigned int v = start + x;

			std::string coinvalue;
			std::vector<__int128> basen(11, 0);
			std::vector<__int128> placen(11, 1);

			for (unsigned int v1 = v; v1 > 0; v1 >>= 1) {
				int r = v1 & 1;
				coinvalue = (r ? '1' : '0') + coinvalue;
				for (unsigned int i = 2; i <= 10; i++) {
					basen[i] += r * placen[i];
					placen[i] *= i;
				}
			}

			bool hasNoPrime = true;
			std::vector<unsigned int> divisorn(11, 0);
			for (unsigned int i = 2; i <= 10; i++) {
				divisorn[i] = getdivisor(basen[i]);
				if (divisorn[i] == 0)
					hasNoPrime = false;
			}

			if (hasNoPrime) {
				cout << coinvalue;
				for (unsigned int i = 2; i <= 10; i++)
					cout << ' ' /*<< basen[i] << ':'*/ << divisorn[i];
				cout << '\n';
				++numCoins;
				if (numCoins >= j)
					break;
			}
		}
	}

	return 0;
}
