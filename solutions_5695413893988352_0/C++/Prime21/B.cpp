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
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

int n;
char C[20];
char J[20];
char aC[20];
char aJ[20];
int ans;
int kd;

void init()
{
	RS(C+1);
	RS(J+1);
	n=strlen(C+1);
	kd=0;
}

void get()
{
	int nJ=0,nC=0;
	REP(i,1,n) nJ=nJ*10+J[i]-'0';
	REP(i,1,n) nC=nC*10+C[i]-'0';

	if (abs(nJ-nC)<ans)
	{
		ans=abs(nJ-nC);
		REP(i,1,n) aC[i]=C[i],aJ[i]=J[i];
	}
	else if (abs(nJ-nC)<ans)
	{
		int flag=0;
		REP(i,1,n)
		if (aC[i]>C[i]) { flag=1; break; }
		else if (aC[i]<C[i]) { flag=-1; break; }
		
		if (flag==0)
		REP(i,1,n)
		if (aJ[i]>J[i]) { flag=1; break; }
		else if (aJ[i]<J[i]) { flag=-1; break; }

		if (flag==1)
			REP(i,1,n) aC[i]=C[i],aJ[i]=J[i];
	}
}

void dfsj(int i)
{
	if (i>n)
	{
		get();
		return ;
	}
	if (J[i]=='?')
	{
		REP(ch,'0','9')
		{
			J[i]=ch;
			dfsj(i+1);
		}
		J[i]='?';
	}
	else
		dfsj(i+1);
}

void dfsc(int i)
{
	if (i>n)
	{
		dfsj(1);
		return ;
	}
	if (C[i]=='?')
	{
		REP(ch,'0','9')
		{
			C[i]=ch;
			dfsc(i+1);
		}
		C[i]='?';
	}
	else
		dfsc(i+1);
}

int main()
{
	open();
	int _=0;
	RI(_);
	REP(__,1,_)
	{
		printf("Case #%d: ",__);
		ans=1000000000;
		init();
		dfsc(1);
		aC[n+1]=aJ[n+1]=0;
		printf("%s %s\n",aC+1,aJ+1);
	}
	close();
	return 0;
}

