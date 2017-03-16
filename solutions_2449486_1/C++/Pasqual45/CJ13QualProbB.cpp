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

//int main13QB()
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int maxRow[100], maxCol[100], a[100][100];
	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		memset(maxRow, 0, sizeof(maxRow));
		memset(maxCol, 0, sizeof(maxCol));

		int N, M;
		fin >> N >> M;

		for (int i=0; i<N; ++i)
		{
			for (int j=0; j<M; ++j)
			{
				fin >> a[i][j];
				maxRow[i] = max(maxRow[i], a[i][j]);
				maxCol[j] = max(maxCol[j], a[i][j]);
			}
		}

		string result = "YES";

		for (int i=0; i<N; ++i)
			for (int j=0; j<M; ++j)
				if (a[i][j] < maxRow[i] && a[i][j] < maxCol[j])
					result = "NO";

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}