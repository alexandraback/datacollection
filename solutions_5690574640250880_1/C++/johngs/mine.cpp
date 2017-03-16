//Google Code Jam
//Round 2
//1 Jun 2013

//start of jonathanirvings' template v2.0.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
#include <assert.h>
jonathan ganteng banget;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[9] = {-1,0,0,1,-1,-1,1,1,0};
int diry[9] = {0,1,-1,0,-1,1,-1,1,0};

#ifdef TESTING
	#define DEBUG fprintf(stderr,"====TESTING====\n")
	#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define DEBUG 
	#define VALUE(x)
	#define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v2.0.0 (BETA)

#define MAXR 50
#define MAXC 50

int T,r,c,m;
int mine[MAXR+5][MAXC+5];
int isi[MAXR+5][MAXC+5];
bool sudah[MAXR+5][MAXC+5];
int ada, found;

void ddfs(int x,int y)
{
	if (sudah[x][y]) return;
	sudah[x][y] = 1;
	++ada;
	if (isi[x][y] == 0) REP(i,8)
	{
		int xx = x + dirx[i];
		int yy = y + diry[i];
		if (0 <= xx && xx < r && 0 <= yy && yy < c && isi[xx][yy] >= 0 && mine[xx][yy] == 0)
			ddfs(xx,yy);
	}
}

void print(void)
{
	REP(i,r)
	{
		REP(j,c) debug("%d",mine[i][j]);
		debug("\n");
	}
	debug("\n");
}

void printisi(void)
{
	REP(i,r)
	{
		REP(j,c) debug("%d",isi[i][j]);
		debug("\n");
	}
	debug("\n");
}

void dfs(int x,int rem, int prev)
{
	//debug("%d %d %d %d\n",x,rem,prev,found);
	//print();
	//printisi();
	if (found) return;
	if ((prev + 1) * (r - x) < rem) return;
	if (rem == 0)
	{
		REP(i,r) REP(j,c)
		{
			isi[i][j] = 0;
			REP(k,9)
			{
				int xx = i + dirx[k];
				int yy = j + diry[k];
				if (0 <= xx && xx < r && 0 <= yy && yy < c)
					isi[i][j] += (mine[xx][yy]);
			}
		}
		//found = 1;
		//print();
		//print();
		REP(i,r) REP(j,c) if(mine[i][j] == 0)
		{
			ada = 0;
			RESET(sudah,0);
			ddfs(i,j);
			if (ada == r * c - m)
			{
				//print();
				//printisi();
				found = 1;
				REP(k,r) 
				{
					REP(l,c)
					{
						if (mine[k][l]) printf("*");
						else if (mp(i,j) == mp(k,l)) printf("c");
						else printf(".");
					}
					puts("");
				}
				return;
			}
		}
		return;
	}
	FORN(i,0,min(rem-1,prev))
	{
		FORN(j,0,i) mine[x][j] = 0;
		dfs(x+1,rem - i - 1,i);
		FORN(j,0,i) mine[x][j] = 1;
	}

}

int main()
{
	scanf("%d",&T);
	REPN(cases,T)
	{
		found = 0;
		printf("Case #%d:\n",cases);
		scanf("%d %d %d",&r,&c,&m);
		REP(i,r) REP(j,c) mine[i][j] = 1;
		dfs(0,r * c - m,c-1);
		if (!found) puts("Impossible");
	}
	return 0;
}










