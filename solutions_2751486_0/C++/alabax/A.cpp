#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef long long ll;

char buf[1000006];

int cnt1[1000000];
bool good1[1000000];

int cnt[1000000];
bool good[1000000];

int behind[1000000];

int n;
int len;

bool vovel(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

ll calc(int pre, int l, int rest)
{
	ll com = l-n+1;

	ll beg = pre * com;

	ll mid = com*(com+1)/2;

	ll end = rest * com;

	ll oth = ((ll)pre) * rest;

	return beg + mid + end + oth;
}

ll solve()
{
	int k = 0;

	cnt1[k] = 0;

	good1[k] = false;

	for (char *p=buf; *p; ++p)
	{
		bool vov = vovel(*p);

		if (vov == good1[k])
		{
			++cnt1[k];
		}
		else
		{
			++k;
			cnt1[k] = 1;
			good1[k] = vov;
		}
	}

	int m = 0;

	for (int i=0; i<=k; ++i)
	{
		if (i == 0 || (i==1 && cnt1[i]==0))
		{
			cnt[m] = cnt1[i];
			good[m] = good1[i];
		}
		else
		{
			if (good1[i] == good[m] || (good1[i]==false && cnt1[i]<n) || (good[m]==false && cnt[m]<n))
			{
				cnt[m] += cnt1[i];
				good[m] = true;
			}
			else
			{
				++m;
				cnt[m] = cnt1[i];
				good[m] = good1[i];
			}
		}
	}

	behind[m] = 0;

	for (int i=m-1; i>=0; --i)
	{
		behind[i] = behind[i+1] + cnt[i+1];
	}

	ll sum = 0;

	for (int i=0; i<=m; ++i)
	{
		if (!good[i])
		{
			int pre = 0;
			if (i > 0)
			{
				pre += cnt[i-1];
			}
			if (i-1 > 0)
			{
				pre += n-1;
			}

			ll c = calc(pre, cnt[i], behind[i]);

			sum += c;
		}
	}

	//for (int i=0;i<=m;++i)
	//{
	//	cout << cnt[i] << " .. " << good[i] << " .. " << behind[i] << endl;
	//}

	return sum;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	for (int i=0; i<t; ++i)
	{
		cin >> buf;

		len = strlen(buf);

		cin >> n;

		ll result = solve();

		cout << "Case #" << i+1 << ": " << result << endl;
	}

	return 0;
}