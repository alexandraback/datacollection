#include <iostream>
#include <string>
using namespace std;

int64_t reverse(int64_t x)
{
	int64_t result = 0;
	for(int64_t rest = x; rest; rest /= 10)
	{
		int64_t next = result*10 + (rest % 10);
		if(result != next/10) return 0;
		result = next;
	}
	return result;
}

int ndigit(int64_t x)
{
	int count = 1;
	while(x /= 10) ++count;
	return count;
}

int64_t solve(int64_t x)
{
	int64_t count = 0;
	while(x > 19)
	{
		int nd = ndigit(x)/2;
		int64_t b = 1;
		while(nd--) b *= 10;
		if(int64_t k = (x % b))
		{
			x -= k - 1;
			count += k - 1;
			int64_t r = reverse(x);
			if(r < x)
			{
				++count;
				x = r;
			}
		}
		++count;
		--x;
	}
	return count + x;
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		int64_t x; cin >> x;
		cout << solve(x) << endl;
	}
	return 0;
}
