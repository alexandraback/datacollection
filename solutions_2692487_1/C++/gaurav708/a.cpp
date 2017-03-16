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



int main() {
	int T,a,n,ans;
	scanf("%d",&T);
	rep(t,T) {
		printf("Case #%d:",t+1);
		scanf("%d%d",&a,&n);
		vi mote(n+1),op(n+1);
		forup(i,1,n) scanf("%d",&mote[i]);
		if(a==1) ans=n;
		else {
			sort(all(mote));
			int cur=a;
			op[0]=0;
			forup(i,1,n) {
				op[i]=op[i-1];
				if(mote[i]<cur)
					cur+=mote[i];
				else {
					int cnt=0;
					while(cur<=mote[i]) {
						cur+=cur-1;
						cnt++;
					}
					op[i]+=cnt;
					cur+=mote[i];
				}
			}
			/*forup(i,1,n) printf("%d ",mote[i]);
			puts("");
			forup(i,1,n) printf("%d ",op[i]);
			*/
			ans=n;
			forup(i,1,n) {
				ans=min(ans,op[i]+n-i);
			}
		}
		printf(" %d\n",ans);
	}
	return 0;
}
