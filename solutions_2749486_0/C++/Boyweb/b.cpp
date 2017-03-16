#include <fstream>

using namespace std;

int main()
{
	ifstream fin("B-small-attempt1.in");
	ofstream fout("out.txt");

	int t;
	fin >>t;
	for (int i = 1; i <= t; i++)
	{
		fout <<"Case #" <<i <<": "; 
		int x, y;
		fin >>x >>y;
		if (y > 0)
		{
			for (int j = 0; j < y; j ++)
			{
				fout <<"SN";
			}
		}
		else if (y < 0)
		{
			for (int j = 0; j < -y; j ++)
			{
				fout <<"NS";
			}
		}
		if (x > 0)
		{
			for (int j = 0; j < x; j ++)
			{
				fout <<"WE";
			}
		}
		else if (x < 0)
		{
			for (int j = 0; j < -x; j ++)
			{
				fout <<"EW";
			}
		}
		fout <<endl;
	}

	return 0;
}