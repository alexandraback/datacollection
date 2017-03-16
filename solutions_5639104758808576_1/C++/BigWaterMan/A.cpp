#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 10000;
long long a[MAXSIZE], b[MAXSIZE], c[MAXSIZE];
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
	err1 = freopen_s(&fin, "A-large.in", "r", stdin);
	//err1 = freopen_s(&fin, "A-small-attempt4.in", "r", stdin);
	//err1 = freopen_s(&fin, "in.txt", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	for (LL z = 1; z <= T; ++z)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cout << "Case #" << z << ": ";
		int c;
		string s;
		cin >> c >> s;
		int ans = 0;
		int tot = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (tot < i && s[i]!='0')
			{
				ans += i - tot;
				tot = i;
			}
			tot += s[i] - 48;
		}
		cout << ans << endl;
	}

}
