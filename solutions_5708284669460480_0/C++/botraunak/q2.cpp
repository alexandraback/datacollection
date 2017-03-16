#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
#define sz 10000000
#define ull unsigned long long
string key;
string target;
int maximum,tot,k,l,s;
int arr[10000000]={0};
char per[1000000];
void permute(int i)
{
	if(i>=s)
	{
		tot++;
		int match=0;
		for(int keyi=0;keyi<(s-l+1);keyi++)
		{
			int f=1;
			for(int stot=0;(stot+keyi)<(s) && (stot<l) ;stot++)
			{
				if(per[stot+keyi]!=target[stot])
				{
					f=0;
				}
			}
			if(f==1)
			{
				match++;
			}
		}
		arr[tot-1]=match;
		if(maximum<match)
		{
			maximum=match;
		}
	}
	else
	{
		for(int x=0;x<k;x++)
		{
			per[i]=key[x];
			permute(i+1);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		cin>>k>>l>>s;
		cin>>key;
		cin>>target;
		maximum=0;
		tot=0;
		permute(0);
		float ans=0;
		for(int i=0;i<tot;i++)
		{
			ans+=(maximum-arr[i]);
		}
		ans/=((double)(tot));
		printf("%0.7f",ans);
		cout<<endl;
	}
	return 0;
}