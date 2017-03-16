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
int main()
{
	int t,x,R,C;
	cin>>t;
	string ans[2] = { "NO" , "YES" };
	REP(tc,t)
	{
		cin>>R>>C;
		vector< VI > cols(C,VI(R));
		vector< VI > matrix(R,VI(C));
		VI rowvals(R);
		VI colvals(C);
		REP(i,R)
			REP(j,C)
			{
				cin>>matrix[i][j];
				cols[j][i] = matrix[i][j];
			}
		REP(i,R)
			rowvals[i] = *max_element(matrix[i].begin(),matrix[i].end());
		REP(i,C)
			colvals[i] = *max_element(cols[i].begin(),cols[i].end());
		bool valid = 1;
		REP(i,R)
			REP(j,C)
				if( matrix[i][j] != MIN( rowvals[i] , colvals[j] ) )
				{
					valid=0;
					break;
				}
		cout<<"Case #"<<tc+1<<": "<<ans[valid]<<endl;
	}
	return 0;
}
