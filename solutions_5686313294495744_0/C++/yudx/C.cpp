#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cplx;

#define sqr(x) ((x)*(x))
#define pb push_back
#define X first
#define Y second
#define sit(a) set<a>::iterator
#define mit(a,b) map<a,b>::iterator

const ll mod=1000000007LL;
const int inf=0x3f3f3f3f;
const int maxn=100005,maxm=1005;
const double eps=1e-10;
const double pi=acos(-1.0);

typedef pair<int,int> pa;

int T,ca,n;
pa a[maxn];

char c[4005][25];
vector<string> v[2];

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(ca=1;ca<=T;ca++)
	{
		scanf("%d",&n);
		v[0].clear();v[1].clear();
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%s",c+(2*i));
			v[0].pb(c[2*i]);
			scanf("%s",c+(2*i+1));
			v[1].pb(c[2*i+1]);
		}
		printf("Case #%d: ",ca);
		for(i=0;i<2;i++)
		{
			sort(v[i].begin(),v[i].end());
			v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		}
		for(i=0;i<n;i++)
		{
			a[i].X=lower_bound(v[0].begin(),v[0].end(),string(c[2*i]))-v[0].begin();
			a[i].Y=lower_bound(v[1].begin(),v[1].end(),string(c[2*i+1]))-v[1].begin();
		}
		int r=0;
		for(i=0;i<(1<<n);i++)
		{
			bool ve[2][20]={0};
			for(j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					ve[0][a[j].X]=1;
					ve[1][a[j].Y]=1;
				}
			}
			int ntt=0;
			for(j=0;j<n;j++)
			{
				if(!(i>>j&1))
				{
					ntt+=(ve[0][a[j].X]&&ve[1][a[j].Y]);
				}
			}
			r=max(r,ntt);
		}
		printf("%d\n",r);
	}
        return 0;
}
