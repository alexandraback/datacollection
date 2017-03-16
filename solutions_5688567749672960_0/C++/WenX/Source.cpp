#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <set>
using namespace std;

int ct[1000009];
int last[1000009];
long long rev(long long i)
{
	long long k = 0;
	while (i != 0)
	{
		k = k * 10 + i % 10;
		i /= 10;
	}
	return k;
}
int main()
{
	memset(ct, 0, sizeof(ct));
	ct[1] = 1;
	last[1] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		if (ct[i + 1] == 0 || ct[i + 1] > ct[i] + 1)
		{
			ct[i + 1] = ct[i]+1;
			last[i + 1] = i;
		}
		int r = rev(i);
		if (ct[r] == 0 || ct[r] > ct[i] + 1)
		{
			ct[r] = ct[i]+1;
			last[r] = i;
		}
	}

	int tt;
	cin >> tt;
	for (int cc = 1,k; cc <= tt; cc++)
	{
		cin >> k;
		cout << "Case #" << cc << ": " << ct[k] << endl;
	}
	return 0;
}