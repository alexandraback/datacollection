#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 10005;
const int INF = 1<<29;
const double eps = 1e-7;
const int mod = 1000000007;
typedef long long LL;

int main()
{
	int a, b, c;
	int T, nc = 0;
	cin >> T;
	while(T--)
	{
		printf("Case #%d: ", ++nc);
		cin >> a >> b >> c;
		int ans = 0;
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++)
				if((i&j) < c) ans++;
		cout << ans << endl;
	}
	return 0;
}