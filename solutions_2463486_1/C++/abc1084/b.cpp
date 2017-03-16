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
#include<cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

 
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
#define p(n) printf("%d",n);
#define nl printf("\n");
#define pl(n) printf("%ld",n);

    const long double EPS = 1E-9;
    const int INF = (int) 1E9;
    const ll INF64 = (ll) 1E18;
    bool check(string s) {
	    for(int i=0,j=s.size()-1;i<j;i++,j--) {
		    if(s[i]!=s[j]) return 0;
	    }
	    return 1;

    }
     int main()
     {
	     int t;
	     cin>>t;
	     int y=0;
	     vector<ll> v;
		for(ll i=1;i<=10000000;i++)  {
			stringstream ss;
			ss<<i;
			string t;			
			ss>>t;
			if(check(t)) {
				ll tem=(ll)i*(ll)i;
				ss.clear();
				ss<<tem;
				t.clear();				
				ss>>t;			
				if(check(t)) {v.pb(tem); }
			}
		}
//		fornl(i,v.size()) cout<<v[i]<<" ";
//		cout<<check("121");
			
	     while(t--) {
		     y++;
		     ll a,b;
		     cout<<"Case #"<<y<<": ";
		     cin>>a>>b;
		cout<<upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a)<<endl;
	     }	     

     }

