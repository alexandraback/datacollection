#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream inF;
	ofstream outF;

	inF.open("small-b.in");
	outF.open("small-b.out");

	int t;
	inF >> t;
	
	/*
	int **lists = new int*[max_n];
	for (int i = 0; i < max_n; ++i)
	{
		lists[i] = new int[max_n];
	}
	*/
	map<int, bool> found;
	map<int, bool>::iterator it;
	vector<int> missing;
	for (int test_case = 1; test_case < t + 1; ++test_case)
	{
		int n;
		inF >> n;

		int num;

		for (int row = 0; row < 2*n - 1; ++row)
		{
			for (int col = 0; col < n; ++col)
			{
				inF >> num;
				it = found.find(num);
				if (it == found.end())
				{
					found.insert(pair<int, bool>(num, false));
				}
				else
				{
					it->second = !it->second;
				}
			}
		}

		outF << "Case #" << test_case << ": ";
		for (it = found.begin(); it != found.end(); ++it)
		{
			if (!it->second)
			{
				outF << it->first << " ";
			}
		}
		outF << endl;

		found.clear();
	}

	/*
	for (int d = 0; d < max_n; ++d)
	{
		delete[] lists[d];
	}
	delete[] lists;
	*/
	inF.close();
	outF.close();

	return 0;
}