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

const int MAXN = 20;
const int MAXS= 70000;

string s[MAXN];
string t[MAXN];

vi now[MAXN][MAXN];

bool ys[MAXN][MAXN];
bool yt[MAXN][MAXN];
int f[MAXS];
int n;
int all;

int hamming_weight(int x){
	int ret=0;
	while (x)
	{
		x-=lowbit(x);
		ret++;
	}
	return ret;
}

void prepare()
{
	REP(n,1,16)
	{
		all=(1<<n)-1;
		REP(s,0,all)
		{
			now[n][hamming_weight(s)].pb(s);
		}
	}
}

void init()
{
	MS(f,0);
	MS(ys,false);
	MS(yt,false);

	RI(n);
	all=(1<<n)-1;

	REP(i,1,n)
		cin >> s[i] >> t[i];
	
	REP(i,1,n)
	REP(j,1,n)
	{
		if (s[i]==s[j]) ys[i][j]=true;
		if (t[i]==t[j]) yt[i][j]=true;
	}
}

void work()
{
	int s;
	int tt;

	REP(len,0,n-1)
	{
		REP(v,0,now[n][len].size()-1)
		{
			s=now[n][len][v];
			REP(i,1,n)
			if ( ( (s>>(i-1))&1 )==0)
			{
				tt=0;

				REP(j,1,n)
				if ( (s>>(j-1))&1 )
				{
					if (ys[i][j])
						tt|=1;
					if (yt[i][j])
						tt|=2;
				}

				if (tt==3)
					f[s|(1<<(i-1))]=max( f[s|(1<<(i-1))],f[s]+1 );
			}
		}
	}

	printf("%d\n",f[all]);
}

int main()
{
	open();
	int _=0;
	prepare();
	RI(_);
	REP(__,1,_)
	{
		printf("Case #%d: ",__);
		init();
		work();
	}
	close();
	return 0;
}


