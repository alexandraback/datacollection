#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		int N;
		cin >> N;
		vector<int> cnts(2501, 0);
		for (int i = 0; i < 2 * N - 1; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int v;
				cin >> v;
				cnts[v]++;
			}
		}
		vector<int> ret;
		for (int i = 1; i <= 2500; ++i)
		{
			if (cnts[i] % 2 == 1)
			{
				ret.push_back(i);
			}
		}
		printf("Case #%d:", cn);
		for (int i = 0; i < ret.size(); ++i)
			printf(" %d", ret[i]);
		printf("\n");
	}
}