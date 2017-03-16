#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	int n, r, m, k;
	cin >> r >> n >> m >> k;
	printf("Case #1:\n");
	for(int o = 0; o < r; o++)
	{
		vector<int> numbers(k);
		for (int j = 0; j < k; j++)
		{
			cin >> numbers[j];
		}
		int p[3] = {2, 3, 5};
		vector<int> degs(3);
		vector<int> minDegs(3, 5);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int deg = 0;
				int temp = numbers[i];
				while (temp % p[j] == 0)
				{
					temp /= p[j];
					deg++;
				}
				degs[j] = max(degs[j], deg);
				if (deg > 0)
					minDegs[j] = min(minDegs[j], deg);
			}
		}
		vector<int> res(n);
		int idx = 0;
		for (int j = 1; j <= 2; j++)
		{
			for (int i = 0; i < degs[j]; i++)
				res[idx++] = p[j];
		}

		if ((n - idx) * 2 == degs[0])
		{
			for (int i = 0; idx < n; i++)
			{
				res[idx++] = 4;
			}
		} else {
			if (minDegs[0] == 1)
				res[idx++] = 2;
			int num4 = (n - idx) * 2 - degs[2];
			for (int i = 0; i < num4 && idx < n; i++)
			{
				res[idx++] = 4;
			}
			while(idx < n)
			{
				res[idx++] = 2;
			}
		}

		for (int i = 0; i < n; i++)
			cout << res[i];
		cout << endl;
		
	}
	return 0;
}
