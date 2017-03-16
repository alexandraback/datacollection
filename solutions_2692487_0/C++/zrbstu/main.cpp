#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1)

const int maxn = 100 + 5;
int a[maxn];

int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("input.txt", "r", stdin);
        freopen("ans.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    for(int icase = 1; icase <= T; icase++){
        cout << "Case #" << icase << ": ";
        int u, n;
        cin >> u >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int num = 0, ans = n;
        for(int i = 0; i < n; i++){
            if(u > a[i]){
                u += a[i];
            }
            else{
                ans = min(ans, n - i + num);
                num++;
                u = u * 2 - 1;
                if(num > ans) break;
                i--;
            }
        }
        ans = min(ans, num);
        cout << ans << endl;
    }
    return 0;
}
