#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef vector<pair<int, pair<int, int> > > viii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<vii> vvii;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(a) a.begin(),a.end()
#define loop(x,a,b) for(int (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])  
#define md 1000000007
#define MAXN 200005

void fn()
{
	set<int> s;
	ll n,nn;
	cin>>n;
	nn = n;
	if(n == 0)
		cout<<"INSOMNIA\n";
	else
		while(1)
		{
			ll nc = n;
			while(nc)
			{
				s.insert(nc%10);
				nc /= 10;
			}
			if(s.size() == 10)
			{
				cout<<n<<"\n";
				return;
			}
			n += nn;
		}
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    rep(i,t)
    {
    	cout<<"Case #"<<i+1<<": ";
    	fn();
    }
    return 0;
}
