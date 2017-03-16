#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("B-large.in");
	ofstream fout("out.txt");

	int t;
	fin >>t;
	for (long i = 1; i <= t; i++)
	{
		fout <<"Case #" <<i <<": "; 
		long x, y;
		fin >>x >>y;

		long value = abs(x)+abs(y);
		long a = 0;
		long count = 0;
		bool flag = true;
		while (true)
		{
			count++;
			a+=count;
			if (a>value)
			{
				if (a%2 ==value%2)
				{
					break;
				}
			}
		}

		fout <<count <<endl;
	}

	return 0;
}