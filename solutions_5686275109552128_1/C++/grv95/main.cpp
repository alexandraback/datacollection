#include <bits/stdc++.h>
#define X first
#define Y second
#define psb push_back
#define pob pop_back
#define mp make_pair
#define ll long long
#define scand(n) scanf("%d",&n)
#define scanld(n) scanf("%lld",&n)
#define printd(n) printf("%d\n",n)
#define printld(n) printf("%lld\n",n)
#define all(x) x.begin(),x.end()
#define SET( arr, val) memset(arr,val,sizeof(arr))
#define ITR iterator
#define SZ(arr) arr.size()
#define FOR( i, L, U ) for(int i=(int)L ; i<(int)U ; ++i )
#define FORI( i, L, U ) for(int i=(int)L ; i<=(int)U ; ++i )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; --i )
#define Tcases(t) int t;cin>>t;while(t--)

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int arr[1005];

int reduce(int val,int mx){
    int ret=0;
    while(val>mx){
        ret++;
        val-=mx;
    }
    return ret;
}

int main() {
//	ios_base::sync_with_stdio(false);
    freopen("B-large.in","r",stdin);
    freopen("output.out","w",stdout);
	int T,d;
	cin>>T;
	FORI(t,1,T){
        cin>>d;
        int large=INT_MIN;
        FOR(i,0,d){
            cin>>arr[i];
            large=max(large,arr[i]);
        }
        int ans=large;

        FORI(k,1,large){
            int tot=0;
            FOR(i,0,d)
                tot+=reduce(arr[i],k);
            ans=min(ans,tot+k);
        }
        printf("Case #%d: %d\n",t,ans);
	}

	return 0;
}
