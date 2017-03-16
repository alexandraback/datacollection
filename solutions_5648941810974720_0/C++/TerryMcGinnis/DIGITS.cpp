#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sz(a) int((a).size())
#define N 2010
#define MAX 30
#define mod 1000000007
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
const ll INF = 1e18+1;

inline ll input(void)
{
	char t;
	ll x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
	while(t>=48 && t<=57)
	{
		x=(x<<3)+(x<<1)+t-48;
		t=getchar();
	}
	if (neg) x=-x;
	return x;
}

inline void output(ll x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

char s[N];

int main()
{
	ll t,n,pres[26],num[10];
	t=input();
	REP(kase,t)
	{
		scanf("%s",s);
		FILL(pres,0);
		n=strlen(s);
		REP(i,n) pres[s[i]-'A']++; 
		num[0]=pres['Z'-'A'];
		num[2]=pres['W'-'A'];
		num[4]=pres['U'-'A'];
		num[6]=pres['X'-'A'];
		num[8]=pres['G'-'A'];
		num[5]=pres['F'-'A']-num[4];
		num[7]=pres['V'-'A']-num[5];
		num[1]=pres['O'-'A']-num[0]-num[2]-num[4];
		num[9]=(pres['N'-'A']-num[7]-num[1])/2;
		num[3]=pres['R'-'A']-num[0]-num[4];
		printf("Case #%d: ",kase+1);
		REP(i,10)
			REP(j,num[i]) putchar('0'+i);
		putchar('\n');
	}
return 0;
}
