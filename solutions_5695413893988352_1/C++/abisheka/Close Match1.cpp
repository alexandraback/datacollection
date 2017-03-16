#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>  
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<vector<ll> > mat;

map<long long,pll > diff;
string a,b;
int n;

void go(int i,ll x,ll y,int eq)
{
	if(i==n)
	{
		if(present(diff,abs(y-x)))
		{
			if(x==diff[abs(y-x)].ff)
			{
				if(y<diff[abs(y-x)].ss)
				diff[abs(y-x)].ss=y;
			}
			else
			{
				if(x<diff[abs(y-x)].ff)
				{
					diff[abs(y-x)].ff=x;
					diff[abs(y-x)].ss=y;
				}
			}
		}
		else
		diff[abs(y-x)]=mp(x,y);
		//o2(x,y);on;
		return;
	}
	if(a[i]=='?'&&b[i]=='?')
	{
		if(eq==1)
		{
			go(i+1,x*10,y*10,1);
			go(i+1,x*10,y*10+1,0);
			go(i+1,x*10+1,y*10,0);
		}
		else
		{
			go(i+1,x*10,y*10+9,0);
			go(i+1,x*10+9,y*10,0);
		}
	}
	else if(a[i]=='?'&&b[i]!='?')
	{
		if(eq==1)
		{
			go(i+1,x*10+b[i]-'0',y*10+b[i]-'0',1);
			if(b[i]-'0'<9)
			go(i+1,x*10+b[i]-'0'+1,y*10+b[i]-'0',0);
			if(b[i]-'0'>0)
			go(i+1,x*10+b[i]-'0'-1,y*10+b[i]-'0',0);
		}
		else
		{
			go(i+1,x*10+9,y*10+b[i]-'0',0);
			go(i+1,x*10,y*10+b[i]-'0',0);
		}
	}
	else if(a[i]!='?'&&b[i]=='?')
	{
		if(eq==1)
		{
			go(i+1,x*10+a[i]-'0',y*10+a[i]-'0',1);
			if(a[i]-'0'<9)
			go(i+1,x*10+a[i]-'0',y*10+a[i]-'0'+1,0);
			if(a[i]-'0'>0)
			go(i+1,x*10+a[i]-'0',y*10+a[i]-'0'-1,0);
		}
		else
		{
			go(i+1,x*10+a[i]-'0',y*10+9,0);
			go(i+1,x*10+a[i]-'0',y*10,0);
		}
	}
	else
	{
		int kk=0;
		if(eq==1&&a[i]==b[i])
		kk=1;
		go(i+1,x*10+a[i]-'0',y*10+b[i]-'0',kk);
	}
}

int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,t1=0;
gl(t);
while(t--)
{
	t1++;
	ol("Case #");ol(t1);ol(": ");
	
	cin>>a>>b;
	
    n=a.length();
    diff.clear();
    
    go(0,0,0,1);
	tr(diff,it)
	{
		string aa,bb;
			rep(j,0,n-1)
			{
				aa+=(char)(((it->ss).ff)%10)+'0';
				bb+=(char)(((it->ss).ss)%10)+'0';
				(it->ss).ff/=10;
				(it->ss).ss/=10;
			}
			reverse(all(aa));
			reverse(all(bb));
			o2(aa,bb);
			on;
			break;
	}
	
}
return 0;
}
