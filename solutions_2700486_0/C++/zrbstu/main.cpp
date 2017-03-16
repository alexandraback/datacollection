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
LL f[1000][1000];

void init(){
    f[0][0] = 1; f[0][1] = 0;
    for(int i = 1; i < 1000; i++){
        f[i][0] = 1;
        for(int j = 1; j <= i; j++){
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
}

int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("input.txt", "r", stdin);
        freopen("ans.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    init();
    for(int icase = 1; icase <= T; icase++){
        cout << "Case #" << icase << ": ";
        int n, x, y;
        //scanf("%d %d %d", &n, &x, &y);
        cin >> n >> x >> y;
        double ans = 0;
        int level = (x + y) / 2;
        int num = 2 * level * level - level;
        if(n <= num + y){
            ans = 0;
        }
        else if(n >= num + 2 * (level + 1) - 1 + y){
            ans = 1;
        }
        else if(x == 0){
            if(n >= 2 * (level + 1) * (level + 1) - 1)
                ans = 1.0;
            else
                ans = 0;
        }
        else{
            double t = pow(0.5, y + 1);
            int len = 2 * (level + 1) - 1;
            for(int i = 1; i <= len && num + i + y <= n; i++){
                ans += t * f[y - 1 + i][y];
                t *= 0.5;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
