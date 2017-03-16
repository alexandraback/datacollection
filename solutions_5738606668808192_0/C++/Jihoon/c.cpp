#include <iostream>
#include <bitset>
#include <cmath>

#define LENGTH 16

using namespace std;

unsigned long long to_dec(bitset<LENGTH>& s, int base)
{
	unsigned long long res = 0;
	for (int i = LENGTH-1; i >= 0; --i)
	{
		if (s[i])
			res += (unsigned long long)pow(base, i);
	}
	return res;
}

unsigned long long find(unsigned long long val)
{
	unsigned long long end = sqrt(val);
	for (unsigned long long i = 2; i <= end; ++i)
	{
		if (val % i == 0)
			return i;
		
	}
	return 0;
}

void solve(unsigned N, unsigned J)
{
	if (N < 2) return;

	unsigned long long max = (unsigned long long)pow(2, N);
	unsigned j = 0;

	for (unsigned long long i = (unsigned long long)pow(2, N-1) + 1; i < max; i += 2)
	{
		bitset<LENGTH> bits(i);

		//cout << bits;
		unsigned long long divisors[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		bool failed = false;
		for (int base = 2; base <= 10; ++base)
		{
			unsigned long long val = to_dec(bits, base);
			unsigned long long divisor = find(val);
			//cout << " (" << val << " " << divisor << ")";
			if (divisor == 0)
			{
				failed = true;
				//cout << " FAILED !!!" << endl;
				break;
			}
			else
				divisors[base] = divisor;
		}
		if (!failed)
		{
			cout << bits;
			for (int base = 2; base <= 10; ++base)
			{
				cout << " " << divisors[base];
			}
			cout << endl;
			++j;
		}
		if ( j == J)
			break;
	}
}

int main()
{
	unsigned numInputs = 0;
	
	cin >> numInputs;

	for (size_t i=0; i< numInputs; ++i)
	{
		unsigned N, J;
		cin >> N >> J;

		cout << "Case #" << i + 1 << ":" << endl;
		solve(N, J);
	}	

	return 0;
}

