// Round 1B

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()

using namespace std;

static void HandleCase(const int cse)
{
	int N;
	cin >> N;

	vector<vector<int> > in(2*N, vector<int>(N));
	vector<int> count(2500);

	for (int i = 0; i < 2 * N - 1; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> in[i][j];
			++count[in[i][j]];
		}
	}

	// find missing one
	int pos = 0;
	for (int i = 1; i <= 2500; ++i)
	{
		if ((count[i] % 2) == 1)
			in[2 * N - 1][pos++] = i;
	}
	sort(in[2 * N - 1].begin(), in[2 * N - 1].end());

	cout << "Case #" << cse << ":";
	for (int i = 0; i < N; ++i)
		cout << " " << in[2 * N - 1][i];
	cout << endl;
}


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


