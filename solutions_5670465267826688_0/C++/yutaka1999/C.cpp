#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 10005

using namespace std;
typedef long long int ll;

struct P
{
	int c;
	bool sg;
	
	P(int c=1,bool sg=true):c(c),sg(sg){}//1
	void ins(char d)
	{
		sg=true;
		if(d=='i') c=2;
		else if(d=='j') c=3;
		else if(d=='k') c=4;
	}
	bool operator==(const P&l) const
	{
		return c==l.c&&sg==l.sg;
	}
	bool operator!=(const P&l) const
	{
		return c!=l.c||sg!=l.sg;
	}
};
//‚Ç‚ñ‚È‚Ì‚à4æ‚µ‚½‚ç1
P mul(P p,P q)
{
	if(!p.sg)
	{
		P r=P(p.c,!p.sg);
		P a=mul(r,q);
		a.sg=!a.sg;
		return a;
	}
	if(!q.sg)
	{
		P r=P(q.c,!q.sg);
		P a=mul(p,r);
		a.sg=!a.sg;
		return a;
	}
	if(p.c==1) return q;
	if(q.c==1) return p;
	if(p.c>q.c)
	{
		P a=mul(q,p);
		a.sg=!a.sg;
		return a;
	}
	if(p.c==q.c) return P(1,false);
	if(p.c==2)
	{
		if(q.c==3) return P(4,true);
		return P(3,false);
	}
	if(p.c==3) return P(2,true);
}
char str[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int L;
		ll X;
		scanf("%d %lld",&L,&X);
		scanf("%s",&str);
		P now;
		for(int i=0;i<L;i++)
		{
			P p;
			p.ins(str[i]);
			now=mul(now,p);
		}
		int tm=(int) (X%4);
		P all;
		while(tm--) all=mul(all,now);
		if(all!=P(1,false))
		{
			printf("Case #%d: NO\n",t);
			continue;
		}
		now=P();
		bool O=false,U=false;
		X=min(X,10LL);
		for(int i=0;i<L*(int) X;i++)
		{
			int pos=i%L;
			P p;p.ins(str[pos]);
			now=mul(now,p);
			if(now==P(2,true)) O=true;
			else if(now==P(4,true)&&O) U=true;
		}
		if(O&&U) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
	return 0;
}
