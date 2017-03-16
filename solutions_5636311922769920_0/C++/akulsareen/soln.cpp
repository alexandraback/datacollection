#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for (int cn = 1; cn <= t; ++cn)
	{
		int k,c,s;
		cin>>k>>c>>s;
		cout<<"Case #"<<cn<<": ";
		if(s*c >= k)
		{
			long long int num = 0;
			set <long long int> S;
			for (int i = 1; i <= s*c; ++i)
			{
				num = num*k + (i%k);
				if(i%c == 0)
				{
					S.insert(num+1ll);
					num = 0;
				}
			}
			for (set<long long int>::iterator it = S.begin(); it != S.end(); ++it)
				cout<<*it<<" ";
			cout<<"\n";
		}
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
