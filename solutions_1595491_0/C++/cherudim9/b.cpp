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

#ifdef online
#else
#endif

int main(){
    	freopen("b.in","r",stdin);
    	freopen("b.out","w",stdout);
		
	int T;cin>>T;
	Rep(_,1,T){
		int n,k,p; int a[200], f[200][200];
		cin>>n>>k>>p;
		Rep(i,1,n) cin>>a[i];
		
		memset(f,0,sizeof(f));
		Rep(i,0,n-1){
			int x=i+1,val0=0,val1=0;
			val0=(a[x]+2)/3>=p;
			val1=(a[x]+4)/3>=p && p>=2;
		
			Rep(j,0,k){
				f[i+1][j]=max(f[i+1][j],f[i][j]+val0);
				if (j!=k)
					f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+val1);
			}
		}
			
		printf("Case #%d: %d\n",_,f[n][k]);
	}

    return 0;
}
