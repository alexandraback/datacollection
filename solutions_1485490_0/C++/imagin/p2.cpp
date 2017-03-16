#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> VVII;
typedef vector<VI> VVI;

#define INF 2000000000
#define INFLL (1LL<<62)
#define FI first
#define SE second
#define PB push_back
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define SSF getint()
#define SSLF getlint()
#define _mp make_pair

template<class T>
inline void _min(T &a,T b)
{
	if(a>b)
		a=b;
}

template<class T>
inline void _max(T &a,T b)
{
	if(a<b)
		a=b;
}

/********************* FAST IO *********************************/

// comment this line for only +ve numbers input in int and lints [slightly more efficient :P]
#define NEGATIVE

#define BUFSIZE (10000)

char inputbuffer[BUFSIZE];
char *ioptr=inputbuffer+BUFSIZE,*ioend=inputbuffer+BUFSIZE;
int input_eof=0;

#define getchar() ({if (ioptr >= ioend) init_input(); *ioptr++;})
#define eof() (ioptr>=ioend && input_eof)
#define eoln() ({if(ioptr >= ioend) init_input(); *ioptr == '\n';})

void init_input()
{
	if (input_eof)
		return;
	int existing = BUFSIZE - (ioend - inputbuffer);
	memcpy(inputbuffer, ioend, existing);
	int wanted = ioend - inputbuffer;
	int count=fread(inputbuffer + existing, 1, wanted, stdin);
	if (count < wanted)
		input_eof = 1;
	ioend = inputbuffer + BUFSIZE - (wanted - count);
	while (*--ioend > ' ');
	ioend++;
	ioptr=inputbuffer;
}
inline void non_whitespace()
{
	for(;;)
	{
		if(ioptr>=ioend)
			init_input();
		if(*ioptr>' ')
			return;
		ioptr++;
	}
}
inline int getint()
{
	non_whitespace();
	
	#ifdef NEGATIVE
	int neg=0;
	if(*ioptr=='-')
	{
		ioptr++;
		neg=1;
	}
	#endif
	
	int n=0;
	while(*ioptr>' ')
		n=(n<<3)+(n<<1)+*ioptr++-'0';
	ioptr++;
	
	#ifdef NEGATIVE
	if(neg)
		n=-n;
	#endif	
	return n;
}
inline LL getlint()
{
	non_whitespace();
	
	#ifdef NEGATIVE
	int neg=0;
	if(*ioptr=='-')
	{
		ioptr++;
		neg=1;
	}
	#endif
	
	LL n=0;
	while(*ioptr>' ')
		n=(n<<3)+(n<<1)+*ioptr++-'0';
	ioptr++;

	#ifdef NEGATIVE
	if(neg)
		n=-n;
	#endif	

	return n;
}

//******************************** programme code starts here*************************//
int n,m,A[200],B[200];
LL a[200],b[200],dp[200][200];
LL solve(int p,int q);
LL _try(int A[],LL a[],int B[],LL b[],int p,int q,LL rem,int rev)
{
	//cout<<"skjdfgfd"<<p<<" "<<q<<"\n";
	int nn=rev?m:n;
	for(++p;p<=nn;p++)
	{
	//	cout<<"dsfuh"<<p<<"\n";
		if(A[p]==B[q])
		{
			if(a[p]==rem)
			{
//				cout<<"h1"<<p<<"\n";
				return a[p]+(rev?solve(q+1,p+1):solve(p+1,q+1));
			}
			if(a[p]<rem)
			{
		//		cout<<"h2\n";
				return a[p]+_try(A,a,B,b,p,q,rem-a[p],rev);
			}
			if(a[p]>rem)
			{
		//		cout<<"h3 "<<p<<"\n";
				return rem+_try(B,b,A,a,q,p,a[p]-rem,1-rev);
			}
		}
	}
	return 0;
}

LL solve(int p,int q)
{
	//printf("inf\n");
	if(p>n || q>m)
		return 0;

	LL &ret=dp[p][q];
	if(ret!=-1)
		return ret;
	
	ret=max(solve(p+1,q),solve(p,q+1));
	
	LL p1=0,p2=0,p3=0;
	
	if(A[p]==B[q])
	{
		LL cur=min(a[p],b[q]);
		//cout<<cur<<" "<<p<<" "<<q<<" "<<"\n";
		
		if(a[p]<b[q])
			p1=_try(A,a,B,b,p,q,b[q]-a[p],0);

		if(a[p]>b[q])
			p2=_try(B,b,A,a,q,p,a[p]-b[q],1);
		
		p3=solve(p+1,q+1);
		
		//cout<<"hh "<<p1<<" "<<p2<<" "<<p3<<"\n";
		ret=max(ret,cur+max(p1,max(p2,p3)));
	}
	//printf("dp[%d][%d]=%lld\n",p,q,ret);
	return ret;
}
int main()
{
	int i,j,k,t,l;
	t=SS;
	for(l=1;l<=t;l++)
	{
		n=SS;
		m=SS;
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			a[i]=SSL;
			A[i]=SS;
		}
		for(i=1;i<=m;i++)
		{
			b[i]=SSL;
			B[i]=SS;
		}
		printf("Case #%d: %lld\n",l,solve(1,1));
	}
	return 0;
}
