
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

// Terrible O(n) impl of base-2 log.
// Finds higest set bit.
int64_t log2(int64_t var)
{
	int64_t lg = 0;
	while (var >>= 1)
	{
		lg++;
	}
	return lg;
}

int64_t fac(int64_t var)
{
	if (!var) return 1;
	return var*(fac(var-1));
}

int64_t binomial(int64_t a, int64_t b)
{
	return fac(a)/(fac(b)*fac(a-b));
}

// Counts the number of combinations of two n-bit numbers which AND to 0
int64_t magicandcount(int64_t n)
{
	int64_t acc = 0;
	for(int64_t i = 0; i <= n; ++i)
	{
		cerr << "2^" << i << " * " << binomial(n,i) << endl;
		acc += (1 << i)*binomial(n,i);
	}
	return acc;
}

int main()
{
	int numCases;
	cin >> numCases;
	forl(i,1,numCases+1)
	{
		int64_t a,b,k;
		cin >> a >> b >> k;
		if (a < b)
			swap(b,a);

		int64_t kmask = (1 << (log2(k) + 1)) - 1;
		int64_t awrong = (1 << (log2(a-1) + 1)) ;
		int64_t bwrong = (1 << (log2(b-1) + 1)) ;
		int64_t ans = 0;
		if (k > b)
		{
			ans = a * b;
		}
		else
		{
			ans = k * k;
			int64_t iterans = ans;
			ans += k * (b - k);
			ans += k * (a - k);
			
			int64_t numcor = log2(b) - log2(k);
			int64_t mult = 1 << (log2(a) - log2(b));
			int64_t corrval = magicandcount(numcor);
			cerr << a << " " << b << " " << k << endl;
			cerr << "lg b - k " << numcor << "    lg a - b " << mult << "    2^(lga-b)-1 " << corrval << "    ans: " << (double)ans /  iterans << endl;
			if (a == awrong && b == bwrong && 0)
				ans = iterans * mult * corrval;
			else
			{
				forl(i,k,a)
					forl(j,k,b)
					{
						if ((i & j) < k) ans++;
					}
			}
#if 0
			forl(i,a,awrong)
			{
				//ans += k;


				// Find highest bit
				forl(j,b,bwrong)
				{
					if ((i & j) < k) ans--;
				}
			}
			cerr << "Removed " << iterans*mult*corrval - ans << " incorrect values" << awrong << " " << bwrong << "\n";
#endif

		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}
