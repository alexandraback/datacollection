#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)
#define DFOR(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define S(n) scanf("%d",&n)
#define SLL(n) scanf("%lld",&n)
#define SD(n) scanf("%lf",&n)
#define SS(n) scanf("%s",n)
#define P(n) printf("%d\n",n)
#define PLL(n) printf("%lld\n",n)
#define PD(n) printf("%lf\n",n)
#define PS(n) printf("%s\n",n)
#define eps 1e-9
#define inf 1e9
#define PB push_back
#define PF push_front

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VLL;
typedef vector <double> VD;
typedef vector <string> VS;
typedef list <int> LI;
typedef list <LL> LLL;
typedef list <string> LS;
typedef list <double> LD;

int main()
{
	int T,x,y;
	string ans;
	S(T);
	REP(loop,1,T)
	{
		ans="";
		S(x);S(y);
		if(x>0)
		{
			while(x)
			{
				ans=ans+"WE";
				x--;
			}
		}
		else
		{
			while(x<0)
			{
				ans=ans+"EW";
				x++;
			}
		}
		if(y>0)
		{
			while(y)
			{
				ans=ans+"SN";
				y--;
			}
		}
		else
		{
			while(y<0)
			{
				ans=ans+"NS";
				y++;
			}
		}
		cout<<"Case #"<<loop<<": "<<ans<<endl;
	}
	return 0;
}