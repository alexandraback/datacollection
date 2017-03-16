#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char buf[100];

bool isPal(long long x)
{
	sprintf(buf, "%lld", x);
	int len = strlen(buf);
	int l = len / 2;
	for (int i = 0; i < l; i++)
		if (buf[i] != buf[len - i - 1])
			return false;
	return true;
}

#define MAX 1e7

int main()
{
	vector<long long> fs;
	for (long long x = 1; x <= MAX; x++)
	{
		if (isPal(x))
		{
			long long y = x * x;
			if (isPal(y))
			{
				fs.push_back(y);
			}
		}
	}

	int t;
	cin >> t;
	for (int caseNum = 1; caseNum <= t; caseNum++)
	{
		long long a, b;
		cin >> a >> b;

		unsigned int ia, ib;
		for (ia = 0; ia < fs.size(); ia++)
		{
			if (fs[ia] >= a)
			{
				break;
			}
		}
		for (ib = 0; ib < fs.size(); ib++)
		{
			if (fs[ib] > b)
			{
				break;
			}
		}

		cout << "Case #" << caseNum << ": " << (ib - ia) << endl;
	}
	return 0;
}
