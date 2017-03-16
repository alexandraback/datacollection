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
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

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

int T;
int point[1005];
vi ke[1005];
int dp[1005];
int n;
bool sudah[1005];
bool sudah2[1005];

int jahja(int x)
{
  assert(!sudah[x]);
  int &ret = dp[x];
  if (ret >= 0) return ret;
  ret = 1;
  REP(i,SIZE(ke[x])) MAX(ret,jahja(ke[x][i]) + 1);
  return ret;
}

int main()
{
	scanf("%d", &T);
  REPN(cases,T)
  {
    RESET(dp,-1);
    scanf("%d",&n);
    REP(i,n) ke[i].clear();
    REP(i,n)
    {
      scanf("%d",&point[i]);
      --point[i];
      ke[point[i]].pb(i);
    }
    int risan1 = 0;
    int risan2 = 0;
    RESET(sudah2,0);
    REP(i,n)
    {
      RESET(sudah,0);
      int x = i;
      int y = i;
      int ada = 0;
      while (1)
      {
        if (sudah[x]) break;
        sudah[x] = 1;
        y = x;
        x = point[x];
        ++ada;
      }
      if (x == i)
      {
        //printf("%d %d\n",y+1,x+1);
        int ret1 = 0;
        int ret2 = 0;
        REP(i,SIZE(ke[x]))
        {
          if (!sudah[ke[x][i]]) MAX(ret1,jahja(ke[x][i]));
        }
        REP(i,SIZE(ke[y]))
        {
          if (!sudah[ke[y][i]]) MAX(ret2,jahja(ke[y][i]));
        }
        if (ada == 2) 
        {
          if (sudah2[x]) continue;
          sudah2[x] = sudah2[y] = 1;
          risan1 += ret1+ret2+ada;
        }
        MAX(risan2,ada);
        //debug("%d %d %d %d\n",i+1,ada,ret1,ret2);
      }
    }
    printf("Case #%d: %d\n", cases,max(risan1,risan2));
  }
	return 0;
}
















