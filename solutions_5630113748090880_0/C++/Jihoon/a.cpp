#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void fillVector(vector<bool>& heights, unsigned h)
{
	heights[h] = !heights[h];
}

string getResult(vector<bool>& heights, unsigned N)
{
	bool first = true;
	ostringstream oss;

	unsigned count = 0;
	for (unsigned i = 0; i <=2500; ++i)
	{
		if (heights[i] == true)
		{
			if (first)
			{
				first = false;
				oss << i;
			}
			else
				oss << " " << i;

			++count;
		}
	}

	if (count != N)
		cerr << "wrong answer" << endl;
	return oss.str();
}

int main()
{
	unsigned numInputs = 0;

	cin >> numInputs;

	for (unsigned i=0; i< numInputs; ++i)
	{
		vector<bool> heights;

		unsigned N;
		cin >> N;

		heights.reserve(2501);
		for (unsigned j = 0 ; j <= 2500; ++j)
			heights[j] = false;

		for (unsigned j = 0 ; j < (2*N-1); ++j)
		{
			for (unsigned k = 0; k < N; ++k)
			{
				unsigned n;
				cin >> n;
				fillVector(heights, n);
			}
		}

		cout << "Case #" << i + 1 << ": " << getResult(heights, N) << endl;
	}
	return 0;
}

