#include <fstream>
#include <cstring>
using namespace std;
int T, A, B, K, nr[4200], sol;

int main()
{
	int i, j, t;
	ifstream fin("B.in");
	ofstream fout("B.out");
	fin >> T;
	for(t = 1; t <= T; ++t)
	{
		fin >> A >> B >> K;
		for(i = 0; i < A; ++i)
			for(j = 0; j < B; ++j)
				nr[(i & j)]++;
		sol = 0;
		for(i = 0; i < K; ++i)
			sol += nr[i];
		memset(nr, 0, sizeof(nr));
		fout << "Case #" << t << ": " << sol << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
