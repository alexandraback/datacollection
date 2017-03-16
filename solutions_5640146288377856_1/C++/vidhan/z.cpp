#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, r, c, w,i;
	cin >> t;
	for (i=1; i<=t; i++)
	{
		int res = 0;
		cin>>r>>c>>w;
		res = c / w *r;
		res += w - 1;
		if (c%w != 0)
			res++;
		cout<<"Case #"<<i<<": "<<res<<"\n";
	}

	return 0;
}
