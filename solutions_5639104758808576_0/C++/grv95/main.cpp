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

string s;

int arr[1005];

int main() {
//	ios_base::sync_with_stdio(false);
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.out","w",stdout);
	int T;
	int len;
	int ans;
	cin>>T;
	FORI(t,1,T){
        cin>>len;
        cin>>s;
  //      cout<<s<<endl;
        ans=0;
        arr[0]=s[0]-'0';
        FORI(i,1,len){
            if(arr[i-1]>=i)
                arr[i]=arr[i-1]+s[i]-'0';
            else
                ans+=i-arr[i-1],arr[i]=i+s[i]-'0';
        }
        printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
