#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t,ind,r,x,c;
	getint(t);
	rep(ind,1,t)
	{
		printf("Case #%d: ",ind);
		getint(x);
		getint(r);
		getint(c);
		int win=0;
		if(x==1)
			win=1;
		else if(x==2)
		{
			if((r*c)%2==0)
				win=1;
		}
		else if(x==3)
		{
			if((r*c)%3==0)
			{
				if(min(r,c)>1)
					win=1;
			}
		}
		else
		{
			if((r*c)%4==0)
			{
				if(min(r,c)>2)
					win=1;
			}
		}
		if(win==1)
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
	}
}