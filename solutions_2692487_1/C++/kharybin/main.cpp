#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template <class T> T sqr(T x) { return x*x; }

const int INF = 1000*1000*1000;
const long long INF64 = sqr(static_cast<long long>(INF));
const double PI = acos(-1.0);

const int N = 110;

int sz[N];
int n, s;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCaseCount;
	cin >> testCaseCount;
	for(int testCaseNumber = 1; testCaseNumber <= testCaseCount; ++testCaseNumber)
	{
		cin >> s >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d", sz+i);
		sort(sz, sz+n);
		int ans = n;
		for (int i = n; i >= 0; --i)
		{
			int cur = s;
			int p = 0;
			for (int j = 0; j < i;)
			{
				while (j < i && sz[j] < cur)
				{
					cur += sz[j];
					++j;
				}
				if (j >= i)
					break;
				++p;
				if (cur == 1)
				{
					p += n;
					break;
				}
				cur += cur-1;
			}
			ans = min(ans, p+n-i);
		}
		cout << "Case #" << testCaseNumber << ": " << ans << endl;
	}
	return 0;
}