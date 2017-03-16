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
int a[1005],n;
int main()
{
	int t,i,j,k,cs,css,ans;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		for(i=0;i<=1000;i++)a[i]=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>k;
			a[k]++;
		}
		ans=1000;
		for(i=1000;i>=1;i--)
		{
			k=0;
			for(j=1000;j>i;j--)
			{
				if(j%i==0)t=j/i-1;
				else t=j/i;

				k+=t*a[j];
			}
			k+=i;
			if(k<ans)ans=k;
		}
		cout<<ans<<endl;
	}
	return 0;
}
