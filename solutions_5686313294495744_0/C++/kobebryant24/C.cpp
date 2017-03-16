#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

#define fi          first
#define se          second
#define mp 			make_pair
#define pb          push_back
#define forall(i,a,b)               for(int i=a;i<b;++i)
#define max(a,b)                    ( (a) > (b) ? (a) : (b))
#define min(a,b)                    ( (a) < (b) ? (a) : (b))
#define mes(a,b)					memset(a,b,sizeof a)
#define endl			    		"\n"
#define ll 							long long
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;

int main(){
	int t;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		string a[20],b[20];
		int n,ans=0;cin >> n;
		forall(i,0,n) cin >> a[i] >> b[i];
		for(int i=(1<<n)-1;i>=0;--i){
			bool af=true,bf=true;
			vi x,y;
			int temp=0;
			forall(j,0,n) {
				if(i>>j & 1) x.pb(j),++temp;
				else y.pb(j);
			}
			forall(j,0,x.size()){
				bool lala=false;
				forall(k,0,y.size()){
					if(a[x[j]]==a[y[k]]) {
						lala=true;
						break;
					}
				}
				if(!lala) af=false;
			}
			if(!af) continue;
			forall(j,0,x.size()){
				bool lala=false;
				forall(k,0,y.size()){
					if(b[x[j]]==b[y[k]]) {
						lala=true;
						break;
					}
				}
				if(!lala) bf=false;
			}
			if(!bf) continue;
			else ans=max(ans,temp);
		}
		cout << ans << endl;
	}
}