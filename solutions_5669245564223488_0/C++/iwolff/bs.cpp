#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
//~ #include <unordered_map>
//~ #include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long
#define SZ(x) (int)((x).size())

vector<string> v;
int N,n,dp[1<<11][28];

int solve(int mask, int us, int last) {
    if (mask == N) return 1;
    int &r = dp[mask][last];
    if (r != -1) return r;
    
    r = 0;
    for (int i=0; i<n; i++)
        if ((mask & (1<<i)) == 0) {
            int newus = us, l = last;
            bool flag = true;
            for (int j=0; j<SZ(v[i]); j++) {
                int ch = v[i][j]-'a';
                if (l != 26 && ch != l && (newus&(1<<ch)) != 0) { flag = false; break; }
                newus |= (1<<ch);
                l = ch;
            }
            if (flag) r += solve(mask|(1<<i),newus,l);
        }
    
    return r;
}

int main() {
    cin.sync_with_stdio(false);
    int nt,nteste=1;
    cin>>nt;
    while (nt--) {
        cin>>n;
        v.resize(n);
        for (int i=0; i<n; i++)
            cin>>v[i];
        memset(dp,-1,sizeof(dp));
        N = (1<<n)-1;
        cout << "Case #" << nteste++ << ": " << solve(0,0,26) << endl;
    }
    
    return 0;
}
