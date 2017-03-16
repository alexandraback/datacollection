#include <fstream>
using namespace std;

const int	MAX_SIZE = 1001;
int			x[MAX_SIZE];

int main()
{
	fstream		f("in.txt");
	ofstream	g("out.txt");
	int			testCount;
	int			N, special, bestTime, maxHeight;

	f >> testCount;
	for (int test = 1; test <= testCount; test++)
	{
		f >> N;
		for (int i = 0; i < N; i++)
			f >> x[i];

		maxHeight = x[0];
		for (int i = 0; i < N; i++)
			maxHeight = max(x[i], maxHeight);

		bestTime = maxHeight;
		for (int h = 1; h <= maxHeight; h++)
		{
			special = 0;
			for (int i = 0; i < N; i++)
				special += (x[i] - 1) / h;

			bestTime = min(bestTime, special + h);
		}

		g << "Case #" << test << ": " << bestTime << endl;
	}

	return 0;
}