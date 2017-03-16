#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

int solve()
{
	int n;
	cin >> n;
	vector<string> v1(n), v2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i] >> v2[i];	
	}

	int ans = 0;
	

	for (int i = 0; i < (1<<n); i++)
	{
		int faked = 0;
		set<string> fw, sw;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				faked++;
			else
			{
				fw.insert(v1[j]);
				sw.insert(v2[j]);
			}
		}
		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				if (fw.find(v1[j]) == fw.end())
				{
					flag = false;
					break;
				}
				if (sw.find(v2[j]) == sw.end())
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)
			ans = max(faked, ans);
		
	}

	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int ans = solve();
		cout << "Case #" << i + 1 << ": " << ans << endl; 
		cerr << i << endl;
	}
	fprintf(stderr, "\n\n Execution time: %.4fs", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}

