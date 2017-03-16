#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

#define REP(I,A,B) for(int I=A,_END_=B;I<=_END_;I++)
#define REPD(I,A,B) for(int I=A,_END_=B;I>=_END_;I--)
#define RI(X) scanf("%d",&X)
#define RII(X,Y) RI(X),RI(Y)
#define RIII(X,Y,Z) RI(X),RI(Y),RI(Z)
#define RL(X) X=Readint()
#define RLL(X,Y) RL(X),RL(Y)
#define RLLL(X,Y,Z) RL(X),RL(Y),RL(Z)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define pb(X) push_back(X)
#define mp(A,B) make_pair(A,B)
#define fr first
#define sc second
#define lch(p) (p+p)
#define rch(p) (p+p+1)
#define lowbit(X) ((X)&(-(X)))

using namespace std;

typedef pair<int,int> poi;
typedef vector<int> vi;

inline long long Readint()
{
	long long ret=0;
	int f=1;
	char ch;
	do
	{
		ch=GCH;
		if (ch=='-') f*=-1;
	}while(ch>=0 && (ch<'0' || ch>'9'));

	while ('0'<=ch && ch<='9')
	{
		ret=ret*10+ch-'0';
		ch=GCH;
	}
	return ret*f;
}

void open()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

const int MAXN = 2020;
const int inf =1e9;
const int MAXS = 2020;

int tot;
int to[MAXN*10];
int nxt[MAXN*10];
int f[MAXN*10];
int hd[MAXN*2];

int src,snk;

int lst[MAXN*2];

map<string,int> S,T;
poi L[MAXN];
int n;

inline void add(const int &x,const int &y,const int &fl)
{
	tot++;
	to[tot]=y;
	nxt[tot]=hd[x];
	f[tot]=fl;
	hd[x]=tot;
}

int dis[MAXS+1];
int que[MAXS+1];

int spfa()
{
	int L=0,R=0;
	int now;
	que[R++]=src;
	MS(dis,0);
	dis[src]=1;

	while (L<R)
	{
		now=que[L];
		L++;
		for (int i=hd[now];i!=-1;i=nxt[i])
			if (f[i])
			{
				if (!dis[to[i]])
				{
					dis[to[i]]=dis[now]+1;
					que[R++]=to[i];
				}
			}
	}

	return dis[snk];
}

long long dfs(int p,int flow)
{
	int ret=0,tmp;
	if (p==snk) return flow;
	for (int i=hd[p];i!=-1;i=nxt[i])
		if (f[i] && dis[p]+1==dis[to[i]])
		{
			tmp=dfs(to[i],min(flow-ret,f[i]));
			f[i]-=tmp;
			f[i^1]+=tmp;
			ret+=tmp;
			if (ret==flow) return ret;
		}
	if (!ret) dis[p]=0;
	return ret;
}

int maxflow(){
	int ret=0;
	while (spfa())
		ret+=dfs(src,inf);
	return ret;
}

void init()
{
	tot=-1;
	MS(hd,-1);
	S.clear();
	T.clear();
	string A,B;
	int x,y;
	RI(n);
	REP(i,1,n)
	{
		cin >> A >> B;
		if (S.count(A)==0)
		{
			S[A]=S.size();
		}
		x=S[A];

		if (T.count(B)==0)
		{
			T[B]=T.size();
		}
		y=T[B];
		L[i]=mp(x,y);
	}

	src=0;
	snk=S.size()+T.size()+1;
	REP(i,1,S.size()) add(src,i,1),add(i,src,0);
	REP(i,S.size()+1,S.size()+T.size()) add(i,snk,1),add(snk,i,0);
	REP(i,1,n)
		add(L[i].fr,L[i].sc+S.size(),1),
		add(L[i].sc+S.size(),L[i].fr,0);
}

int main()
{
	open();
	int _=0;
	RI(_);
	REP(__,1,_)
	{
		printf("Case #%d: ",__);
		init();
		printf("%d\n",n-S.size()-T.size()+maxflow());
	}
	close();
	return 0;
}
