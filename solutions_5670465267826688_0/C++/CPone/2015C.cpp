#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

char dot[128][128];

char dot_lower(char a, char b)
{
	if (a == 'u')
		return b;
	if (b == 'u')
		return a;
	if (a == b)
		return 'U';
	if (a == 'i' && b == 'j')
		return 'k';
	if (a == 'j' && b == 'k')
		return 'i';
	if (a == 'k' && b == 'i')
		return 'j';
	return toupper(dot_lower(b, a));
}

void init_table()
{
	const char *uijk = "uijk";
	for (const char *p = uijk; *p; ++p)
	{
		for (const char *q = uijk; *q; ++q)
		{
			char x = dot_lower(*p, *q);
			char y = isupper(x) ? tolower(x) : toupper(x);
			dot[*p][*q] = x;
			dot[toupper(*p)][*q] = y;
			dot[*p][toupper(*q)] = y;
			dot[toupper(*p)][toupper(*q)] = x;
		}
	}
}

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::ofstream out(argv[1] + std::string(".out"));

	init_table();

	int T;
	in >> T;
	for (int x = 1; x <= T; ++x)
	{
		out << "Case #" << x << ": ";

		const char *ijk = "ijk";
		char val = 'u';

		int L, X;
		std::string S;
		in >> L >> X;
		in >> S;
		for (int k = 0; k < X; ++k)
		{
			for (int j = 0; j < L; ++j)
			{
				val = dot[val][S[j]];
				if (*ijk && val == *ijk)
				{
					++ijk;
					val = 'u';
				}
			}
		}
		if (*ijk == 0 && val == 'u')
		{
			out << "YES" << "\n";
		}
		else
		{
			out << "NO" << "\n";
		}
	}
}