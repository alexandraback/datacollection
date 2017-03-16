#include <bits/stdc++.h>
using namespace std;

void test()
{
	long long B, M;
	cin >> B >> M;
	
	long long max = 1 << (B-2);
	if (M > max)
	{
		cout << "IMPOSSIBLE";
		return;
	}
	
	cout << "POSSIBLE" << endl;
	
	// i = 1
	cout << '0';
	int z = M;
	for (size_t j = 2; j<=B; ++j)
	{
		int value = j == B ? 1 : (1 << (B-j-1));
		if (z >= value)
		{
			cout << '1';
			z -= value;
		}
		else
			cout << '0';
	}
	cout << endl;
	
	for (size_t i = 2; i<=B; ++i)
	{
		for (size_t j = 1; j<=B; ++j)
		{
			cout << (j>i) ? '1':'0';
		}
		if (i<B) cout << endl;
	}
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ": ";
		test();
		std::cout << std::endl;
	}
}
