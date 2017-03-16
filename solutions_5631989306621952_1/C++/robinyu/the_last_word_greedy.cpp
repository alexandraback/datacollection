#include <ios>
#include <iostream>
#include <string>
#include <deque>

std::deque<char> d;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int tc;
	std::string k;
	std::cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		std::cin >> k;
		std::cout << "Case #" << t+1 << ": ";
		
		d.push_back(k.at(0));
		for (int i = 1; i < k.length(); i++)
		{
			if (d.front() > k.at(i)) d.push_back(k.at(i));
			else d.push_front(k.at(i));
		}
		while (!d.empty())
		{
			std::cout << d.front();
			d.pop_front();
		}
		std::cout << '\n';
	}
}
