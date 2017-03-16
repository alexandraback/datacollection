#include <fstream>
using namespace std;

int main()
{
	unsigned int T, N, c, h, cd, nsd;
	bool sd[10];
	ifstream fin("countingsheep.in");
	fin >> T;
	ofstream fout("countingsheep.out");
	for (unsigned int x = 1; x <= T; x++)
	{
		fout << "Case #" << x << ": ";
		fin >> N;
		if (N == 0) fout << "INSOMNIA\n";
		else
		{
			for (unsigned int i = 0; i < 10; i++) sd[i] = false;
			nsd = 0;
			c = 0;
			while (nsd < 10)
			{
				c += N;
				h = c;
				while (h > 0)
				{
					cd = h % 10;
					if (!sd[cd])
					{
						sd[cd] = true;
						nsd++;
					}
					h /= 10;
				}
			}
			fout << c << '\n';
		}
	}
	fout.close();
	fin.close();
	return(0);
}