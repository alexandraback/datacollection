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
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

int k,c,s;

void work()
{
	RIII(k,c,s);
	REP(i,1,s) printf("%d ",i); printf("\n");
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


