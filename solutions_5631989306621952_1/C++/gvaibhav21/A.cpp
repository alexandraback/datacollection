#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
char s[1010];
char op[1010];
int main()
{
	//freopen("A_2.in","r",stdin);
	//freopen("A_2.out","w",stdout);

	int tt,t,i,l;
	sd(t);
	for(tt=1;tt<=t;tt++)
	{
		ss(s);
		l=strlen(s);
		int r=l-1,p1=0,p2=l-1;
		while(r>=0)
		{
			int maxx=-1,mpos;
			for(i=r;i>=0;--i)
			{
				if(s[i]-'A'>maxx)
				{
					maxx=s[i]-'A';
					mpos=i;
				}
			}
			for(i=r;i>mpos;--i)
			{
				op[p2]=s[i];
				p2--;
			}
			op[p1]=s[mpos];
			p1++;
			r=mpos-1;
		}
		op[l]='\0';
		printf("Case #%d: %s\n",tt,op);
	}
}