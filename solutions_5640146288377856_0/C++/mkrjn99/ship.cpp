#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

int main() {
    static int T,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    rep(k,1,T+1){
        int R,C,W;
        cin>>R>>C>>W;
        int ans=0;
        ans+=(C-1)/W+W;
        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %d",k,ans);
        cout<<ans_string<<'\n';
    }
    return 0;
}

