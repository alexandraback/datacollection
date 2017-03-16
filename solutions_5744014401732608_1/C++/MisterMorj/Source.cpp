#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
#include <set>

using namespace std;

long long int B, M;
bool gr[100][100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		cin >> B >> M;
		for (int j = 0; j < B; j++)
			for (int q = j + 1; q < B; q++)
				gr[j][q] = 1;
		long long int max_ans = 1;
		for (int j = 0; j < B - 2; j++)
			max_ans *= 2;
		if (M > max_ans)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;
			long long int dead_e = max_ans / 2;
			int pos = B - 2;
			while (max_ans > M)
			{
				if (max_ans - dead_e >= M)
				{
					gr[pos][B - 1] = 0;
					max_ans -= dead_e;
				}
				pos--;
				dead_e = max(dead_e / 2, long long int(1));
			}
			for (int j = 0; j < B; j++)
			{
				for (int q = 0; q < B; q++)
					cout << gr[j][q];
				cout << endl;
			}
		}
	}

}