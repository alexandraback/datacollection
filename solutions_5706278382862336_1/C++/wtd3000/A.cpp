#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define LL long long
using namespace std;
LL x,y,d;
int ans,T,tot;
char ch;
inline bool P(LL G)
{	LL t=G;
	for (;t>1;t/=2) if (t%2) return 0; return 1;
}
inline LL gcd(LL a,LL b) { return (!b)?a:gcd(b,a%b); }
int main()
{	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	for (scanf("%d",&T),tot=1;tot<=T;tot++)
	{	printf("Case #%d: ",tot);
		scanf("%I64d%c%I64d",&x,&ch,&y);
		d=gcd(x,y);
		x/=d; y/=d;
		for (ans=0;P(y);)
		{	ans++;
			y/=2;
			if (x>=y) break;
			if (ans>40) break;
			}
		if (!P(y)||(ans>40)) { printf("impossible\n"); continue; }
		x-=y;
		if (x==0) { printf("%d\n",ans); continue; }
		d=gcd(x,y);
		x/=d; y/=d;
		if (!P(y)||(ans==40)) printf("impossible\n"); else
							printf("%d\n",ans);
		}
	return 0;
}
