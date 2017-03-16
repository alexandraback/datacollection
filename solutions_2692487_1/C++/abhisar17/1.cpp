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
int a,n;
int A[1000009];
int ans;
LL solve(LL ms,int pos)
{
	if(pos == n-1)
	{
		if(ms > A[pos])
			return 0;
		else
			return 1;
	}

	if(ms > A[pos])
		return solve(ms+A[pos],pos+1);
	else
	{
		int a = 0;
		do
		{
			ms += ms-1;
			a++;
		}while(ms<=A[pos]);
		return MIN( (n-pos) , a + solve(ms+A[pos],pos+1) );
	}
}
int main()
{
	int t,cs = 0;
	cin>>t;
	while(t--)
	{
		cs++;
		cin>>a>>n;
		REP(i,n)
			cin>>A[i];
		cout<<"Case #"<<cs<<": ";
		sort(A,A+n);
		ans = INF;
		if(a == 1)
		{
			cout<<n<<endl;
		}
		else
		{
			cout<<solve(a,0)<<endl;
		}
	}
	return 0;
}
