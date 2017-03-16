#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
#define get getchar

inline int scan() {
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

const int maxn = (1<<16) + 1000;
int dp[maxn];

int main() {
        
    ios::sync_with_stdio(false);
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t;
    cin >> t;
    int ca = 0;
    while (t--) {
        ca++;
        int n; cin >> n;
        string a[20][2];

        for (int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];
        dp[0] = 0;

        for (int mask = 1; mask < (1<<n); mask++) {
            dp[mask] = 0;
            if (__builtin_popcount(mask) == 1) dp[mask] = 0;
            else {
                for (int i = 0; i < n; i++) {
                    if (mask&(1<<i)) {
                        dp[mask] = max(dp[mask],dp[mask-(1<<i)]);
                        bool f1,f2;
                        f1 = f2 = false;
                        for (int j = 0; j < n; j++) {
                            if (j == i) continue;
                            int gg = (mask&(1<<j));
                            if (!gg) continue;
                            if (a[j][0].compare(a[i][0]) == 0)
                                f1 = true;
                            if (a[j][1].compare(a[i][1]) == 0)
                                f2 = true;
                        }
                        if (f1 and f2) {
                            dp[mask] = max(dp[mask],dp[mask-(1<<i)] + 1);
                        }
                    }
                }
            }

        }

        int id = 1<<n;
        id--;
        cout << "Case #" << ca << ": " << dp[id] << endl;
    }
    
    return 0;
        
}