#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

// Slides!

static void HandleCase(const int cse)
{
	_int64 B, M;
	cin >> B >> M;

	if (M > 1 + (B - 1) * (B - 2) / 2)
	{
		cout << "Case #" << cse << ": IMPOSSIBLE" << endl;
		return;
	}

	vector<int> mat(B * B);

	for (int i = 0; i < B - 1; ++i)
	{
		int y = i;
		int x = i + 1;
		mat[B * y + x] = 1;
	}

	int count = 1;
	for (int y = 0; y <= B - 3; ++y)
	{
		if (count == M)
			break;
		for (int x = y + 2; x <= B - 1; ++x)
		{
			mat[B * y + x] = 1;
			++count;
			if (count == M)
				break;
		}
		if (count == M)
			break;
	}

	cout << "Case #" << cse << ": POSSIBLE" << endl;
	for (int y = 0; y < B; ++y)
	{
		for (int x = 0; x < B; ++x)
		{
			cout << mat[B*y + x];
		}
		cout << endl;
	}
}


int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	freopen("B-small-attempt7.in", "r", stdin);
	freopen("B-small-attempt7.out", "w", stdout);

	//freopen("C-large-practice.in", "r", stdin);
	//freopen("C-large-practice.out", "w", stdout);

	int T;
	cin >> T;

	//string str;
	//getline(cin, str, '\n');

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


