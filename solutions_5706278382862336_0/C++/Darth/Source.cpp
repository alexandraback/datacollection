#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("input.txt");
	ofstream fout("output.txt");

	int t;

	fin >> t;
	long result;
	long a, b;
	long bk, ak;
	char ch;
	bool fail;
	for (int test = 0; test < t; test++)
	{
		fin >> a >> ch >> b;
		fail = false;

		bk = 0;
		int bn = b;
		result = 0;
		while (1)
		{
			if (bn%2 == 0)
			{
				bn= bn /2 ;
				bk++;
			} else break;
		}
		if (a%bn != 0)
			fail = true;
		else
		{
			a = a / bn;
			b = b / bn;
			while (a < b)
			{
				b = b / 2;
				result ++;
			}
		}


		fout << "Case #" << (test+1) << ": ";
		if (fail)
			fout << "impossible" << endl;
		else 
			fout << result<< endl;
	}

	return 0;
}