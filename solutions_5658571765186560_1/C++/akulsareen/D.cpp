#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("d_large.in", "r", stdin);
	freopen("d_large.out", "w", stdout);
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int x,r,c;
		cin>>x>>r>>c;
		bool ans=true;
		if(r > c)
			swap(r,c);
		if((r*c)%x)
			ans=false;
		for (int i = 1; i <= x; ++i)
		{
			int l=i,b=(x-i)+1;
			if(l<=r && b<=c)
				continue;
			if(l<=c && b<=r)
				continue;
			ans=false;
			break;
		}
		if(r == 2 && x >= 4)
			ans=false;
		if(r > 2 && x >= 7)
			ans=false;
		// cout<<x<<" "<<r<<" "<<c<<" ";
		if(ans)
			cout<<"Case #"<<case_num<<": GABRIEL\n";
		else
			cout<<"Case #"<<case_num<<": RICHARD\n";
	}
	return 0;
}