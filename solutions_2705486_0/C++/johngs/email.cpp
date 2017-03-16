//Google Code Jam 2013
//Round 1B
//4 May 2013

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
int INF = 1000000000;
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

int T,n;
string s;
char x[1000005];
int dp[55][10];
//map<string,bool> ada;
vector<string> words[100];
int maxlen;
int W = 521196;

inline pair<int,pii> change(int a,int b,int c)
{
	//if (b - a + 1 != SIZE(words[c])) return INF;
	int len = b - a + 1;
	int last = -1;
	int ret = 0;
	int first = -1;
	REP(i,len)
	{
		if (s[i + a] != words[len][c][i])
		{
			if (first == -1) first = i;
			if (last == -1 || i - last >= 5)
			{
				++ret;
				last = i;
			} else return mp(INF,mp(-1,-1));
		}
	}
	return mp(ret,mp(first,last));
}

int jahja(int a,int last)
{
	if (a == n) return 0;
	int &ret = dp[a][last];
	if (ret > -1) return ret;
	ret = INF;
	//debug("%d %d\n",a,last);
	FOR(i,a,n)
	{
		int len = i - a + 1;
		if (len > maxlen) break;
		int sz = SIZE(words[len]);
		//VALUE(sz); VALUE(len);
		REP(j,sz)
		{
			pair<int,pii> tmp = change(a,i,j);
			if (tmp.fi == INF) continue;
			if (tmp.fi == 0)
			{
				int next = (last + len > 5 ? 0 : last + len);
				if (last == 0) next = 0;
				MIN(ret,jahja(i+1,next));
			} else
			if (last == 0 || last + tmp.se.fi > 4)
			{
				int next = (len - tmp.se.se > 5 ? 0 : len - tmp.se.se);
				MIN(ret,tmp.fi + jahja(i+1,next));
			}
		}
	}
	return ret;
}

int main()
{
	FILE *kin = fopen("dict.txt","r");
	while (fscanf(kin,"%s",x)!=EOF) 
	{
		s = x;
		//ada[s] = 1;
		words[SIZE(s)].pb(s);
		MAX(maxlen,SIZE(s));
	}
	//words[7].pb("codejam");
	scanf("%d",&T);
	REPN(cases,T)
	{
		printf("Case #%d: ",cases);
		fprintf(stderr,"%d\n",cases);
		RESET(dp,-1);
		s = GetString();
		n = SIZE(s);
		int risan = jahja(0,0);
		printf("%d\n",risan);
	}
	return 0;
}

