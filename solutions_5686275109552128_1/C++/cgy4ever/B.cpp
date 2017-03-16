#include <bits/stdc++.h>
using namespace std;

vector <int> lis;

vector <int> solveNext(vector <int> lis)
{
	int a = lis[0] / 2;
	int b = lis[0] - a;
	vector <int> ret;
	ret.push_back(a);
	ret.push_back(b);
	for(int i = 1; i < lis.size(); i++)
		ret.push_back(lis[i]);
	sort(ret.begin(), ret.end());
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve()
{
	int n;
	cin >> n;
	lis.clear();
	for(int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		lis.push_back(t);
	}
	sort(lis.begin(), lis.end());
	reverse(lis.begin(), lis.end());
	int ret = 1000000;
	for(int i = 1; i <= 1000; i++)
	{
		int cur = i;
		for(int j = 0; j < lis.size(); j++)
		{
			cur += lis[j] / i + (lis[j] % i > 0) - 1;
		}
		ret = min(ret, cur);
	}

	cout << ret << endl;
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
