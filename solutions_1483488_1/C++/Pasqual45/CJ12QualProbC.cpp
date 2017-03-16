#include <set>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int A, B;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> A >> B;

		int result = 0;
		int tens = 1, digits = 1;
		set<int> seen;
		for (int i=1; i<B; ++i)
		{
			if (i == tens*10) tens *= 10, ++digits;
			if (i<A) continue;

			seen.clear();
			int num(i);
			for (int j=1; j<digits; ++j)
			{
				num = num/10 + tens * (num%10);
				if (num > i && num <= B)
					seen.insert(num);
			}
			result += seen.size();
		}

		fout << "Case #" << zz << ": " <<result << endl;
	}

	return 0;
}