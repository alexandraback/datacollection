#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<pii > vpii;
typedef vector<ll> vll;

#define mp make_pair
#define pb push_back
#define eps 1e-9
#define all(a) (a).begin(),(a).end()
#define len(a) int((a).size())
#define  mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)


#define inf 999999


vvi rev;
vi ary;

int vis[1111];

int get_max_path(int x,int par){
	if(vis[x])return 0;
	vis[x] = true;
	int mx = 1;
	rep(i,len(rev[x])){
		if(rev[x][i]==par)continue;
		mx = max(mx,1+get_max_path(rev[x][i],x));
	}
	return mx;
}


int get_cycle(int x, int cnt){
	if(vis[x]){
		return cnt-vis[x];
	}
	vis[x] = cnt;
	return get_cycle(ary[x],cnt+1);
}



int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int tst;
	cin>>tst;
	repi(ks,1,tst+1){
		int n;
		cin>>n;
		rev.clear();
		rev.resize(n);
		ary.clear();
		ary.resize(n);
		rep(i,n){
			int t;
			cin>>t;
			t--;
			ary[i] = t;
			rev[t].pb(i);
		}
		int ans = 0;
		mem(vis,0);
		
		rep(i,n){
			int tot = -1;
			if(i==ary[ary[i]]){
				
				tot = get_max_path(i,ary[i])+get_max_path(ary[i],i);
				//~ cout<<i<<" == "<<tot<<endl;
				if(tot)	ans+= tot;
			}
		}
		//~ cout<<ans<<endl;
		
		rep(i,n){
			mem(vis,0);
			int tot = get_cycle(i,1);
			ans = max(ans,tot);
		}
		
		cout<<"Case #"<<ks<<": "<<ans<<endl;
	}
	
	return 0;
}
