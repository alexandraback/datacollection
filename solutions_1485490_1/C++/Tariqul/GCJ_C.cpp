#include "stdafx.h"

#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector>

using namespace std; 

#define fo(i,j,n) for(i=j;i<n;++i)
#define Fo(i,j,n) for(i=n-1;i>=j;--i)
#define foo(i,j,v) fo(i,j,sz(v))
#define Foo(i,j,v) Fo(i,j,sz(v))
#define li(v) v.begin(),v.end()
#define sz(v) ((int)v.size())
#define CLR(a,v) memset((a),(v),sizeof(a))
#define inf 1000000001
//typedef long long Long;
typedef __int64 Long;
#define pi (2*acos(0))
#define eps 1e-9

#define two(X) (1<<(X))
#define twoL(X) (((Long)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

char BUFFER[100000 + 5];
bool readn(int &n)	{ return scanf("%d",&n) == 1; } 
bool readl(Long &n)	{ return scanf("%I64d",&n) == 1; } 
bool readd(double &n){ return scanf("%lf",&n) == 1; } 
bool reads(string &s){ s = ""; int n = scanf("%s",BUFFER); if(n == 1)s = BUFFER; return n == 1; }
bool readln(string &s){ char *valid = gets(BUFFER); if(valid)s = BUFFER; return ((bool)valid); }

vector<Long> A1,A2,T1,T2;

Long Min(Long a,Long b)
{
	if(a < b)return a; return b;
}

Long Max(Long a,Long b)
{
	if(a > b)return a; return b;
}

void input(int &n,int &m)
{
	cin >> n >> m; A1.clear(); A2.clear(); T1.clear(); T2.clear();
	Long a,b,pb = -1; int i,j;
	fo(i,0,n)
	{
		readl(a); readl(b);
		if(pb != b){ A1.push_back(0); T1.push_back(b); pb = b; }
		j = sz(A1) - 1;	A1[j] += a; 
	}
	pb = -1;
	fo(i,0,m)
	{
		readl(a); readl(b);
		if(pb != b){ A2.push_back(0); T2.push_back(b); pb = b; }
		j = sz(A2) - 1;	A2[j] += a; 
	}
	n = sz(A1); m = sz(A2);
}

const int maxn = 105;
Long f[maxn][maxn];

Long memo(int n,int m)
{
	Long &res = f[n][m]; if(res != -1)return res;
	if((n == 0) || (m == 0))return res = 0;
	res = 0; res = Max(res,memo(n,m-1)); res = Max(res,memo(n-1,m));
	int i,j; Long su1 = 0,su2 = 0;
	int t = T1[n-1]; su1 = su2 = 0;
	Fo(i,0,n)
	{
		if(T1[i] == t)su1 += A1[i]; su2 = 0;
		Fo(j,0,m)
		{
			if(T2[j] == t)su2 += A2[j];
			res = Max(res,memo(i,j)+Min(su1,su2));
		}
	}
	t = T2[m-1]; su1 = su2 = 0;
	Fo(i,0,n)
	{
		if(T1[i] == t)su1 += A1[i]; su2 = 0;
		Fo(j,0,m)
		{
			if(T2[j] == t)su2 += A2[j];
			res = Max(res,memo(i,j)+Min(su1,su2));
		}
	}
	return res;
}

int main()
{
	freopen("D://input.txt","r",stdin);
	freopen("D://output.txt","w",stdout);
	int Case,t,n,m;
	scanf("%d",&t);
	fo(Case,1,t+1)
	{		
		printf("Case #%d: ",Case);
		input(n,m); CLR(f,-1);
		printf("%I64d",memo(n,m));
		cout << endl;
	}
	return 0;
} 

