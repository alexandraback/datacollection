#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");

	int t;
	fin >>t;
	for (int k = 1; k <= t; k++)
	{
		char str[1000000];
		long value1, value2, n;

		fin >>str >>n;

		bool flag = false;
		long count = 0, preCount = 0;
		for (long i = 0; i < strlen(str); i++)
		{
			if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
			{
				if (!flag)
				{
					flag = true;
					value1 = 1;
				}
				else
				{
					value1 = value2 + 1;
				}
				if (value1 >= n)
				{
					count += (i - n + 2);
					preCount = i - n + 2;
				}
				else
				{
					count += preCount;
				}
			}
			else
			{
				flag = false;
				count += preCount;
			}
			value2 = value1;
		}
		fout <<"Case #" <<k <<": " <<count <<endl;
	}

	return 0;
}