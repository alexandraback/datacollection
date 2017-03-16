#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>

#define SZ 100006
#define INF (1<<29)
using namespace std;

int r,c,w;

int dp[12][(1<<10)][(1<<10)][2];
int vis[12][(1<<10)][(1<<10)][2] , True;



int back(int pos,int hit,int miss,int t)
{
	if(vis[pos][hit][miss][t] == True)  return dp[pos][hit][miss][t];
	vis[pos][hit][miss][t] = True;
	if(t==0)
		dp[pos][hit][miss][t] = 0;
	else dp[pos][hit][miss][t] = INF;

	if(__builtin_popcount(hit) == w) {
		//cout<<"here\n";
		dp[pos][hit][miss][t] = 0;
		return 0;
	}

	if(t==0) {
		int ret = 0;
		for(int i=0;i<c;i++) {
			if(i+w>c) break;
			int cur = (((1<<(i+w))-1) ^ ((1<<(i))-1) );
			//printf("%d\n",i);
			if( ((cur & hit) == hit )&& (cur & miss) == 0 ) {
				int nhit = hit;
				int nmiss = miss;
				if( (1<<pos) & cur) nhit = (nhit | (1<<pos));
				else nmiss = (nmiss | (1<<pos));
				ret = max(ret, back(pos,nhit,nmiss,1));
			}
		}
		dp[pos][hit][miss][t] = ret;
		return ret;
	}
	else {
		int ret = INF;
		
		for(int i=0;i<c;i++) {
			if( ((1<<i) & hit) || ((1<<i)&miss) ) continue;
			if(i==pos) continue;
			ret = min(ret , 1 + back(i,hit,miss,0));
		}
		dp[pos][hit][miss][t] = ret;
		return ret;
	}

}


int main()
{
	freopen("Asm.txt","rt",stdin);
	freopen("Aan2.txt","wt",stdout);
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		True++;
		scanf("%d%d%d",&r,&c,&w);
		int mn = INF;
		for(int i=0;i<c;i++) {
			mn = min(mn, 1 + back(i,0,0,0));
		}

		printf("Case #%d: %d\n",cas,mn);


	}
	return 0;
}