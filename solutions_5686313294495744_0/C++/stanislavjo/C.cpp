#include <iostream>
#include <set>

std::set<std::string> s, f;


int main()
{
	int t;
	std::cin >> t;

	std::string first, second;
	for(int _ = 0;_ < t;++ _)
	{
		int n, res = 0;
		std::cin >> n;
		for(int i = 0;i < n;++ i)
		{
			std::cin >> first >> second;
			if(f.find(first) != f.end() and s.find(second) != s.end())
			{
				res ++;
			}
			else
			{
				f.insert(first);
				s.insert(second);
			}
		}
		std::cout << "Case #" << _+1 << ": " << res << std::endl;
	}
	return 0;
}
