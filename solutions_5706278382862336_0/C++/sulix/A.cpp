
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
#include <popcntintrin.h>
#include <x86intrin.h>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)


int popcnt64(uint64_t val)
{
	return _mm_popcnt_u64(val);
}

uint64_t log2uint64( uint64_t x )
{
	uint64_t ans = 0 ;
	while( x>>=1 ) ans++;
	return ans;
}

int main()
{
	int numCases;
	scanf("%d", &numCases);
	forl(i,1,numCases+1)
	{
		int64_t a, b;
		scanf("%ld/%ld", &a, &b);
		cout << "Case #" << i << ": ";
		if(popcnt64(b) != 1)
		{
			cout << "impossible";
		}
		else
		{
			cout << log2uint64(b) - log2uint64(a);
		}
		cout << endl;
	}
}
