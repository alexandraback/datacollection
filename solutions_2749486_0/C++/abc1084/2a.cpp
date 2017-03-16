#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef double ld;
typedef vector<ld> vld;


#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define fornl(i,n)   for(ll i=0;i<n;i++)
#define len			  size()
#define s(n)          scanf("%d",&n);
#define slld(n)       scanf("%lld",&n);
#define sf(n)         scanf("%lf",&n);
#define ss(n)         scanf("%s",n);
#define maX(a,b)      (a>b?a:b)
#define miN(a,b)      (a<b?a:b)
#define MEM(a,b)      memset(a,(b),sizeof(a))  //memset(arr,0,sizeof(arr))
#define istr(S)       istringstream sin(S)
#define MOD           1000000007
#define nl cout<<endl
    const long double EPS = 1E-9;
    const int INF = (int) 1E9;
    const ll INF64 = (ll) 1E18;
    bool ch(char c) {
    	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 0;
    	return 1;
    }
bool check(string s,int n) {
	if(s.size()<=n-1)  return 0;
	for(int i=n-1;i<s.size();i++) {
	//	if(ch(s[i])&&ch(s[i-1])&&ch(s[i-2])) return 1;
	bool f=0;
		for(int j =0;j<n;j++)
		if(ch(s[i-j])==0) f=1;
		if(f==0) return 1;		
	}
	return 0;
}
int main()
{
	freopen("inp3.txt","r",stdin);
	freopen("out3.txt","w",stdout);
	int t,y=0;
	cin>>t;
	while(t--) {
		y++;
		cout<<"Case #"<<y<<": ";
		int x,y;
		cin>>x>>y;
		if(x>0) {
			forn(i,x) cout<<"WE";
		}
		else if(x<0){
			x=-1*x;
		 forn(i,x) cout<<"EW";
		}
		if(y>0) {
		forn(i,y) cout<<"SN";
		}
		else if(y<0) {
			y=y*-1;
		forn(i,y) cout<<"NS";
		}
		cout<<endl;
	}
	}

