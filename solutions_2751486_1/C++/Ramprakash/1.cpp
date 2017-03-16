#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
char c[1000001];
int a[1000001];
int main()
{
	int t,n,i,k,j;
	ifstream f("1.in");
	ofstream g("1.out");
	unsigned long long int s=0;
	f>>t;
	for(k=1;k<=t;k++)
	{
		f>>c>>n;
		s=0;
		a[0]=strlen(c);
		i=0;
		if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u') a[1]=0;
		else a[1]=1;
		for(i=1;i<a[0];i++)
			if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u') a[i+1]=0;
			else a[i+1]=a[i]+1;
		for(i=1;i<=a[0];i++)
		{
			if(a[i]>=n)break;
		}
		a[1]=i;
		for(i=2;i<=a[0];i++)
		{
			if((a[i-1]-n+1)>=i) a[i]=a[i-1];
			else
			{
				for(j=i+n-1;j<=a[0];j++)
				if(a[j]>=n)break;
				a[i]=j;
			}
		}
		for(i=1;i<=a[0];i++)
		{if(a[i]<=a[0])s+=(a[0]+1-a[i]);}
		g<<"Case #"<<k<<": "<<s<<endl;
	}
	return 0;
}
