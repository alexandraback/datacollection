#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) int((a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

set<int> c;

int trans(int n, int l, int r){
	int ret=0;
	
	stringstream aa; aa<<n; string s,ss; aa>>s;
	int len=s.size();
	ss=s;
	Rep(i,1,len-1){
		char ch=ss[len-1];
		Repd(j,len-1,1) ss[j]=ss[j-1];
		ss[0]=ch;
		
		int m; stringstream bb(ss); bb>>m;
		if (m>n && m>=l && m<=r && ss[0]!='0' && c.find(m)==c.end() )
			ret++, c.insert(m);
	}
	
	return ret;
}

int main(){
    	freopen("c.in","r",stdin);
    	freopen("c.out","w",stdout);

	int T;cin>>T;
	Rep(_,1,T){
		int a,b;
		cin>>a>>b;
		int ans=0;
		Rep(n,a,b)
			c.clear(), ans+=trans(n,a,b);
		printf("Case #%d: %d\n",_,ans);
	}

    return 0;
}
