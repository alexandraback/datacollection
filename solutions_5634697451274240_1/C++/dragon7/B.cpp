#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int a[1000];

int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		string s;
		cin>>s;
		int n = s.size();
		for(int i=1;i<=n;i++)
		{
			a[i]=(s[i-1]=='+');
		}
		int presSum = 0,ans=0;
		for(int i=n ;i >0;i--)
		{
			if(a[i]==0)
			{
				if(presSum == 0)
				{
					presSum = 1;
					ans++;
				}
			}
			else 
			{
				if(presSum == 1)
				{
					presSum = 0;
					ans++;
				}
			}
		}
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
}
