#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		string s;
		int n;
		cin>>s>>n;
		int l=s.length();
		int A[l],B[l];
		memset(A,0,sizeof(A));
		int i;
		for(i=0;i<l;i++)
		{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
				A[i]=0;
			else
				A[i]=1;
		}
		if(A[0]==1)
			B[0]=1;
		else
			B[0]=0;
		for(i=1;i<l;i++)
		{
			if(A[i]==1&&B[i-1]==n)
				B[i]=B[i-1];
			else if(A[i]==1)
				B[i]=B[i-1]+1;
			else
				B[i]=0;
		}
		ll ans=0;
		int last=0;
		for(i=0;i<l;i++)
		{
			if(B[i]==n)
			{
				ans+=((i-n+2-last)*(l-i));
				last=i-n+2;
			}
		}
		cout<<"Case #"<<u-t<<": "<<ans<<endl;
	}
}