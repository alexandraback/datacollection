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

int n,m;
double p[200000],a[200000];

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	
	int T; cin>>T;
	Rep(_,1,T){
		scanf("%d%d",&n,&m);
		
		double ans=m+2.0;
		
		a[0]=1.0;
		Rep(i,1,n){
			scanf("%lf",p+i);		
			a[i]=a[i-1]*p[i];
		}
		
		Rep(i,0,n){
			double ret=n-i+m-i+1+(1-a[i])*(m+1);
			ans=min(ans,ret);
		}
		
		printf("Case #%d: %.7lf\n",_,ans);
	}

    return 0;
}
