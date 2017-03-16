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
int val(int a,ll x)
{
	if(a==1)
		return 1;
	if(a==-1)
		if(x%2==0)
			return 1;
		else
			return -1;
	if(x%2==0)
	{
		if(x%4==0)
			return 1;
		else
			return -1;
	}
	else
	{
		if(x%4==1)
			return a;
		else
			return -a;
	}
}
int main()
{
	int a[5][5],i,j,dr[200];
	a[1][1]=1,a[1][2]=2,a[1][3]=3,a[1][4]=4;
	a[2][1]=2,a[2][2]=-1,a[2][3]=4,a[2][4]=-3;
	a[3][1]=3,a[3][2]=-4,a[3][3]=-1,a[3][4]=2;
	a[4][1]=4,a[4][2]=3,a[4][3]=-2,a[4][4]=-1;
	dr['i']=2,dr['j']=3,dr['k']=4;
	ll x;
	int t,l,ind;
	char s[10005];
	getint(t);
	rep(ind,1,t)
	{
		int tr=1;
		getint(l);
		getlong(x);
		scanf("%s",s);
		int mul=1,neg=1;
		ll pos1=x*l,pos2=-1,posneg1=x*l,posneg2=-1;
		rep(i,0,l-1)
		{
			mul=a[mul][dr[s[i]]];
			if(mul<0)
			{
				mul*=-1;
				neg*=-1;
			}
			int v=mul*neg;
			if(v==2)
				pos1=min(pos1,(ll)i);
			else if(v==-2)
				posneg1=min(posneg1,(ll)i);
			else if(v==4)
				pos2=i;
			else if(v==-4)
				posneg2=i;
		}
		int rmul=val(mul,x);
		int rneg=val(neg,x);
		mul*=neg;
		rmul*=rneg;
		// cerr<<rmul<<"\n";
		if(rmul!=-1)
			tr=0;
		else
		{
			int pd=1;
			if(mul!=-1)
				pd=2;
			if(pd==2)
			{
				mul=1,neg=1;
				pos1=x*l,pos2=-1,posneg1=x*l,posneg2=-1;
				rep(i,0,2*l-1)
				{
					mul=a[mul][dr[s[i%l]]];
					if(mul<0)
					{
						mul*=-1;
						neg*=-1;
					}
					int v=mul*neg;
					// cerr<<v<<endl;
					if(v==2)
						pos1=min(pos1,(ll)i);
					else if(v==-2)
						posneg1=min(posneg1,(ll)i);
					else if(v==4)
						pos2=i;
					else if(v==-4)
						posneg2=i;
				}
			}
		}
		pos1=min(pos1,posneg1+l);
		if(x%2==0)
		{
			if(pos2!=-1)
			pos2=pos2+(x-2)*l;
			if(posneg2!=-1)
			posneg2=posneg2+(x-1)*l;
		}
		else
		{
			if(pos2!=-1)
			pos2=pos2+(x-1)*l;
			if(x!=1&&posneg2!=-1)
				posneg2=posneg2+(x-2)*l;
		}
		pos2=max(pos2,posneg2);
		// cerr<<pos1<<" "<<pos2<<"\n";
		if(pos1>=pos2)
			tr=0;
		if(tr==1)
			printf("Case #%d: YES\n",ind);
		else
			printf("Case #%d: NO\n",ind);
	}
}