#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 10000;
int a[MAXSIZE], b[MAXSIZE], c[MAXSIZE];
int L;
LL countbit(long long x)
{
	LL ans = 0;
	for (LL i = 0; i < 64; ++i)
	{
		ans += x % 2;
		x = x >> 1;
	}
	return ans;
}
int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "B-small-attempt2.in", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	memset(a, 0, sizeof(a));
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for (int i = 4; i < MAXSIZE; ++i)
		a[i] = a[(i - 1) / 2 + 1] + 1;
	for (LL z = 1; z <= T; ++z)
	{
		
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cout << "Case #" << z << ": ";
		int n;
		cin >> n;
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if (m < a[i])
				m = a[i];
		}
		int ans = 10000000000;
		for (int t = 1; t <= m; ++t)
		{
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				if (a[i]>t)
				count += (a[i]-t-1) / t+1;
			}
			if (count + t < ans)
				ans = count + t;
		}
		cout << ans << endl;

	}

}
