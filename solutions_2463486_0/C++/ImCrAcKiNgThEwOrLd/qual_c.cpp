#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXN = 10000500;

bool good[MAXN];
int cnt[MAXN];

bool is_pal(__int64 nmb, char * buf)
{
	sprintf(buf, "%I64d", nmb);
	int n = strlen(buf);
	for (int i = 0; i < n / 2; ++i)
		if (buf[i] != buf[n - 1 - i])
			return false;
	return true;
}

int sqrt_ge(__int64 nmb)
{
	__int64 s = sqrt(nmb + .0);
	for (int i = -1; i <= 2; ++i)
		if ((s + i) * (s + i) >= nmb)
			return s + i;
}

int sqrt_le(__int64 nmb)
{
	__int64 s = sqrt(nmb + .0);
	for (int i = 2; i >= -1; --i)
		if ((s + i) * (s + i) <= nmb)
			return s + i;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; 
	char s[20];
	for (__int64 i = 1; i <= MAXN; ++i)
	{
		good[i] = (is_pal(i, s) && is_pal(i * i, s));
		cnt[i] = cnt[i - 1] + good[i];
	}
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		__int64 a, b;
		cin >> a >> b;
		int a1 = sqrt_ge(a), b1 = sqrt_le(b);
		cout << cnt[b1] - cnt[a1 - 1] << endl;
	}
}