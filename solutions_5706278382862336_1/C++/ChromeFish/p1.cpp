#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

ifstream in("a.in");
ofstream out("a.out");
long long q, p;
long long a[60];
string st;

long long gcd(long long a, long long b)
{
	return (b==0)?a:gcd(b, a % b);
}

int main()
{
	int t, j;
	a[0]=1;
	for (int i=1; i<60; i++)
		a[i]=a[i-1]*2;
	in>>t;
	for (int i=1; i<=t; i++)
	{
		p=0;
		q=0;
		in>>st;
		j=0;
		while (st[j]!='/')
		{
			p=p*10+(st[j]-'0');
			j++;
		}
		j++;
		while (j<st.length())
		{
			q=q*10+(st[j]-'0');
			j++;
		}
		long long d=gcd(p,q);
		p/=d;q/=d;
		bool flag=0;
		int lnp=0, lnq=0;
		for (int k=0; k<60; k++)
		{
			if ((a[k]>p) && (lnp==0))
			{
				lnp=k;
			}
			if (a[k]==q)
			{
				lnq=k+1;
				flag=1;
				break;
			}
		}
			
		out<<"Case #"<<i<<": ";
		if (!flag || (lnp>lnq))
			out<<"impossible"<<endl;
		else
			out<<lnq-lnp<<endl;
		
	}
}