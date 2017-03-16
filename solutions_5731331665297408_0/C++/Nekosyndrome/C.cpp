#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 55
using namespace std;
typedef long long LL;
typedef pair<int, pair<int,int> > P; //weight, from, to
int t,n,m,in[M][M],w[M],fa[M],st;
bool done[M],edg[M][M];
bool chk_vis[M],edg2[M][M];
set<P> s;
queue<int> q;

bool check(int cur,int from,int to)
{
	/////////////////////
	memcpy(edg2,edg,sizeof(edg));
	while(cur != from)
	{
		if( edg2[cur][fa[cur]] )
			return false;

		edg2[cur][fa[cur]]=true;
		cur=fa[cur];
	}


	MSET(chk_vis,false);
	chk_vis[to]=true;
	fa[to]=from;//////////////////

	q.push(to);
	chk_vis[to]=true;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		REP(i,1,n)if(!chk_vis[i] && in[cur][i])
			if(!done[i] || ( fa[cur]==i && !edg2[cur][i] ))
			{
				chk_vis[i] = true;
				q.push(i);
			}
	}

	REP(i,1,n)
		if(!done[i] && !chk_vis[i])
			return false;
	return true;
}
int main()
{
	int x,y;
	
	scanf("%d",&t);
	REP(tt,1,t)
	{
		s.clear();
		MSET(in,0);
		MSET(fa,0);
		MSET(edg,false);
		MSET(done,false);
		printf("Case #%d: ",tt);

		st=1;
		scanf("%d %d",&n,&m);
		REP(i,1,n)
		{
			scanf("%d",&w[i]);
			if(w[i]<w[st])st=i;
		}
		REP(i,1,m)
		{
			scanf("%d %d",&x,&y);
			in[x][y]=in[y][x]=1;
		}

		int cnt=0, cur=st;
		while(1)
		{
			if(done[cur])
			{
				puts("QAQ");
				puts("QAQ");
				puts("QAQ");
				break;
			}
			cnt++;
			done[cur]=true;
			printf("%d",w[cur]);
			if(cnt == n)break;

			REP(i,1,n)if(!done[i] && in[cur][i])
				s.insert(MP(w[i], MP(cur,i) ));

			for(set<P>::iterator i=s.begin(); i!=s.end(); )
			{
				set<P>::iterator nxt = i;
				nxt++;
				
				if(done[i->S.S])s.erase(i);
				i = nxt;
			}

			FOR(i,s)
			{
				if(done[i->S.S])continue;
				
				if( check(cur, i->S.F, i->S.S) )
				{
					fa[i->S.S] = i->S.F;
					cur = i->S.S;

					//
					memcpy(edg, edg2, sizeof(edg2));
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}

