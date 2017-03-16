#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
ifstream in("b.in");
ofstream out("b.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
const int N=10010;
long long v[N];
long long nowe[N], maxlev[N];
int vis[N];
int main()
{
	int T, i;
	long long j, k, p, n, r, e, ans;
	in>>T;
	fo(i, 1 ,T)
	{
		in>>e>>r>>n;
		fo(j, 1, n)
			in>>v[j];
		ans=0;
		nowe[0]=e;
		fo(j, 1, n)
		{
			nowe[j]=min(r,e);
			maxlev[j]=e;
			vis[j]=0;
		}
		fo(j, 1, n)
		{
			long long tmp=0;
			fo(k, 1, n)
				if (!vis[k])
					if (v[k]>tmp)
					{
						tmp=v[k];
						p=k;
					}
			vis[p]=1;
			tmp=0;
			for(k=p-1; k>=0; k--)
				if (tmp+nowe[k]>=maxlev[p])
				{
					nowe[k]=tmp+nowe[k]-maxlev[p];
					tmp=maxlev[p];
					break;
				}
				else
				{
					tmp+=nowe[k];
					nowe[k]=0;
					maxlev[k]=min((p-k)*r,maxlev[k]);
				}
			ans+=tmp*v[p];
		}
		out<<"Case #"<<i<<": "<<ans<<endl;
	}
	
}