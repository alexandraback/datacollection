#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MAXD 110
pair<ll,ll> toys[MAXD]; //X of type Y
pair<ll,ll> boxes[MAXD]; //X of type Y
ll memo[MAXD][MAXD];
int N, M, T;

ll recur ( ll boxn, ll toyn, ll rbox, ll rtoy )
{
	if ( boxn >= N || toyn >= M ) return 0;
	
	if ( boxes[boxn].second == toys[toyn].second )
	{
		ll boxcnt = boxes[boxn].first - rbox;
		ll toycnt = toys[toyn].first - rtoy;
		
		if ( boxcnt >= toycnt )
		{
			return toycnt + recur(boxn,toyn+1,rbox+toycnt,0);
		}
		
		else
		{
			return boxcnt + recur(boxn+1,toyn,0,rtoy+boxcnt);
		}
	}
	
	else
	{
		return max(recur(boxn+1,toyn,0,rtoy), recur(boxn,toyn+1,rbox,0));
	}
}

int main ()
{
	scanf("%d",&T);
	int i, j;
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		scanf("%d %d",&N,&M);
		
		for ( i = 0; i < N; i++ )
		{
			scanf("%lld %lld",&boxes[i].first,&boxes[i].second);
		}
		
		for ( i = 0; i < M; i++ )
		{
			scanf("%lld %lld",&toys[i].first,&toys[i].second);
		}
		
		printf("Case #%d: %lld\n",cnt,recur(0,0,0,0));
	}
}