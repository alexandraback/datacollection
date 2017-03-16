#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int, ll> Pil;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
	int Q;
	scanf("%d",&Q);
	rep(q,Q){
		int N;
		scanf("%d",&N);
		vector<string> headS;
		vector<string> endS;
		string h,e;
		rep(i,N){
			cin >> h >> e;
			headS.pb(h);
			endS.pb(e);
		}
		int bit = 1<<N;
		int ans = -1;
		rep(i,bit){
			int comp = 0;
			rep(j,N){
				if(!((i>>j)&1)){
					rep(k,N){
						if(!((i>>k)&1)){
							string add = headS[j]+endS[k];
							rep(l,N){
								if((i>>l)&1){
									if(add == headS[l]+endS[l]){
										++comp;
									}
								}
							}
							ans = max(ans,comp);
						} 
					}
				}
			}
		}
		printf("Case #%d: %d\n",q+1,ans);

	}
	return 0;
}
