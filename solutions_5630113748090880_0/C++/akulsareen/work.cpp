#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;
int ctr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for (int tc = 1; tc <= t; ++tc)
	{
		int n;
		cin>>n;
		memset(ctr, 0, sizeof ctr);
		for (int i = 1; i < 2*n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x;
				cin>>x;
				ctr[x]++;
			}
		}
		cout<<"Case #"<<tc<<": ";
		for (int i = 1; i < MAXN; ++i)
			if(ctr[i]%2)
				cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
