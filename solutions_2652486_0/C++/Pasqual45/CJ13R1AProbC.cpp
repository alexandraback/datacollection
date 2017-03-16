#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

//int main13R1APC()
int main()
{
	ifstream fin("C-small-1-attempt0.in");
	ofstream fout("C-small-1-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int R,N,M,K;
	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> R >> N >> M >> K;

		fout << "Case #" << zz << ":" << endl;

		for (int i=0; i<R; ++i)
		{
			int maxCount[6] = {0};
			for (int j=0; j<K; ++j)
			{
				int val;
				fin >> val;
				for (int k=5; k>1; --k)
				{
					int cur = 0;
					while ((val%k)==0)
						++cur, val /= k;

					maxCount[k] = max(maxCount[k], cur);
				}
			}

			int used(0);
			for (int j=2; j<=M; ++j)
				while (maxCount[j]-- > 0)
				{
					++used;
					fout << j;
				}

			while (used++ < N)
				fout << "2";
			fout << endl;
		}
	}

	return 0;
}