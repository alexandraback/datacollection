#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

long long minAns;
pair<string, string> ans;

void solve(string s1, string s2, int idx, long long dif)
{
	if (idx == s1.length())
	{
		// cout << s1 << " - " << s2 << endl;
		if (abs(dif) == minAns)
			ans = min(ans, make_pair(s1, s2));
		if (abs(dif) < minAns)
		{
			ans = make_pair(s1, s2);
			minAns = abs(dif);
		}
		return;
	}
	dif *= 10;
	if (s1[idx] == '?')
	{
		if (s2[idx] == '?')
		{
			int minNum2 = 0, minNum1 = 0;
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
				{
					if (abs(dif + j - i) < abs(dif + minNum2 - minNum1))
					{
						minNum2 = j;
						minNum1 = i;
					}
					// cout << j << ", " << i << ": " << abs(dif + j - i) << endl;
				}
			s1[idx] = minNum1 + '0';
			s2[idx] = minNum2 + '0';
			solve(s1, s2, idx + 1, dif + minNum2 - minNum1);
			if (dif + minNum2 - minNum1 == 0)
			{
				minNum2++;
				s1[idx] = minNum1 + '0';
				s2[idx] = minNum2 + '0';
				solve(s1, s2, idx + 1, dif + minNum2 - minNum1);
				minNum2--;
				minNum1++;
				s1[idx] = minNum1 + '0';
				s2[idx] = minNum2 + '0';
				solve(s1, s2, idx + 1, dif + minNum2 - minNum1);
				// cout << "*" << idx << endl;
			}
		}
		else
		{
			int minNum = 0;
			for (int i = 0; i < 10; i++)
				if (abs(dif - i + (s2[idx] - '0')) < abs(dif - minNum + (s2[idx] - '0')))
					minNum = i;
			s1[idx] = minNum + '0';
			solve(s1, s2, idx + 1, dif - minNum + (s2[idx] - '0'));
			if (dif - minNum + (s2[idx] - '0') == 0)
			{
				if (minNum < 9)
				{
					minNum++;
					s1[idx] = minNum + '0';
					solve(s1, s2, idx + 1, dif - minNum + (s2[idx] - '0'));
					minNum--;
				}
				if (minNum > 0)
				{
					minNum--;
					s1[idx] = minNum + '0';
					solve(s1, s2, idx + 1, dif - minNum + (s2[idx] - '0'));
					minNum++;
				}
			}
		}
	}
	else
	{
		if (s2[idx] == '?')
		{
			int minNum = 0; 
			for (int i = 0; i < 10; i++)
				if (abs(dif + i - (s1[idx] - '0')) < abs(dif + minNum - (s1[idx] - '0')))
					minNum = i;
			s2[idx] = minNum + '0';
			solve(s1, s2, idx + 1, dif + minNum - (s1[idx] - '0'));
			if (dif + minNum - (s1[idx] - '0') == 0)
			{
				if (minNum < 9)
				{
					minNum++;
					s2[idx] = minNum + '0';
					solve(s1, s2, idx + 1, dif + minNum - (s1[idx] - '0'));
					minNum--;
				}
				if (minNum > 0)
				{
					minNum--;
					s2[idx] = minNum + '0';
					solve(s1, s2, idx + 1, dif + minNum - (s1[idx] - '0'));
					minNum++;
				}
			}
		}
		else
			solve(s1, s2, idx + 1, dif + (s2[idx] - s1[idx]));
	}
}

int t;
string s1, s2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> s1 >> s2;
		int len = s1.size();
		minAns = (ll)INF * (ll)INF;
		ans = make_pair(string(len, '9'), string(len, '9'));
		solve(s1, s2, 0, 0);
		cout << "Case #" << tt << ": ";
		cout << ans.first << " " << ans.second;
		cout << endl;
	}
	return 0;
}