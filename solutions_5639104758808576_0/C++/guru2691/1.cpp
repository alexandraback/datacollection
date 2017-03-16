#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int idx=1;idx<=T;idx++)
	{
		int L;
		cin>>L;
		string S;
		cin>>S;
		int A[1100];
		int ans = 0;
		memset(A,0,sizeof A);
		for(int i=0;i<=L;i++)
		{
			if(i!=0)
			{
				if(A[i-1]>=i)
				{
					A[i] = A[i-1] + (S[i]-'0');
				}
				else
				{
					ans += i-A[i-1];
					A[i] = i + (S[i]-'0');
				}
			}
			else
			A[i] = (S[i]-'0');
		}
		cout<<"Case #"<<idx<<": "<<ans<<'\n';
	}
	return 0;
}
