#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d", &n);

		int* arr = new int[n];
		for (int i = 0; i < n; i++) scanf("%d", arr + i);

		printf("Case #%d:\n", t + 1);

		bool found = false;
		unsigned int m = pow(3, n);
		for (unsigned int i = 0; i < m; i++)
		{
			int l = 0,
				r = 0;

			unsigned int cur = i;

			for (int j = 0; j < n; j++)
			{
				if (cur % 3 == 1) l += arr[j];
				else if (cur % 3 == 2) r += arr[j];
				cur /= 3;
			}

			if (l != 0 && l == r)
			{
				cur = i;
				bool first = true;
				for (int j = 0; j < n; j++)
				{
					if (cur % 3 == 1) printf("%s%d", first ? "" : " ", arr[j]), first = false;
					cur /= 3;
				}

				printf("\n");

				cur = i;
				first = true;
				for (int j = 0; j < n; j++)
				{
					if (cur % 3 == 2) printf("%s%d", first ? "" : " ", arr[j]), first = false;
					cur /= 3;
				}

				printf("\n");

				found = true;
				break;
			}
		}

		if (!found) printf("Impossible\n");
	}

	return 0;
}