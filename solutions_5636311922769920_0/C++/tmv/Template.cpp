#include <iostream>
#include <vector>
#include <string>

using namespace std;

static void WritePos(int K, int C, const vector<int> &v)
{
	/*
	cout << "[";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << "]\n";
	*/

	_int64 pos = 0;
	for (int i = 0; i < C; ++i)
	{
		pos *= K;
		pos += (v[i] - 1);
	}
	cout << pos + 1;
}

static void HandleCase(const int cse)
{
	cout << "Case #" << cse << ":";

	int K, C, S;
	cin >> K >> C >> S;

	int S_needed = (K + C - 1) / C; // =ceil(K/C)
	if (S < S_needed)
	{
		cout << " IMPOSSIBLE" << endl;
		return;
	}

	vector<int> v;
	for (int i = 1; i <= K; i += C)
	{
		v.resize(0);
		for (int j = 0; j < C; ++j)
		{
			int val = i + j;
			if (val > K)
				val = 1;
			v.push_back(val);
		}
		cout << " ";
		WritePos(K, C, v);
	}
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


