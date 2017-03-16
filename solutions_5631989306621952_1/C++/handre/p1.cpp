#define R1AP1
#ifdef R1AP1


#include <iostream>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>

int main(void) {
	int testCases;
	std::cin >> testCases;

	for (int c = 1; c <= testCases; c++) {
		std::cout << "Case #" << c << ": ";

		std::list<char> word;
		char buff[2048];
		scanf("%s", buff);
		word.push_back(buff[0]);
		char * curr_c = buff + 1;
		while (*curr_c) {
			if (*curr_c >= *word.begin()) word.push_front(*curr_c);
			else word.push_back(*curr_c);
			curr_c++;
		}
		for (auto i : word) printf("%c", i);
		printf("\n");
	}
	return 0;
}

#endif