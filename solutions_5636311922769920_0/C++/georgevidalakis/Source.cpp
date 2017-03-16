#include <fstream>
using namespace std;

int main()
{
	unsigned int T, K, C, S, tm, p;
	ifstream fin("fractiles.in");
	fin >> T;
	ofstream fout("fractiles.out");
	for (unsigned int x = 1; x <= T; x++)
	{
		fout << "Case #" << x << ":";
		fin >> K >> C >> S;
		tm = 1;
		for (unsigned int i = 1; i < C; i++) tm *= K;
		for (unsigned int i = 0; i < K; i++)
		{
			fout << ' ' << i + 1;
		}
		fout << '\n';
	}
	fout.close();
	fin.close();
	return(0);
}