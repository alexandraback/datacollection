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

vector<string> frst(1001),scd(1001);
unordered_map<string,int> m1,m2;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int n;
    string tmp;
    FORI(t,1,T){
        cout<<"Case #"<<t<<": ";
        cin>>n;
        m1.clear();
        m2.clear();
        FOR(i,0,n){
            cin>>frst[i]>>scd[i];
            ++m1[frst[i]];
            ++m2[scd[i]];
        }
        int ans=0;
        FOR(i,0,n){
            if(m1[frst[i]]>1 && m2[scd[i]]>1){
                ans++;
               m1[frst[i]]--;
                m2[scd[i]]--;
            }
        }




        cout<<ans<<endl;
    }


	return 0;
}
