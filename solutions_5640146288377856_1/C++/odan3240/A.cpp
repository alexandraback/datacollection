#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int R,C,W;
bool ok(int S) {
    for(int pos=1;pos<=C-W;pos++) {
        // [c,c+W]
        bool f=false;

        //printf("[debug] [%d,%d]\n",pos,pos+W-1);
        for(int i=pos;i<=pos+W-1;i++) {
            if((S>>i)&1) f=true;
            //cout<<"check "<<i<<" ";
        }
        //cout<<endl;

        if(!f) return false;
    }

    //cout<<"ok "<<S<<endl;
    return true;
}
void solve() {
    cin>>R>>C>>W;
    int ans=INF;
    rep(S,1<<C) {
        if(ok(S)) ans=min(__builtin_popcount(S)+W,ans);
    }

    cout<<R*ans<<endl;
}

int main() {
    int t;
    cin>>t;
    rep(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

