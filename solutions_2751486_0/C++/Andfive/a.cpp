#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int MAXN=1e6+5;
char m[MAXN];
bool p[MAXN];
vector<pair<int,int> > kk;

int main ()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int cas,len,n;
	scanf("%d",&cas);
	for(int ii=1;ii<=cas;++ii)
	{
		scanf("%s%d",m,&n);
		len=strlen(m);
		printf("Case #%d: ",ii);

		for(int i=0;i<len;++i)
			p[i]=!(m[i]=='a' || m[i]=='e' || m[i]=='i' || m[i]=='o' || m[i]=='u');

		kk.clear();
		int st=-1;
		for(int i=0;i<len;++i)
		{
			if(p[i] && st==-1)
				st=i;
			else if(!p[i] && st!=-1)
			{
				if(i-1-st+1>=n)
					kk.push_back(make_pair(st,i-1));
				st=-1;
			}
		}
		if(st!=-1 && len-1-st+1>=n)
			kk.push_back(make_pair(st,len-1));

		ll ans=0;
		for(int i=0;i<kk.size();++i)
		{
			for(int j=kk[i].first;j+n-1<=kk[i].second;++j)
			{
				if(j==kk[i].first)
				{
					ll tmp=len-1-(j+n-1)+1;
					if(i==0)
						ans+=tmp*(j+1);
					else
						ans+=tmp*(j-(kk[i-1].second-n+2)+1);
				}
				else
					ans+=len-1-(j+n-1)+1;
			}
		}

		printf("%lld\n",ans);
	}
	return 0;
}

