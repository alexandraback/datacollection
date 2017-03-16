//satyaki3794
#include <bits/stdc++.h>
#include <iomanip>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}

typedef pair<string, string> pss;
int n, dist[1<<17];
vector<int> adj[1<<17];
pss arr[20];


int main()
{
    ios_base::sync_with_stdio(0);

    freopen("C-small-attempt0 (1).in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
   // t=1;
    while(t--){

    	cout<<"Case #"<<x++<<": ";
    	memset(dist, -1, sizeof(dist));

    	cin>>n;
    	for(int i=0;i<n;i++)
    		cin>>arr[i].ff>>arr[i].ss;

    	for(int i=0;i<(1<<n);i++)
    		adj[i].clear();

    	set<string> f, s;
    	for(int mask=0;mask<(1<<n);mask++){
    		f.clear();	s.clear();
    		for(int i=0;i<n;i++)
    			if((mask>>i) & 1){
    				f.insert(arr[i].ff);
    				s.insert(arr[i].ss);
    			}

    // cout<<"now at mask = "<<mask<<":\n";
    // cout<<"f: ";for(auto it : f)	cout<<(it)<<" ";cout<<endl;
    // cout<<"s: ";for(auto it : s)	cout<<(it)<<" ";cout<<endl;

    		for(int next=0;next<n;next++){
    			if((mask>>next) & 1)	continue;
    			if(f.find(arr[next].ff) == f.end())	continue;
    			if(s.find(arr[next].ss) == s.end())	continue;
    	// cout<<"\ncan go from "<<mask<<" to "<<next<<endl<<endl;;
    			adj[mask|(1<<next)].pb(mask);
    	// cout<<"added edge from "<<(mask|(1<<next))<<" to "<<mask<<endl;
    		}
    	}

    	queue<int> qq;
    	dist[(1<<n)-1] = 0;
    	qq.push((1<<n)-1);
    	while(!qq.empty()){
    		int v = qq.front();
    		qq.pop();
    		for(int i=0;i<(int)adj[v].size();i++){
    			int vv = adj[v][i];
    			if(dist[vv] == -1){
    				dist[vv] = dist[v]+1;
    				qq.push(vv);
    			}
    		}
    	}

// cout<<"dist\n";
// for(int i=0;i<8;i++)	cout<<dist[i]<<" ";cout<<endl;

    	int ans = -1;
    	for(int mask=0;mask<(1<<n);mask++)
    		if(dist[mask] != -1)
    			ans = max(ans, n - __builtin_popcount(mask));
    	cout<<ans<<endl;
    }

    return 0;
}







