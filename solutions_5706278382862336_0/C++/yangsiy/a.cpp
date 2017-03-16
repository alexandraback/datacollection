#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
ifstream cin("A-small-attempt0.in");
ofstream cout("out.txt");

long long a,b,ans;

long long bcd(long long a,long long b)
{
	long long c=a%b;
	while (c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

bool check(long long x)
{
	if (x==1) return false;
	while (x>0&&x%2==0)
	{
		x/=2;
	}
	if (x==1) return true;
	else return false;
}

bool work()
{
	if (!check(b)) return false;
	long long rtn=0;
	while (a<b)
	{
		rtn++;
		if (rtn>40) return false;
		a*=2;
	}
	ans=rtn;
	return true;
}

int main()
{
	long long t,i,j,k,count=0;
	char s[100];
	cin>>t;
	while (t--)
	{
		count++;
		cin>>s;
		a=0;
		b=0;
		i=0;
		while (s[i]!='/')
		{
			a=a*10+s[i]-'0';
			i++;
		}
		i++;
		while (i<strlen(s))
		{
			b=b*10+s[i]-'0';
			i++;
		}
		k=bcd(a,b);
		a/=k;
		b/=k;
		cout<<"Case #"<<count<<": ";
		if (!work())
			cout<<"impossible";
		else
			cout<<ans;
		cout<<endl;
	}
	return 0;
}