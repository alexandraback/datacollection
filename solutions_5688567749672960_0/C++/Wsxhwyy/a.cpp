#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;
ofstream fout("a.out");

int dp[1000001];
queue<int> q;
int inq[1000001];
int step = 1;

int main()
{
	dp[0] = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		dp[i] = 1000001;
		inq[i] = 0;
	}
	q.push(0);
	inq[0] = 1;
	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		inq[i] = 0;
		if (dp[i] > step)
		{
			cout << step << endl;
			step = dp[i];
		}
		if (dp[i + 1] > dp[i] + 1)
		{
			dp[i + 1] = dp[i] + 1;
			if (!inq[i + 1])
			{
				q.push(i + 1);
				inq[i + 1] = 1;
			}
		}
		ostringstream ost;
		ost << i;
		string s = ost.str();
		sort(s.begin(), s.end());
		do
		{
			int now;
			istringstream ist(s);
			ist >> now;
			if (now >= 0 && now <= 1000000)
			{
				if (dp[now] > dp[i] + 1)
				{
					dp[now] = dp[i] + 1;
					if (!inq[now])
					{
						q.push(now);
						inq[now] = 1;
					}
				}
			}
		} while (std::next_permutation(s.begin(), s.end()));
	}
	int N,T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		fout << "Case #" << t << ": " << dp[N] << endl;
	}
}