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
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n, m;
		cin >> n >> m;
		vector<vector<int> > mown(n);
		for (int i = 0; i < n; i++)
		{
			mown[i].resize(m);
			for (int j = 0; j < m; j++)
				cin >> mown[i][j];
		}

		bool valid = true;
		for (int i = 0; i < n && valid; i++)
		{
			for (int j = 0; j < m && valid; j++)
			{
				bool does = true;
				for (int k = 0; k < n; k++)
				{
					if (mown[k][j] > mown[i][j])
					{
						does = false;
						break;
					}
				}
				if (does) continue;
				does = true;
				for (int k = 0; k < m; k++)
				{
					if (mown[i][k] > mown[i][j])
					{
						does = false;
						break;
					}
				}
				if (!does)
				{
					valid = false;
				}
			}
		}

		if (valid)
		{
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
