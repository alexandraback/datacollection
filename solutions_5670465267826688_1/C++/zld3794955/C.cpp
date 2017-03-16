#include<bits/stdc++.h>
using namespace std;
const int v[5][5]={ {0,0,0,0,0},
					{0,1,2,3,4},
					{0,2,-1,4,-3},
					{0,3,-4,-1,2},
					{0,4,3,-2,-1}};
inline int mul(int x,int y)
{
	int sign=1;
	if(x<0) sign=-sign,x=-x;
	if(y<0) sign=-sign,y=-y;
	return sign*v[x][y];
}
const int L=10010;
const long long Inf=1ll<<60;
int l,a[L]={},pres[L]={},sufs[L]={};
long long x;
char ch[L]={};
void init()
{
	cin>>l>>x;
	cin>>(ch+1);
	for(int i=1;i<=l;++i)
		switch(ch[i])
		{
			case '1' : a[i]=1; break;
			case 'i' : a[i]=2; break;
			case 'j' : a[i]=3; break;
			case 'k' : a[i]=4; break;
		}
	pres[0]=sufs[l+1]=1;
	for(int i=1;i<=l;++i)
		pres[i]=mul(pres[i-1],a[i]);
	for(int i=l;i>=1;--i)
		sufs[i]=mul(a[i],sufs[i+1]);
}
int power(int x,long long y)
{
	int t=1;
	while(y)
	{
		if(y&1)
			t=mul(t,x);
		x=mul(x,x);
		y>>=1;
	}
	return t;
}
bool check()
{
	int sum=power(pres[l],x);
	if(sum!=-1)
		return false;
	long long minpos=Inf,maxpos=0;
	for(int i=1;i<=l;++i)
	{
		int s=pres[i];
		for(long long j=0,k=i;j<min(4ll,x);++j,k+=l)
		{
			if(s==2)
				minpos=min(minpos,k);
			s=mul(pres[l],s);
		}
	}
	for(int i=l;i>=1;--i)
	{
		int s=sufs[i];
		for(long long j=0,k=(x-1)*l+i;j<min(4ll,x);++j,k-=l)
		{
			if(s==4)
				maxpos=max(maxpos,k);
			s=mul(s,sufs[l]);
		}
	}
	return minpos<maxpos;
}
int main()
{	
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		init();
		if(check())
			printf("Case #%d: YES\n",t);
		else
			printf("Case #%d: NO\n",t);
	}
	return 0;
}
