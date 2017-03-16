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
const double eps=1e-9;

int main() {
	int T;
	ll r,t;
	scanf("%d",&T);
	rep(c,T) {
		printf("Case #%d: ",c+1);
		scanf("%lld%lld",&r,&t);
		double r0=double(2*r-1);
		ll sq = ll(sqrt(r0*r0+8*double(t))-eps);
		//cout<<sq<<" ";
		ll k = (sq-(2*r+1))/2;
		k=max(ll(0),k-10);
		while(true) {
			ll tmp=r*(k+1)+k*(k+1)/2;
			if(tmp>t) break;
			k++;
		}
		printf("%lld\n",k/2);
	}
	return 0;
}
