#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

long long n;

long long check()
{
	vector<bool> u(10, false);
	int cnt = 10;
	long long cur = 0, t1, t2;
	do
	{
		cur += n;
		t1 = cur;
		while (t1 > 0)
		{
			t2 = t1 % 10;
			t1 = t1 / 10;
			if (!u[t2])
			{
				u[t2] = true;
				cnt--;
			}
		}
	} while (cnt > 0);
	return cur;
}

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		long long res;
		cin >> n;
		cout << "Case #" << t << ": ";
		if (n == 0)
			cout << "INSOMNIA" << endl;
		else
			cout << check() << endl;
	}

    return 0;
}
