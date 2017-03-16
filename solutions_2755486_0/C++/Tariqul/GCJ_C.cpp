/*
ID: Tariqul
PROG: 
LANG: C++
*/

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

const int maxn = 1000,extra = 250;
const int Limit = 12;
int Wall[maxn],di[Limit],ni[Limit],wi[Limit],ei[Limit],si[Limit],deldi[Limit],delpi[Limit],delsi[Limit];

bool isSucceed(int pos)
{
	if(ni[pos] == 0)return false;
	int n1 = wi[pos] * 2, n2 = ei[pos] * 2 + 1,i,s = si[pos];
	fo(i,n1,n2)if(Wall[i] < s)return true;
	return false;
}

void updateValue(int pos)
{		
	if(ni[pos] == 0)return;
	int n1 = wi[pos] * 2, n2 = ei[pos] * 2 + 1,i,s = si[pos];
	fo(i,n1,n2)if(Wall[i] < s)Wall[i] = s;	
	di[pos] += deldi[pos]; ni[pos]--;  wi[pos] += delpi[pos]; ei[pos] += delpi[pos]; si[pos] += delsi[pos];	
}

int getv(int n)
{
	int i,ans = 0,day = -1;
	bool update = true;
	while(update)
	{
		update = false; day++;
		fo(i,0,n)
		{
			if(ni[i] > 0)update = true;
			if(di[i] != day)continue;
			ans += isSucceed(i);
		}
		if(!update)break;
		fo(i,0,n)
		{			
			if(di[i] != day)continue;
			updateValue(i);			
		}
	}

	return ans;
}

int main()
{
	freopen("D://input.txt","r",stdin);
	freopen("D://output.txt","w",stdout);
	int Case,t,n,i;
	scanf("%d",&t);
	fo(Case,1,t+1)
	{		
		CLR(Wall,0); cin >> n;
		fo(i,0,n)
		{
			cin >> di[i] >> ni[i] >> wi[i] >> ei[i] >> si[i] >> deldi[i] >> delpi[i] >> delsi[i];
			wi[i] += extra;
			ei[i] += extra;
		}
		
		printf("Case #%d: ",Case);
		cout << getv(n);
		cout << endl;
	}
	return 0;
} 

