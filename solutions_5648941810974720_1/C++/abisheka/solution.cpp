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
	string s;
	cin>>s;
	int c[26]={0},n=s.length(),ans[10]={0};
	
	rep(i,0,n-1)
	{
		c[s[i]-'A']++;
	}
	int cc=c['Z'-'A'];
	ans[0]=cc;
	c['Z'-'A']-=cc;c['E'-'A']-=cc;c['R'-'A']-=cc;c['O'-'A']-=cc;
	cc=c['W'-'A'];
	ans[2]=cc;
	c['T'-'A']-=cc;c['W'-'A']-=cc;c['O'-'A']-=cc;
	cc=c['U'-'A'];
	ans[4]=cc;
	c['F'-'A']-=cc;c['O'-'A']-=cc;c['U'-'A']-=cc;c['R'-'A']-=cc;
	cc=c['X'-'A'];
	ans[6]=cc;
	c['S'-'A']-=cc;c['I'-'A']-=cc;c['X'-'A']-=cc;
	cc=c['G'-'A'];
	ans[8]=cc;
	c['E'-'A']-=cc;c['I'-'A']-=cc;c['G'-'A']-=cc;c['H'-'A']-=cc;c['T'-'A']-=cc;
	cc=c['O'-'A'];
	ans[1]=cc;
	c['O'-'A']-=cc;c['N'-'A']-=cc;c['E'-'A']-=cc;
	cc=c['T'-'A'];
	ans[3]=cc;
	c['T'-'A']-=cc;c['H'-'A']-=cc;c['R'-'A']-=cc;c['E'-'A']-=cc;c['E'-'A']-=cc;
	cc=c['F'-'A'];
	ans[5]=cc;
	c['F'-'A']-=cc;c['I'-'A']-=cc;c['V'-'A']-=cc;c['E'-'A']-=cc;
	cc=c['S'-'A'];
	ans[7]=cc;
	c['S'-'A']-=cc;c['E'-'A']-=cc;c['V'-'A']-=cc;c['E'-'A']-=cc;c['N'-'A']-=cc;
	cc=c['I'-'A'];
	ans[9]=cc;
	c['N'-'A']-=cc;c['I'-'A']-=cc;c['N'-'A']-=cc;c['E'-'A']-=cc;
	rep(i,0,9)
	{
		rep(j,1,ans[i])
		ol(i);
	}	
	on;
}
return 0;
}
