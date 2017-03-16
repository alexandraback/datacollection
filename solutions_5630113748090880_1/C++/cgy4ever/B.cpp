#include <bits/stdc++.h>
using namespace std;

int cnt[2501];

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	int n;
	cin >> n;
	for(int i = 1; i <= 2*n-1; i++)
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			cnt[x] ++;
		}
	for(int i = 0; i <= 2500; i++)
		if(cnt[i] % 2 == 1)
			cout << " " << i;
	cout << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ":";
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
		//cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
