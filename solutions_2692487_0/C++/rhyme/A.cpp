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
#define SL(x) scanf("%lld",&x)
#define SD(x) scanf("%lf",&x)
#define SC(x) scanf("%1s",&x)
#define SS(x) scanf("%s",x)
#define DUM() scanf("%c",&dum)
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define FILL(x,y) memset(x,y,sizeof(x))
#define IT iterator
#define CASE printf("Case #%d: ",Case++)

using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
typedef long double ld;
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
int Case=1;
int main()
{
	#ifndef ONLINE_JUDGE
	READ("read.txt");
	WRITE("output.txt");
	#endif
	
	int t,a[1000],am,n,ans;
	S(t);
	while(t--)
	{
		ans=MAXM;
		S(am),S(n);
		FOR(i,0,n)
		S(a[i]);
		if(am==1)
		{
			CASE;
			printf("%d\n",n);
			continue;
		}
		int lt=pow(2,n),temp;
		VI v;
		FOR(i,0,lt)
		{
			int op=0,val=am;
			CLR(v);
			FOR(j,0,n)
			{
				if(i&(1<<j))
				v.pb(a[j]);
				else op++;
			}
			SORT(v);
			
			FOR(j,0,SZ(v))
			{
				if(val>v[j])
				val+=v[j];
				else 
				{
					while(val<=v[j])
					{
						val+=(val-1);
						op++;
					}
					val+=v[j];
				}
			}
			ans=min(op,ans);
		}
		CASE;
		printf("%d\n",ans);
	}
	return(0);
}
