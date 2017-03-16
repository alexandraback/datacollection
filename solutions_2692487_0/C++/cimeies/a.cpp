#include <iostream>
#include <map>

int main()
{
	int t;
	std::cin >> t;
	for (int c = 0; c < t; ++c)
	{
		std::cout << "Case #" << (c + 1) << ": ";
		int a, n, x;
		std::cin >> a >> n;
		if (a == 1)
		{
			for (int i = 0; i < n; ++i, std::cin >> x);
			std::cout << n << std::endl;
			continue;
		}
		std::map<int, std::pair<int, int> > m;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> x;
			if (m.count(x))
			{
				++m[x].first;
			}
			else
			{
				m[x] = std::make_pair(1, 0);
			}
		}
		int current = a;
		for (std::map<int, std::pair<int, int> >::iterator it = m.begin(); it != m.end(); ++it)
		{
			for (; current <= it->first; ++it->second.second, (current <<= 1) -= 1);
			current += it->second.first * it->first;
			if (it != m.begin())
			{
				std::map<int, std::pair<int, int> >::iterator jt = it;
				it->second.second += (--jt)->second.second;
			}
		}
		int result = n, remaining = 0;
		for (std::map<int, std::pair<int, int> >::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
		{
			result = std::min(result, it->second.second + remaining);
			remaining += it->second.first;
		}
		std::cout << result << std::endl;
	}
	return 0;
}
