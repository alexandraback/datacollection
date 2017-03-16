#include <ios>
#include <iostream>
#include <string>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	std::string k, d, tmp, what;
	int tc, tmpdist;
	
	std::cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		std::cout << "Case #" << t+1 << ": ";
		std::cin >> k;
		
		k += '+';
		int ccs = 1;
		for (int i = 1; i < k.length(); i++)
		{
			if (k.at(i) != k.at(i-1)) ccs++;
		}
		std::cout << ccs-1 << '\n';
	}
}
