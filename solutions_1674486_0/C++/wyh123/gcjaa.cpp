#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

int cnt[1010];
int m[1010];
int maz[1010][1010];
int n;
bool flag;

void dfs(int u) {
    for (int i=1; i<=n; i++) {
        if (maz[u][i]==1) {
            cnt[i]++;
            //vis[i]=1;
            dfs(i);
        }
    }
}
  
int main() {
    int T;    
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin >> T;
    for (int cas=1; cas<=T; cas++) {
        memset(maz,0,sizeof(maz));
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> m[i];
            int tmp;
            for (int j=1; j<=m[i]; j++) {
                cin >> tmp;
                maz[tmp][i]=1;
            }
        }
        flag=false;
        for (int i=1; i<=n; i++) {
            memset(cnt,0,sizeof(cnt));
            if (m[i]==0) {
                dfs(i);
            }
            for (int i=1; i<=n; i++) {
                if (cnt[i]>=2) { flag=true; break;}
            }
            if (flag) break;
        }
        cout << "Case #" << cas << ": ";
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;        
    }
    return 0;  
}     
