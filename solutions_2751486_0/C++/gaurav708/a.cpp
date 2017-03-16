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

string name;
vector<pii> pos;
bool isvowel(char c) {
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {
	int T,n,l;
	scanf("%d",&T);
	rep(t,T) {
		pos.clear();
		printf("Case #%d: ",t+1);
		cin>>name;
		l=name.size();
		scanf("%d",&n);
		int cnt=0,prev=-1;
		rep(i,l) {
			if(!isvowel(name[i])) cnt++;
			else cnt=0;
			if(cnt>=n) pos.pb(mp(i-n+1,i));
		}
		ll ans=0;
		rep(i,pos.size()) {
			ans+=ll(pos[i].fi-prev)*ll(l-pos[i].sc);
			prev=pos[i].fi;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
