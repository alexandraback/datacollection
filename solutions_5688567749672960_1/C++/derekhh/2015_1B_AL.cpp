//A. Counter Culture

#include<iostream>
using namespace std;

int len(long long num)
{
	if (num == 0) return 1;
	int ret = 0;
	while (num) num /= 10, ret++;
	return ret;
}

long long rev(long long num)
{
	long long ret = 0;
	while (num)
	{
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		long long n, curr = 0, target;
		cin >> n;
		int finalLen = len(n), ans = 0;
		while (curr != n)
		{
			//cout << curr << " " << n << endl;
			int currentLen = len(curr);
			if (currentLen < finalLen)
			{
				target = 1;
				for (int i = 0; i < currentLen; i++)
					target = target * 10;
			}
			else
				target = n;

			// if target is abcd0, then we cannot use 100ba to flip to ab001
			bool flag = false;
			if (target % 10 == 0) flag = true, target--;
			int d[20], nd = 0;
			long long tmp = target;
			while (tmp)
			{
				d[nd++] = tmp % 10;
				tmp /= 10;
			}
			int e[20];
			memcpy(e, d, sizeof(d));
			e[0] = 1;
			for (int i = 1; i < nd / 2; i++)
				e[i] = 0;
			/*
			for (int i = 0; i < nd; i++)
				cout << e[i];
			cout << endl;
			*/
			tmp = 0;
			for (int i = 0; i < nd; i++)
				tmp = tmp * 10 + e[i];
			ans += tmp - curr;
			bool reved = false;
			if (rev(tmp) > tmp)
				ans++, reved = true;
			if (reved)
				ans += target - rev(tmp);
			else
				ans += target - tmp;
			curr = target;
			if (flag)
				ans++, curr++;
		}
		cout << "Case #" << ++kase << ": " << ans << endl;
	}
	return 0;
}