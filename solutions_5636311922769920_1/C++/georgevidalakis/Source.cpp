#include <fstream>
using namespace std;

unsigned long long int pow(unsigned int b, unsigned int e)
{
	unsigned long long int r = 1;
	for (unsigned int i = 0; i < e; i++) r *= b;
	return(r);
}

int main()
{
	unsigned int T, K, C, S, ns;
	unsigned long long int p;
	ifstream fin("fractiles.in");
	fin >> T;
	ofstream fout("fractiles.out");
	for (unsigned int x = 1; x <= T; x++)
	{
		fout << "Case #" << x << ":";
		fin >> K >> C >> S;
		ns = K / C;
		if (K % C) ns++;
		if (S < ns) fout << " IMPOSSIBLE";
		else
		{
			for (unsigned int v = 0; v < K / C; v++)
			{
				p = v * C * pow(K, C - 1);
				for (unsigned int d = 1; d < C; d++) p += (v * C + d) * pow(K, C - 1 - d);
				fout << ' ' << p + 1;
			}
			if (K % C)
			{
				unsigned int v = K / C;
				p = v * C * pow(K, C - 1);
				for (unsigned int d = 1; d < K % C; d++) p += (v * C + d) * pow(K, C - 1 - d);
				fout << ' ' << p + 1;
			}
		}
		fout << '\n';
	}
	fout.close();
	fin.close();
	return(0);
}