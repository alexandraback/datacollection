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
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second

ull r,t;

ull cale(ull mid) {
    return ((2 * r - 3) * mid + 2 * mid * (mid + 1));
}

void gao(){  
  //  cout << t << endl;
    ull low=0,high=min(t*2/r,(ull)sqrt(t*2)),mid,ans,tmp;
    while (low<=high){
       // if (low%2==1 && high%2==1) low++;
        mid=(low+high)/2;
        tmp=cale(mid);
        if (tmp>t) high=mid-1;  
        else low=mid+1,ans=mid;  
    }
    cout << ans << endl;
}


int main() {
    freopen("a.in","r",stdin);
    freopen("aa.txt","w",stdout);
    int T,cas=0;
    cin >> T;
    while (T--) {
        cin >> r >> t;
        cas++;
        cout << "Case #" << cas << ": ";
        gao();
    }
    return 0;
}
