#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lint;
typedef vector<int> vi;
typedef vector<string> vs;
const int INF = 0x7fffffff;

int Solution()
{
	int a, n;
	cin >> a >> n;
	vi mas(n);
	for(int i = 0; i < n; ++i)
		cin >> mas[i];
	sort(mas.begin(), mas.end());
	int ind = 0;
	while(ind < n && mas[ind] < a)
	{
		a += mas[ind];
		++ind;
	}
	if(ind == n)
	{
		cout << 0;
		return 0;
	}
	if(a == 1)
	{
		cout << n;
		return 0;
	}

	int ans = 10000;
	for(int i = 0; i <= n - ind; ++i)
	{
		int cnt = i;
		int nowA = a;
		int nowInd = ind;
		while(nowInd < n - i)
		{
			if(nowA <= mas[nowInd])
			{
				nowA += nowA - 1;
				cnt++;
				continue;
			}
			nowA += mas[nowInd];
			nowInd++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}

#define debug 1

int main()
{
#ifdef debug
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
#endif
	int n;
	cin >> n;
	getchar();
	for(int i = 1; i <= n; ++i)
	{
		printf("Case #%d: ", i);
		Solution();
		printf("\n");
	}
	return 0;
}
