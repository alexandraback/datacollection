#include<iostream>
#include<string>
#include<cstring>

using namespace std;
long long T;
int main()
{
	freopen("A1.in","r",stdin);
	freopen("A1.out","w",stdout);
	long long a[101];
	string s;
	long long n;
	long long i,j,k,st,num,l,ans;
	bool flag;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ans=0;
		memset(a,0,sizeof(a));
		cin>>s>>num;
		l=s.length();
		for (j=0;j<s.length();j++)
		{
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
			{
				a[j+1]=a[j];
			}else a[j+1]=a[j]+1;
		}
		for (k=num;k<=l;k++)
		{
		
			for (j=1;j<=k;j++)
			{	
				flag=false;
				if (k-j+1<num) continue;
				for (st=j+num-1;st<=k;st++)
				{
					if (a[st]-a[st-num]>=num) {flag=true;
					break;
					}
				}
				if (flag) ans++;
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}
