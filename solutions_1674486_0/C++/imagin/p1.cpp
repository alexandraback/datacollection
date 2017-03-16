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
char G[1010][1010];
int main()
{
	int i,j,k,n,t,m,tt;
	t=SS;
	for(tt=1;tt<=t;tt++)
	{
		n=SS;
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				G[i][j]=0;
		
		for(i=1;i<=n;i++)
		{
			m=SS;
			for(j=0;j<m;j++)
			{
				k=SS;
				G[i][k]=1;
			}
		}
		
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)	
					G[i][j]=G[i][j]+min(G[i][k],G[k][j]);
		bool done=false;
		for(i=1;i<=n && !done;i++)
			for(j=1;j<=n && !done;j++)
			if(j!=i && G[i][j]>=2)
			{
				printf("Case #%d: Yes\n",tt);
				done=true;
				break;
			}
		if(!done)
		{
			printf("Case #%d: No\n",tt);
		}
	}
	return 0;
}
