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



int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tst;
	cin>>tst;
	repi(ks,1,tst+1){
		int n;
		cin>>n;
		vi ary(2555,0);
		rep(i,2*n-1){
			rep(j,n){
				int t;
				cin>>t;
				ary[t]++;
			}			
		}
		vi ans;
		rep(i,len(ary))if(ary[i]%2)ans.pb(i);
		sort(all(ans));
		cout<<"Case #"<<ks<<":";
		rep(i,len(ans))cout<<" "<<ans[i];
		cout<<endl;
	}
	
	return 0;
}
