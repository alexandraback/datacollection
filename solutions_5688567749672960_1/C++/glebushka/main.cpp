#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long f[50];
long long P[50];
long long K[50];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	long long pp = 0;
	P[0] = 1;
	for (int i = 1; i <= 15; i++)
	{
		P[i] = P[i - 1] * 10;
	}
	f[0] = 1;
	f[1] = 10;
	for (int i = 1; i <= 20; i++)
	{
		K[i] = K[i - 1] * 10 + 9;
	}
	for (int i = 2; i <= 20; i++)
	{
		f[i] = f[i - 1] + K[(i) / 2] + K[(i + 1) / 2] + 1;
	}

	for (int i = 1; i <= t; i++)
	{
		long long n, n1;
		long long ans = 0;
		string s;
		cin >> n;
		if (n % 10 == 0)
		{
			n--;
			ans++;
		}
		long long tmp = n;
		long long pp = 0;
		while (tmp != 0)
		{
			s.push_back(tmp % 10 + '0');
			tmp /= 10;
		}
		reverse(s.begin(), s.end());
		ans += f[(int)s.size() - 1];
		long long ans1 = ans;
		int cnt = ((int)s.size() + 1)/ 2;
		int cur = 0;
		bool tt = false;
		for (int j = (int)s.size() - 1; j >= 0; j--)
		{
			if (cur >= cnt && !tt)
			{
				cur = j;
				tt = true;
			}
			ans += P[cur] * (s[j] - '0');
			if (!tt)
			{
				cur++;
			}
			else
			{
				cur--;
			}
		}
		cout << "Case #" << i << ": " << min(ans, ans1 + n - P[(int)s.size() - 1]) << endl;
	}


	return 0;
}