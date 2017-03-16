#include <algorithm>
#include <fstream>

using namespace std;

const int maxn=100;

int c[maxn];
int t1,t2,ans,cur,a,now,n,i,j;

ifstream fin("a.in");
ofstream fout("a.out");

int main()
{
	fin>>t1;
	for(t2=1;t2<=t1;t2++)
	{
		fin>>a>>n;
		for(i=0;i<n;i++)
			fin>>c[i];
		sort(c,c+n);

		fout<<"Case #"<<t2<<": ";
		if (a==1)
			fout<<n;
		else
		{
			ans=n;
			for(i=0;i<n;i++)
			{
				now=a;
				cur=n-1-i;
				for(j=0;j<=i;j++)
				{
					while(now<=c[j])
					{
						now=now*2-1;
						cur++;
					}
					now+=c[j];
				}
				if (ans>cur)
					ans=cur;
			}
			fout<<ans;
		}
		fout<<endl;
	}

	return 0;
}