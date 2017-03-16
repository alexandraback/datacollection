#include <cstdio>
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
#define RI(X) X=Readint()
#define RII(X,Y) RI(X),RI(Y)
#define RIII(X,Y,Z) RI(X),RI(Y),RI(Z)
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

inline int Readint()
{
	int ret=0;
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
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

const int MAXS = 222;

char str[MAXS];
int dp[MAXS][2];
int n;

void work()
{
	RS(str+1);
	n=strlen(str+1);
	MS(dp,0x3f);
	dp[0][0]=dp[0][1]=0;
	REP(i,1,n)
	{
		int kd=(str[i]=='+');
		REPD(j,i,1)
		if (str[i]==str[j])
		{
			dp[i][kd]=min(dp[i][kd],dp[j-1][kd]);
			dp[i][kd]=min(dp[i][kd],dp[j-1][kd^1]+1);
			dp[i][kd^1]=min(dp[i][kd^1],dp[j-1][kd]+1);
			dp[i][kd^1]=min(dp[i][kd^1],dp[j-1][kd^1]+2);
		}
		else
			break;
	}
	printf("%d\n",dp[n][1]);
}

int main()
{
	open();
	int _=0;
	RI(_);
	REP(__,1,_) printf("Case #%d: ",__),work();
	close();
	return 0;
}

