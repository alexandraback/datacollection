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

vi val;
int e,r,n;
int calc(int i,int cur,int score) {
	if(i>=n) return score;
	if(cur>e) cur=e;
	int ret=score;
	rep(j,cur+1) {
		ret=max(ret,calc(i+1,cur-j+r,score+val[i]*j));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d",&T);
	rep(t,T) {
		printf("Case #%d: ",t+1);
		scanf("%d%d%d",&e,&r,&n);
		val.resize(n);
		rep(i,n) scanf("%d",&val[i]);
		printf("%d\n",calc(0,e,0));
	}
	return 0;
}
