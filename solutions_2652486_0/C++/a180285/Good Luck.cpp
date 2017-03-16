/*****************************************
USER: a180285
PROB: Good Luck
LANG: C++
2013,UESTC
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=32               ;
const int M=1               ;
const ll P=10000000097ll    ;

int n, m, k;
int v[N];
int ans[N];
int an;
const int p[4] = {2, 3, 5, 7};
const int pn = 4;
int num[N];

void read()
{
	for(int i=0; i<k; i++)
	{
		scanf("%d", &v[i]);
	}
}

void print(int cas)
{
	for(int i=0; i<an; i++)
		printf("%d", ans[i]);
	puts("");
}

void deal(int x)
{
	switch(x)
	{
	case 1:
		return ;
		break;
	case 2: case 3: case 5: case 7:
		for(int i=0; i<an; i++)
			if(ans[i] == x)
				return ;
		ans[an++] = x;
		return; 
		break;
	}
	
	for(int i=0; i<pn; i++)
	{
		int mx = 0;
		while(x % p[i] == 0)
		{
			x/=p[i];
			mx++;
		}
		checkmax(num[p[i]], mx);
	}
	
}

bool dfs(int left)
{
	bool has = false;
	for(int i=0; i<pn; i++)
		if( num[ p[i] ] )
			has = true;
	if(!has)
		return true;
	if(0==left && has)
		return false;
	left--;
	int x;
	x = 6;
	if(x<=m && num[2] && num[3])
	{
		num[2]--;
		num[3]--;
		if(dfs(left));
		{
			ans[an++] = x;
			return true;
		}
		num[2]++;
		num[3]++;
	}
	
	
	x = 8;
	if(x<=m && num[2]>=3)
	{
		num[2]-=3;
		if(dfs(left));
		{
			ans[an++] = x;
			return true;
		}
		num[2]+=3;
	}
	
	x = 4;
	if(x<=m && num[2]>=2)
	{
		num[2]-=2;
		if(dfs(left));
		{
			ans[an++] = x;
			return true;
		}
		num[2]+=2;
	}
	
	for(int i=0; i<pn; i++)
	{
		if( !num[ p[i] ] )
			continue;
		x = p[i];
		num[x]--;
		if(dfs(left));
		{
			ans[an++] = x;
			return true;
		}
		num[x]++;
	}
	
	return false;
}

void doit()
{
	an = 0;
	MEM(num);
	for(int i=0; i<k; i++)
		deal(v[i]);
	dfs(n - an);
	while(an < n)
		ans[an++] = 2;
}

int main()
{
#ifdef Hw
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	scanf("%d", &T);
	scanf("%d %d %d", &n, &m, &k);
	puts("Case #1:");
	for(int cas=1; cas<=T; cas++)
	{
		read();
		doit();
		print(cas);
	}
    return 0;
}

/**

1
2 3 4 4
9 4 36 1
1 1 1 1
Case #1:
343
222

**/