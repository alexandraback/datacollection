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
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

char s[2222]={0};
int n;
int cnt[300];
char num[20][20]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ord[]={0,4,5,7,6,3,8,2,9,1};

vi out;

void init()
{
	RS(s+1);
	n=strlen(s+1);
	REP(i,1,n)
		cnt[s[i]]++;

	out.clear();

	int mn;
	REP(o,0,9)
	{
		mn=1000;
		REP(l,0,strlen(num[ord[o]])-1)
			mn=min(mn,cnt[num[ord[o]][l]]);
		REP(k,1,mn) out.pb(ord[o]);
		REP(l,0,strlen(num[ord[o]])-1)
			cnt[num[ord[o]][l]]-=mn;
	}
	sort(out.begin(),out.end());
	REP(i,0,out.size()-1) printf("%d",out[i]);
	printf("\n");
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
	}
	close();
	return 0;
}

