#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

long long a[1000001],b[1000001],c[1000001];
long long T,n,i,j,k,st,num,l,ans,p;
string s;
bool flag;

int main()
{
    freopen("A-large.in","r",stdin);
	freopen("stdout.txt","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s>>num;
		l=s.length();
		ans=0; b[l+1]=0; c[l+1]=0;
		for (j=0;j<s.length();j++)
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') a[j+1]=0; else a[j+1]=1;
		for (j=l;j>=1;j--)
			if (a[j]==0) b[j]=0; else b[j]=b[j+1]+1;
		k=1; j=1;
		for (j=1;j<=l;j++)
		{
			if(k<j) k=j;
			while (k<=l&&b[k]<num)k++;
			if (k>l) break;
			p=k+num-1; ans+=l-p+1;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}
