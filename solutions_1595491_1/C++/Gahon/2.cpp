#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define maxn 1000
int cmp(const void* a,const void* b)
{
	return *(int*)a<*(int*)b;
}
int main()
{
	int ans,p,i,tt,t,s,n,g[maxn];
	ifstream in("B-large.in");
	ofstream out("B-large.out");
	in>>t;
	for (tt=1;tt<=t;tt++)
	{
		ans=0;
		in>>n>>s>>p;
		for (i=0;i<n;i++)
			in>>g[i];
		qsort(g,n,sizeof(g[0]),cmp);
		for (i=0;i<n;i++)
		{
			if (g[i]%3==0&&g[i]/3>=p)
			{
				ans++;continue;
			}
			if (g[i]%3!=0&&g[i]/3+1>=p)
			{
				ans++;continue;
			}
			if (s>0&&g[i]!=0)
			{
				if (g[i]%3==2&&g[i]/3+2>=p)
				{
					ans++;s--;continue;
				}
				if (g[i]/3+1>=p)
				{
					ans++;s--;continue;
				}
			}
		}
		out<<"Case #"<<tt<<": "<<ans<<endl;
	}
	in.close();
	out.close();
}