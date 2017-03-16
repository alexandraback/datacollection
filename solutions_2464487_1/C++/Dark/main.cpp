#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-4
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)

int main(){
	int ca, c = 0;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&ca);
	while(ca--){
        LL r,t;
        cin>>r>>t;
        LL low = 1, high = t;
        LL ans = 1;
        while(high-low>=0){
            LL mid = (low+high)/2;
            //cout<<mid<<" "<<p<<endl;
            if( 2*mid-1 <= t/mid - 2*r ) ans= mid, low = mid+1;
            else high = mid-1;
        }
        cout<<"Case #"<<++c<<": "<<ans<<endl;
	}
	return 0;
}
