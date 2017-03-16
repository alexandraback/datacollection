#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int N, S, p, t;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> N >> S >> p;

		int s1 = max(p, p*3-2);
		int s2 = max(p, p*3-4);

		int result = 0;
		for (int i=0; i<N; ++i)
		{
			fin >> t;
			if (t >= s1)
				++result;
			else if (S > 0 && t >= s2)
				++result, --S;
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}