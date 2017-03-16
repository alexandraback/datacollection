/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int main()
{
	int t,i,j,k,cs,css,n,ans;
	string s;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>n>>s;
		ans=0;
		k=0;
		for(i=0;i<s.sz;i++)
		{
			if(s[i]-'0'>0)
			{
				if(k<i)
				{
					ans+=(i-k);
					k=i;
				}
				k+=(s[i]-'0');
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
