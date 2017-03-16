/*
ID: Alaudddin
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

// Large problem er jonno data type change korte hobe
// Large problem er jonno data type change korte hobe
// Large problem er jonno data type change korte hobe
// Large problem er jonno data type change korte hobe

vector<string > v;
vector<int> p;
string s;

bool normalize(string &s)
{
	string res = ""; char ch;
	int i; foo(i,0,s)s[i] -= 'a';
	res = ch = s[0];
	foo(i,1,s)if(ch !=  s[i]){ ch = s[i]; res += ch; }
	vector<bool> vis(30,false);
	foo(i,0,res)if(vis[res[i]])return false; else vis[res[i]] = true;
	s = res;
	return true;
}

int getv(vector<int> &vis, int m)
{
	int i,j,k;
	char ch = -1;
	foo(k,0,p)
	{
		i = p[k];
		foo(j,0,v[i])if(ch != v[i][j])
		{
			ch = v[i][j];
			if(vis[ch] == m)return 0;
			vis[ch] = m;
		}
	}
	return 1;
}

int calc()
{
	int i,n; cin >> n; v.clear(); p.clear();
	int ans = 0;
	fo(i,0,n)
	{
		reads(s);
		if(false ==  normalize(s))return 0;
		v.push_back(s); p.push_back(i);
	}
	vector<int> vis(30,0);
	i = 1;
	do
	{
		ans += getv(vis,i++);
	}while(next_permutation(li(p)));

	return ans;
}

int main()
{
	freopen("D://input.txt","r",stdin);
	freopen("D://output.txt","w",stdout);
	int Case,t;
	scanf("%d",&t);
	fo(Case,1,t+1)
	{		
		printf("Case #%d: ",Case);
		cout << calc();
		cout << endl;
	}
	return 0;
} 

