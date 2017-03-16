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

int A[25],B[25];
vector<int> v,ans1,ans2;
bool good(int pos,int sum,bool took)
{	
	if(took)if(sum == 0)return true;
	if(pos >= sz(v))return false;
	if(good(pos+1,sum,took))return true;
	A[pos] = 1; if(good(pos+1,sum+v[pos],true))return true; A[pos] = 0;
	B[pos] = 1; if(good(pos+1,sum-v[pos],true))return true; B[pos] = 0;
	return false;
}
void show()
{
	int i;	ans1.clear(); ans2.clear();
	foo(i,0,v)if(A[i])ans1.push_back(v[i]); else if(B[i])ans2.push_back(v[i]);
	cout << ans1[0]; foo(i,1,ans1)printf(" %d",ans1[i]);
	cout << endl;
	cout << ans2[0]; foo(i,1,ans2)printf(" %d",ans2[i]);
}
int main()
{
	freopen("D://input.txt","r",stdin);
	freopen("D://output.txt","w",stdout);
	int Case,t,n,i;
	scanf("%d",&t);
	fo(Case,1,t+1)
	{		
		printf("Case #%d:\n",Case);
		CLR(A,0); CLR(B,0); cin >> n; v.resize(n); foo(i,0,v)cin >> v[i];
		if(good(0,0,false))
		{
			show();
		}
		else cout << "Impossible";
		cout << endl;
	}
	return 0;
} 

