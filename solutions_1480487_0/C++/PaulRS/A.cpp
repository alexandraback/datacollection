#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define P pair<int,int>
#define eps 0.000000000001

int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": ";
		// result ? 
		int N;
		cin >> N;
		vector <int> s(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
			cin >> s[i], sum += s[i];
		for (int i = 0; i < N; i++)
		{
			double l = 0, h = 1;
			while (h - l >= eps)
			{
				double m = (h + l) / 2, sm = 0;
				for (int j = 0; j < N; j++)
				{
					if (j == i)	continue;
					double r = max(0.0, m + (s[i] - s[j]) / (double)sum);
					sm += r;
				}
				if (sm + m >= 1 )
					h = m;
				else
					l = m;
			}
			printf("%3.9f ", 100*h);
		}
		printf("\n");
//		printf("%1.9f\n", ans);
	}
	return 0;
}
