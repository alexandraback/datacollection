#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long LL;
#define VI vector<int>
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A,0,sizeof(A))
#define MSV(A,a) memset(A,a,sizeof(A))
#define MAX(a,b) ((a>=b)?(a):(b))
#define MIN(a,b) ((a>=b)?(b):(a))
#define II pair<int,int>
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A,x) (A.find(x)!=A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define DEB(n) cout<<"(<<< DEBUG "<<n<<" >>>)"<<endl;
//int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
//int dx[] = {1,1,1,0,0,-1,-1,-1}, dy[] = {1,0,-1,1,-1,1,0,-1};
inline void inp( int &n )
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
		n=n*sign;
}
bool ispalin(LL a)
{
	LL rev = 0;
	LL temp = a;
	while(temp)
	{
		rev = rev*10 + temp%10;
		temp/=10;
	}
	return a == rev;
}
vector<LL> fns;
int roots[] = {1,10,100,1000,10000,100000,1000000};
double limits[3];
int main()
{
	limits[0] = sqrtl(2);
	limits[1] = sqrtl(5);
	limits[2] = sqrtl(10);
	REP(i,7)	// iterate over roots
	{
		REP(j,3)
		{
			int s = roots[i] * (j+1);
			int limit = roots[i] * limits[j];
			FOR(k,s,limit+1)
			{
				if(ispalin(k))
				{
					LL sq = LL(k)*k;
					if(ispalin(sq))
					{
						fns.PB(sq);
					}
				}
			}
		}
	}
	int t;
	LL l,r;
	cin>>t;
	REP(tc,t)
	{
		cin>>l>>r;
		int ans = upper_bound( fns.begin() , fns.end() , r) - lower_bound(fns.begin() , fns.end(), l) ;
		printf("Case #%d: %d\n",tc+1,ans);
	}
	return 0;
}
