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
		printf("Case #%d:\n", testCounter + 1);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		map<int, int> m;
		map<int, int>::iterator itr;
		bool found = false;
		for (int i = 0; i < (1 << n) && !found; i++)
		{
			int sum = 0;
			for(int j = 0; j < n; j++)
			{
				if (i & (1 << j))
					sum += v[j];
			}
			if ((itr = m.find(sum)) != m.end())
			{
				int a = itr->second ^ (itr->second & i);
				int b = i ^ (itr->second & i);
				bool first = true;
				for (int j = 0; j < n; j++)
				{
					if (!(a & (1 << j)))
						continue;
					if (!first)
						printf(" ");
					first = false;
					printf("%d", v[j]);
				}
				cout << endl;
				first = true;
				for (int j = 0; j < n; j++)
				{
					if (!(b & (1 << j)))
						continue;
					if (!first)
						printf(" ");
					first = false;
					printf("%d", v[j]);
				}
				cout << endl;
				found = true;
			} else {
				m.insert(make_pair(sum, i));
			}
		}
		if (!found)
			cout << "Impossible" << endl;
	}
	return 0;
}
