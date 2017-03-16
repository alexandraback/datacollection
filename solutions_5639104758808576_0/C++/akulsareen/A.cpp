#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("a_small.in", "r", stdin);
	freopen("a_small.out", "w", stdout);
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int s_max;
		cin>>s_max;
		string A;
		cin>>A;
		int ans=0,curr=0;
		for (int i = 0; i < A.size(); ++i)
		{
			if(curr < i)
			{
				ans+=(i-curr);
				curr=i;
			}
			curr+=((int)(A[i]-'0'));
		}
		cout<<"Case #"<<case_num<<": "<<ans<<"\n";
	}
	return 0;
}