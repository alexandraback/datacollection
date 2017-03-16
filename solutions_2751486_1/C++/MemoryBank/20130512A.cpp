#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const long long maxn=1000000+2;

long long a[maxn],b[maxn],f[maxn];
long long t1,t2,n,i,j,k,l,c,x,ans,pre;
char ch;

ifstream fin("a.in");
ofstream fout("a.out");


int main()
{
	fin>>t1;
	for(t2=1;t2<=t1;t2++)
	{
		l=0;
		pre=-1;
		ans=0;
		fin.get(ch);
		a[0]=-1;
		x=1;
		while(fin.get(ch) && ch!=' ')
		{
			if ((ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u'))
			    a[x++]=l;
			l++;
		}
		fin>>n;
		a[x++]=l;
		for(i=0;i<x-1;i++)
			b[i]=a[i+1]-a[i]-1;
		for(i=0;i<x-1;i++)
		{
			ans+=b[i]*(pre+1);
			if (i!=x-2)
				ans+=(pre+1);
			if (b[i]>=n)
			{
				ans+=(b[i]-n+1)*(a[i]-pre+1);
				ans+=(b[i]-n+1)*(b[i]-n)/2;
				if (i!=x-2)
				{
					ans+=a[i]-pre+1;
					ans+=b[i]-n;
				}
				pre=a[i+1]-n;
			}
		}

		fout<<"Case #"<<t2<<": "<<ans<<endl;
	}

	return 0;
}