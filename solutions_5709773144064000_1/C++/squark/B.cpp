#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i0 = 1;
    int T;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        int i, j, k;
        R C, F, X;
        R ans;
        R T;
        R cur = 2;
        cin>>C>>F>>X;
        ans = X/2;
        T = 0;
        
        while(true){
            T += C/cur;
            cur += F;
            R newAns = T + X/cur;
            if(newAns >= ans)
                break;
            ans = newAns;
        }
        
        printf("Case #%d: ", i0);
        printf("%.10lf\n", ans);
    }
    return 0;
}
