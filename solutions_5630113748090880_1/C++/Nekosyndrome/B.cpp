#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int t,n,cnt[2505];
vector<int> ans;
int main()
{
	int x;
	RI(t);
	REP(tt,1,t)
	{
		RI(n);
		MSET(cnt,0);
		ans.clear();
		REP(i,1,2*n-1)
		{
			REP(j,1,n)
			{
				RI(x);
				cnt[x]++;
			}
		}

		REP(i,0,2500) if(cnt[i]&1) ans.PB(i);

		assert(ans.SZ == n);
		printf("Case #%d:",tt);
		FOR(i,ans) printf(" %d",*i);
		puts("");
	}
	return 0;
}

