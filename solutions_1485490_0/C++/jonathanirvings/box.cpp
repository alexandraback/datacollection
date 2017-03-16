//Google Code Jam
//Round 1C
//6 May 2012

//start of jonathanirvings' template v1.1.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
jonathan ganteng banget;

typedef long long LL;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef vector <LL> vl;
typedef vector <vl> vll;
typedef vector <string> vstr;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);

#define DEBUG printf("====TESTING====\n")
#define VALUE(x) cout << "The value of " << #x << " is " << x << endl;
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b);
#define MIN(a,b) a = min(a,b);
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr+1,arr+1+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE(v) next_permutation(ALL(v))
#define PERMUTEA(arr,sz) next_permutation(ALLA(arr,sz))
#define TC(t) while(t--)

inline string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline bool angka(char a) { return (a >= '0' && a <= '9'); }
inline bool kecil(char a) { return (a >= 'a' && a <= 'z'); }
inline bool besar(char a) { return (a >= 'A' && a <= 'Z'); }

inline string uppercase(string s){
	int n = SIZE(s); REP(i,n) 	if (kecil(s[i])) s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); REP(i,n) if (besar(s[i])) s[i] = s[i] - 'A' + 'a';
	return s;
}

//end of jonathanirvings' template v1.1.0 (BETA)

int t,n,m;
LL ada1[105],ada2[105];
int warna1[105],warna2[105];
LL jum1[105][105],jum2[105][105];
//LL dp[105][105][3][105];
map<pair<pii,pair<int,LL> >,LL> dp;

LL jahja(int a,int b,int rem,LL ix)
{
	if (a > n) return 0;
	if (b > m) return 0;
	pair<pii,pair<int,LL> > tmp;
	tmp = mp(mp(a,b),mp(rem,ix));
	if (dp.count(tmp) != 0) return dp[tmp];
	LL ret;
	//LL &ret = dp[a][b][rem][ix];
	//if (ret != -1) return ret;
	//printf("=======%d %d %d %d\n",a,b,rem,ix);
	if (rem == 0)
	{
		if (warna1[a] == warna2[b])
		{
			if (ada1[a] == ada2[b]) ret = ada1[a] + jahja(a+1,b+1,0,0); else
			if (ada1[a] > ada2[b]) ret = ada2[b] + jahja(a,b+1,1,ada1[a] - ada2[b]); else
			if (ada1[a] < ada2[b]) ret = ada1[a] + jahja(a+1,b,2,ada2[b] - ada1[a]);
		} else
		{
			//if (ada1[a] == ada2[b])
				ret = max(jahja(a+1,b,0,0),jahja(a,b+1,0,0)); //else
			//if (ada1[a] > ada2[b]) ret = jahja(a,b+1,1,b); else
			//if (ada1[a] < ada2[b]) ret = jahja(a+1,b,2,a);
		}
		dp[tmp] = ret;
		return ret;
	} 
	if (rem == 1)
	{
		LL sisa = ix;
		if (warna1[a] == warna2[b])
		{
			if (sisa == ada2[b]) ret = sisa + jahja(a+1,b+1,0,0); else
			if (sisa > ada2[b]) ret = ada2[b] + jahja(a,b+1,1,sisa - ada2[b]); else
			if (sisa < ada2[b]) ret = sisa + jahja(a+1,b,2,ada2[b] - sisa); 
		} else
		{
			//if (sisa == ada2[b])
				ret = max(jahja(a+1,b,0,0),jahja(a,b+1,1,ix)); //else
			//if (sisa > ada2[b]) ret = jahja(a,b+1,1,ix); else
			//if (sisa < ada2[b]) ret = jahja(a+1,b,2,a);
		}
		dp[tmp] = ret;
		return ret;
	}
	if (rem == 2)
	{
		LL sisa = ix;
		//printf("%lld %lld %lld\n",jum2[b][warna2[b]],sisa,sisa);
		if (warna1[a] == warna2[b])
		{
			if (sisa == ada1[a]) ret = sisa + jahja(a+1,b+1,0,0); else
			if (sisa > ada1[a]) ret = ada1[a] + jahja(a+1,b,2,sisa - ada1[a]); else
			if (sisa < ada1[a]) ret = sisa + jahja(a,b+1,1,ada1[a] - sisa); 
		} else
		{
			//if (sisa == ada1[a])
				ret = max(jahja(a+1,b,2,ix),jahja(a,b+1,0,0));// else
			//if (sisa > ada1[a]) ret = jahja(a+1,b,2,ix); else
			//if (sisa < ada1[a]) ret = jahja(a,b+1,1,a);
		}
		dp[tmp] = ret;
		return ret;
	}
	return 0;
}

int main()
{
	scanf("%d",&t);
	REPN(cases,t)
	{
		printf("Case #%d: ",cases);
		scanf("%d %d",&n,&m);
		RESET(jum1,0);
		RESET(jum2,0);
		REPN(i,n) 
		{
			scanf("%lld %d",&ada1[i],&warna1[i]);
			jum1[i][warna1[i]] = ada1[i];
		}
		REPN(i,m) 
		{
			scanf("%lld %d",&ada2[i],&warna2[i]);
			jum2[i][warna2[i]] = ada2[i];
		}
		REPN(i,n) REPN(j,100) jum1[i][j] += jum1[i-1][j];
		REPN(i,m) REPN(j,100) jum2[i][j] += jum2[i-1][j];
		dp.clear();
		LL risan = jahja(1,1,0,0);
		printf("%lld\n",risan);
	}
	return 0;
}

