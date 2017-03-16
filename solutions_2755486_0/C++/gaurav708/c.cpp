#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define fordn(i,a,b) for(int i=a;i>=b;i--)
#define drep(i,n) for(i=0;i<n;i++)
#define dforup(i,a,b) for(i=a;i<=b;i++)
#define dfordn(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

map<int,vi> days;
struct tribe {
	int dd,dp,ds;
};

int main() {
	int T,N,n,d;
	scanf("%d",&T);
	rep(t,T) {
		printf("Case #%d: ",t+1);
		days.clear();
		scanf("%d",&N);
		int ans=0;
		vi ne(N),nw(N),ns(N),cur(4020,0);
		vector<tribe> delta(N);
		rep(i,N) {
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&nw[i],&ne[i],&ns[i],&delta[i].dd,&delta[i].dp,&delta[i].ds);
			rep(j,n) {
				days[d+j*delta[i].dd].pb(i);
			}
		}
		for(map<int,vi>::iterator it=days.begin();it!=days.end();it++) {
			vi tb = it->sc;
			rep(i,tb.size()) {
				forup(j,2*(nw[tb[i]]+1000),2*(ne[tb[i]]+1000)) {
					if(cur[j]<ns[tb[i]]) {
						ans++;
						//printf("%d %d %d %d\n",it->fi,tb[i],cur[j],ns[tb[i]]);
						break;
					}
				}
			}
			rep(i,tb.size()) {
				forup(j,2*(nw[tb[i]]+1000),2*(ne[tb[i]]+1000)) {
					if(cur[j]<ns[tb[i]]) {
						cur[j]=ns[tb[i]];
					}
				}
				nw[tb[i]]+=delta[tb[i]].dp;
				ne[tb[i]]+=delta[tb[i]].dp;
				ns[tb[i]]+=delta[tb[i]].ds;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
