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
char str[20];
int palin(lli num)
{
	sprintf(str,"%lld",num);
	int ind=0,dig;
	while(num)
	{
		dig=num%10;
		if(dig!=(str[ind]-'0'))
		return(0);
		num/=10;
		ind++;
	}
	return(1);
}
int main()
{
	WRITE("output.txt");
	READ("read.txt");
	vector<lli>v;
	for(lli i=1;i<10000001;i++)
	{
		if(palin(i) and palin(i*i))
		v.pb(i*i);
	}
	
	int t,Case=1;
	S(t);
	lli a,b;
	while(t--)
	{
		SL(a);SL(b);
		printf("Case #%d: %d\n",Case++,(int)(upper_bound(B(v),E(v),b)-lower_bound(B(v),E(v),a)));
	}
	return(0);
}
