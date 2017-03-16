#include<iostream>
#include<cstdio>
using namespace std;
int s;
char s1[1005];
int main()
{
	freopen ("input.in","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin>>t;
	int k=0;
	while(t--)
	{
		k++;
		cin>>s;
		cin>>s1;
		int stand=0,ans=0;
		for(int i=0;i<=s;i++)
		{
			if(stand<i)
			{
				ans=ans+i-stand;
				stand=stand+i-stand;
			}
			stand=stand+s1[i]-'0';
		}
		cout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}