#include <bits/stdc++.h>
using namespace std;
//defines-general
typedef long long ll;
typedef long double ld;
#define to(a) __typeof(a)
#define fill(a,val) memset(a,val,sizeof(a))
#define repi(i,a,b) for(__typeof((b)) i = a;i<(b);i++)
//defines-pair
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define ff first
#define ss second
#define mp make_pair
//defines-vector
typedef vector<int> vi;
typedef vector<long long> vll;
#define all(vec) vec.begin(),vec.end()
#define tr(vec,it) for(__typeof(vec.begin()) it = vec.begin();it!=vec.end();++it)
#define pb push_back
#define sz size()
#define contains(vec,x) (find(vec.begin(),vec.end(),x)!=vec.end())

#define MOD 1000000007

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t;
    cin >> t;
    for(int loop = 1; loop <= t; loop++)
    {
        int r, c, w;
        cin >> r >> c >> w;
        int ans = (c-1)/w;
        ans += (r-1) * (c/w);
        ans+=w;
        cout << "Case #"<<loop<<": "<<ans<<endl;
    }
    return 0;
}