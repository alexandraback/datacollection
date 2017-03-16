#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<deque>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stack>
#include<queue>
#include<sstream>

#define MODM 1000000007
#define MAXM 2147483647
#define MAXML 9223372036854775807LL
#define Pi 3.14159265358979323846264338327950288419716939937510582
#define EPS 1e-10

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define L(x) x.length()
#define B(x) x.begin()
#define E(x) x.end()
#define F(x) x.front()
#define SZ(x) x.size()
#define CLR(x) x.clear()
#define SORT(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define S(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x);
#define SD(x) scanf("%lf",&x);
#define SC(x) scanf("%c",&x);
#define SS(x) scanf("%s",x);
#define DUM() scanf("%c",&dum);
#define READ(x) freopen(x,"r",stdin);
#define WRITE(x) freopen(x,"w",stdout);
#define FILL(x,y) memset(x,y,sizeof(x))
#define IT iterator

using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector< P > VP;
typedef vector< VP > VVP;
typedef vector<string> VS;
typedef vector< VS> VVS;
typedef map<int,int> MAP;

lli gcd(lli a,lli b){if(a==0)return(b);else return(gcd(b%a,a));}
lli fastpow(lli a,lli n,lli temp){if(n==0) return(1);if(n==1)return((a*temp)%MODM); if(n&1)temp=(temp*a)%MODM;return(fastpow((a*a)%MODM,n/2,temp));}
char dum;

int main()
{
	WRITE("output.txt");
	READ("read.txt");
	int t,rx[4],ro[4],cx[4],co[4],rt[4],ct[4],Case=1;
	char a[4][4];
	bool owin,xwin,notcmplt;
	S(t);
	DUM();
	while(t--)
	{
		owin=xwin=notcmplt=false;
		FILL(rx,0),FILL(ro,0),FILL(cx,0),FILL(co,0),FILL(rt,0),FILL(ct,0);
		FOR(i,0,4)
		{
			FOR(j,0,4)
			SC(a[i][j]);
			DUM();
		}
		DUM();
		FOR(i,0,4)
		{
			FOR(j,0,4)
			{
				if(a[i][j]=='X')
				rx[i]++,cx[j]++;
				else if(a[i][j]=='O')
				ro[i]++,co[j]++;
				else if(a[i][j]=='.')
				notcmplt=true;
				else if(a[i][j]=='T')
				rt[i]=true,ct[j]=true;
			}
		}
		FOR(i,0,4)
		{
			if(rx[i]==4 or (rx[i]==3 and rt[i]))
			xwin=true;
			if(ro[i]==4 or (ro[i]==3 and rt[i]))
			owin=true;
		}
		FOR(j,0,4)
		{
			if(cx[j]==4 or (cx[j]==3 and ct[j]))
			xwin=true;
			if(co[j]==4 or (co[j]==3 and ct[j]))
			owin=true;
		}
		int xcnt=0,ocnt=0;
		bool tpres=false;
		for(int i=0,j=0;i<4;i++,j++)
		{
			if(a[i][j]=='X')
			xcnt++;
			else if(a[i][j]=='O')
			ocnt++;
			else if(a[i][j]=='T')
			tpres=true;
		}
		if(xcnt==4 or (xcnt==3 and tpres==true))
		xwin=true;
		if(ocnt==4 or (ocnt==3 and tpres==true))
		owin=true;
		
		xcnt=0,ocnt=0,tpres=false;
		for(int i=0,j=3;i<4;i++,j--)
		{
			if(a[i][j]=='X')
			xcnt++;
			else if(a[i][j]=='O')
			ocnt++;
			else if(a[i][j]=='T')
			tpres=true;
		}
		if(xcnt==4 or (xcnt==3 and tpres==true))
		xwin=true;
		if(ocnt==4 or (ocnt==3 and tpres==true))
		owin=true;
		
		printf("Case #%d: ",Case++);
		if(!xwin and !owin)
		{
			if(notcmplt)
			printf("Game has not completed\n");
			else printf("Draw\n");
		}
		else if(xwin==true)
		printf("X won\n");
		else if(owin)
		printf("O won\n");
	}
	return(0);
}
