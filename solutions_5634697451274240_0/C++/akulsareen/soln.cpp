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
		string x;
		cin>>x;
		int ctr = 1;
		for (int i = 1; i < x.size(); ++i)
			if(x[i] != x[i-1])
				ctr++;
		int ans = ctr-1;
		if((ctr%2 == 1 && x[0] == '-') || (ctr%2 == 0 && x[0] == '+'))
			ans++;
		cout<<"Case #"<<cn<<": "<<ans<<"\n";
	}
	return 0;
}
