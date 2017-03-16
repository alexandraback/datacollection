#include <ios>
#include <iostream>

int cnt[2505] = {};
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int tc, n, x;
	bool first;
	std::cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		std::cout << "Case #" << t+1 << ":";
		
		first = true;
		for (int i = 0; i < 2505; i++) cnt[i] = 0;
		
		std::cin >> n;
		for (int i = 0; i < 2*n-1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cin >> x;
				cnt[x]++;
			}
		}
		for (int i = 0; i < 2505; i++)
		{
			if (cnt[i] & 1)
			{
				std::cout << ' ' << i;
			}
		}
		std::cout << '\n';
	}
}
