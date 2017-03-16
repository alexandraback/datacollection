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
	int a[5][5],i,j,dr[200];
	a[1][1]=1,a[1][2]=2,a[1][3]=3,a[1][4]=4;
	a[2][1]=2,a[2][2]=-1,a[2][3]=4,a[2][4]=-3;
	a[3][1]=3,a[3][2]=-4,a[3][3]=-1,a[3][4]=2;
	a[4][1]=4,a[4][2]=3,a[4][3]=-2,a[4][4]=-1;
	dr['i']=2,dr['j']=3,dr['k']=4;
	ll x;
	int t,l,ind;
	char s[10005];
	short a1[10005];
	short a2[10005];
	getint(t);
	rep(ind,1,t)
	{
		int tr=1;
		getint(l);
		getlong(x);
		scanf("%s",s);
		int mul=1,neg=1,len=strlen(s),pos1=x*len,pos2=-1;
		rep(j,0,x-1)
		{
			rep(i,0,len-1)
			{
				mul=a[mul][dr[s[i]]];
				a1[i+j*len]=mul*neg;
				if(a1[i+j*len]==2)
					pos1=min(pos1,j*len+i);
				if(mul<0)
				{
					mul*=-1;
					neg*=-1;
				}
			}
		}
		mul*=neg;
		if(mul!=-1)
			tr=0;
		// cout<<mul<<endl;
		mul=1,neg=1;
		for(j=x-1;j>=0;j--)
		{
			for(i=len-1;i>=0;i--)
			{
				mul=a[mul][dr[s[i]]];
				a2[i+j*len]=mul*neg;
				if(a2[i+j*len]==-4||(a2[i+j*len]==4&&i==(len-1)&&j==(x-1)))
				{
					pos2=j*len+i;
					break;
				}
				if(mul<0)
				{
					mul*=-1;
					neg*=-1;
				}
			}
			if(pos2!=-1)
				break;
		}
		// cout<<pos1<<" "<<pos2<<endl;
		if(pos1>=pos2)
			tr=0;
		if(tr==1)
			printf("Case #%d: YES\n",ind);
		else
			printf("Case #%d: NO\n",ind);
	}
}