#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

struct ss{ long long c,v; }tmp;
multiset<ss> s;
long long E,R,v[101000];
int n,T;

bool operator <(ss a,ss b){ return a.v<b.v; }

int main()
{
	freopen("b.in","r",stdin);
	scanf("%d",&T);
	int TT=0;
	while (T--)
	{
		scanf("%I64d%I64d%d",&E,&R,&n);
		for (int i=1;i<=n;i++) scanf("%d",&v[i]);
		tmp.v=0;tmp.c=E;
		s.clear();s.insert(tmp);
		long long ans=0;
		for (int i=1;i<=n;i++)
		{
			long long cnt=0;
			while (!s.empty())
			{
				set<ss>::iterator tt=s.begin();
				if (tt->v>v[i]) break;
				cnt+=tt->c;
				s.erase(tt);
			}
			tmp.c=cnt;tmp.v=v[i];
			s.insert(tmp);
			tmp.c=R;tmp.v=0;
			s.insert(tmp);
			cnt=0;
			set<ss>::iterator tt=s.end();
			tt--;
			for (;cnt<R;)
			{
				tt=s.end();tt--;
				if (tt->c+cnt>R)
				{
					tmp.c=tt->c+cnt-R;
					tmp.v=tt->v;
					ans+=(R-cnt)*tt->v;
					s.erase(tt);
					s.insert(tmp);
					break;
				}else
				{
					cnt+=tt->c;
					ans+=tt->c*tt->v;
					s.erase(tt);
				}
			}
		}
		for (set<ss>::iterator tt=s.begin();tt!=s.end();tt++) 
		{
			ans+=tt->c*tt->v;
		}
		printf("Case #%d: %I64d\n",++TT,ans);
	}
	return 0;
}