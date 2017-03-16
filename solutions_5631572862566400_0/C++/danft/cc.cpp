#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;
const int N=11;

int n, v[21], p[11];
int dp[N][1<<N][N][N];
int seen[N][1<<N][N][N];
const int INF=0x3f3f3f3f;

int f(int u, int us, int st, int la) {
    if(seen[u][us][st][la])
        return dp[u][us][st][la];

    //cout<<u<<endl;
    int &ret=dp[u][us][st][la];
    ret=-INF;

    if(p[u]==st)
        ret=1;
    if(p[u]==la) {
        //cout<<u<<" "<<p[u]<<"@\n";
        ret=1;
        for(int i=0;i<n;i++) if(!(us & (1<<i))) {
            ret=max(ret, f(i, us | (1<<i), st, u)+1);
        }
    }
    else {
        if(!(us & (1<<p[u])))
            ret=max(ret, f(p[u], us | (1<<p[u]), st, u)+1);
    }
    seen[u][us][st][la]=1;
    return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
    int T;cin>>T;
    for(int tt=0;tt<T;tt++) {
        cin>>n;
        cout<<"Case #"<<tt+1<<": ";
        memset(seen, 0, sizeof seen);
        for(int i=0;i<n;i++) {
            cin>>p[i];
            p[i]--;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans, f(i, 1<<i, i, n));
        cout<<ans<<endl;
    }
	
	
	return 0;
}
