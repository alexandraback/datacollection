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
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

int n;
bool hs[10]={0};

int mx;

void work(){
	long long cry;
	RI(n);
	MS(hs,false);
	REP(i,1,200)
	{
		cry=i*1ll*n;
		while (cry)
		{
			hs[cry%10]=true;
			cry/=10;
		}
		int cnt=0;
		REP(dig,0,9) cnt+=hs[dig];
		if (cnt==10)
		{
			printf("%lld\n",i*1ll*n);
			mx=max(mx,i);
			return ;
		}
	}
	printf("INSOMNIA\n");
}

int main()
{
	open();
	int _=0;
	RI(_);
	REP(__,1,_) printf("Case #%d: ",__),work();
	debug("%d\n",mx);
	close();
	return 0;
}

