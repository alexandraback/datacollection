#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
	std::ifstream fin("A-small-attempt1.in");
	std::ofstream fout("out.txt");

	int t;
	fin >>t;
	for (int i = 1; i <= t; i++)
	{
		long a, n;
		long m[100];

		fin >>a >>n;
		for (int j = 0; j < n; j++)
		{
			fin >>m[j];
		}

		std::sort(m, m + n);

		if (a != 1)
		{
			long temp = a;
			long at[100];
			long more = 0;
			for (int j = 0; j < n; j++)
			{
				long count = 0;
				while (temp <= m[j])
				{
					count++;
					more += (temp - 1);
					temp += (temp - 1);
				}
				at[j] = count;
				temp += m[j];
			}
			long minValue = n;
			long ats = 0;
			for (int j = 0; j < n; j++)
			{
				ats += at[j];
				if (ats + (n - 1 - j) < minValue)
				{
					minValue = ats + (n - 1 - j);
				}
			}
			fout <<"Case #" <<i <<": " <<minValue <<std::endl;
		}
		else
		{
			fout <<"Case #" <<i <<": " <<n <<std::endl;
		}

		//fout <<"Case #" <<i <<": " <<attemp <<std::endl;
	}
}