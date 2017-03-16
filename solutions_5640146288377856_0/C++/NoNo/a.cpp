#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>

#define lld long long
#define INF 2100000000
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int, int>
#define lb lower_bound
#define ub upper_bound

using namespace std;

int main(){
    int T, cas = 0, n, m, k;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int ans;
        if (m == k){
            ans = k;
        } else {
            int i = k;
            ans = 1;
            while(i + k < m) i += k, ans++;
            if (i == m) ans += k - 1; else ans += k;
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }

}
