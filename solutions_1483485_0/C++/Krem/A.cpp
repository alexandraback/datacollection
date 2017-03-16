#include<iostream>

char trans[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	std::ios::sync_with_stdio(0);
	int T; std::cin >> T;
	std::cin.ignore();
	for(int ii = 0; ii < T; ii++)
	{
		std::cout << "Case #" << ii+1 << ": ";
		char c;
		while(c = std::cin.get(), c!='\n')
		{
			if(c==' ')
				std::cout << ' ';
			else
				std::cout << trans[c-'a'];
		}
		std::cout << '\n';
	}
	return 0;
}
