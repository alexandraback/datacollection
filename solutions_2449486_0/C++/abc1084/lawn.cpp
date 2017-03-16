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
    int ar[100][100];
    bool check(int i,int n,int no,char ch) {
	    if(ch=='r') {
		    forn(j,n) {
			    if(ar[j][i]>no) return 1 ;
		    }
		    return 0;
	    }
	    if(ch=='c') {
		    forn(j,n) {
			    if(ar[i][j]>no) return 1;
		    }
		    return 0;
	    }
    }
     int main()
     {	
	     int t;
	     cin>>t;
	     int y=0;
	     while(t--) {
		     y++;
		int n,m;
		cin>>n>>m;
		forn(i,n) {
			forn(j,m) {
				cin>>ar[i][j];
			}
		}
		bool f=1;
		forn(i,n) {
			forn(j,m) {
				if(check(i,m,ar[i][j],'c') &&  check(j,n,ar[i][j],'r')) { f=0;break; }
			}
			if(f==0) break;
		
	     }
	     cout<<"Case #"<<y<<": ";
	     if(f==0) { cout<<"NO\n"; }
	     else cout<<"YES\n";


     }
    }

