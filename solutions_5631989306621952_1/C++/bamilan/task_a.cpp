//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ": ";

		std::string s;
		std::cin >> s;

		std::list<char> list;
		list.push_back(s[0]);

		FORI(i, 1, (int)s.size())
		{
			if (s[i] >= *list.begin()) list.push_front(s[i]);
			else list.push_back(s[i]);
		}

		std::list<char>::const_iterator iterator;
		for (iterator = list.begin(); iterator != list.end(); ++iterator) {
			std::cout << *iterator;
		}

		std::cout << std::endl;
	}

	return 0;
}