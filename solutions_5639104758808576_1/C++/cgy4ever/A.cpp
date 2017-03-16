#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int sum = 0;
	for(int i = 0; i <= n; i++)
	{
		if(s[i] > '0' && sum < i)
		{
			ans += i - sum;
			sum = i;
		}
		sum += s[i] - '0';
	}
	cout << ans << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
