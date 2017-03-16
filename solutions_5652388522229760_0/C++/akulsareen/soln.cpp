#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
int ans[MAXN];
int f(int x)
{
	vector <bool> vis(10,false);
	int ctr = 0, val = 0;
	while(ctr < 10)
	{
		val+=x;
		int temp = val;
		while(temp)
		{
			if(!vis[temp%10])
				ctr++;
			vis[temp%10] = true;
			temp/=10;
		}
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i < MAXN; ++i)
		ans[i] = f(i);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int x;
		cin>>x;
		cout<<"Case #"<<case_num<<": ";
		if(x)
			cout<<ans[x]<<"\n";
		else
			cout<<"INSOMNIA\n";
	}
	return 0;
}
