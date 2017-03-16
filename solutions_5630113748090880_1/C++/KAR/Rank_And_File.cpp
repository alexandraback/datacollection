#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	unsigned int		T, iIndex = 0, N;

	ifstream	InFile("B-large.in");
	ofstream	OutFile("Test.out", ios_base::ate || ios_base::out);

	if (OutFile.is_open() && InFile.is_open())
	{
		InFile >> T;

		while (T--)
		{
			InFile >> N;

			map<int, int>	mpElements;
			vector<int>		vecResult;

			for (int i = 0; i < (N << 1) - 1; ++i)
			{
				for (int x = 0; x < N; ++x)
				{
					int	nHeight;
					InFile >> nHeight;
					++mpElements[nHeight];
				}
			}

			for (map<int, int>::iterator it = mpElements.begin(); it != mpElements.end(); ++it)
			{
				if (it->second & 1)
					vecResult.push_back(it->first);
			}
			std::sort(vecResult.begin(), vecResult.end());

			OutFile << "Case #" << ++iIndex << ": ";

			for (int i = 0; i < vecResult.size() - 1; ++i)
				OutFile << vecResult[i] << " ";

			OutFile << vecResult.back() << endl;
		}
	}

	return 0;
}
