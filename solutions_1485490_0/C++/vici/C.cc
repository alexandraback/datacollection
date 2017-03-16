#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 105
using namespace std;
typedef __int64 ll;
ll ac[maxn], av[maxn];
ll bc[maxn], bv[maxn];

ll cc[maxn];

int main(){
    freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-ans.txt", "w", stdout);
  //  freopen("C-large.in", "r", stdin);  freopen("C-large-ans.txt", "w", stdout);
    int test_case;

    int n, m;


    scanf("%d", &test_case);
    for(int _t = 1; _t <= test_case; _t++){
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d", &ac[i], &av[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%I64d%I64d", &bc[i], &bv[i]);
        }
        ll res = 0, cost;
        if(n == 1){
            for(int i=0;i<m;i++){
                if(bv[i] == av[0]){
                    cost = min(ac[0], bc[i]);
                    ac[0] -= cost;
                    bc[i] -= cost;
                    res += cost;
                    if(ac[0] == 0) break;
                }
            }
        }
        else if(n == 2){
            ll tr = 0, tc;
            for(int s=0;s<m;s++){
                for(int i=0;i<m;i++) cc[i] = bc[i];
                tr = 0;
                tc = ac[0];
                for(int i=0;i<=s;i++){
                    if(bv[i] == av[0]){
                        cost = min(tc, cc[i]);
                        tc -= cost;
                        cc[i] -= cost;
                        tr += cost;
                        if(tc == 0) break;
                    }
                }
                tc = ac[1];
                for(int i=s;i<m;i++){
                    if(bv[i] == av[1]){
                        cost = min(tc, cc[i]);
                        tc -= cost;
                        cc[i] -= cost;
                        tr += cost;
                        if(tc == 0) break;
                    }
                }
                res = max(res, tr);
            }
        }
        else if(n == 3){
            ll tr = 0, tc;
            for(int s1=0;s1<m;s1++){
                for(int s2=s1;s2<m;s2++){
                    for(int i=0;i<m;i++) cc[i] = bc[i];
                    tr = 0;
                    tc = ac[0];
                    for(int i=0;i<=s1;i++){
                        if(bv[i] == av[0]){
                            cost = min(tc, cc[i]);
                            tc -= cost;
                            cc[i] -= cost;
                            tr += cost;
                            if(tc == 0) break;
                        }
                    }
                    tc = ac[1];
                    for(int i=s1;i<=s2;i++){
                        if(bv[i] == av[1]){
                            cost = min(tc, cc[i]);
                            tc -= cost;
                            cc[i] -= cost;
                            tr += cost;
                            if(tc == 0) break;
                        }
                    }
                    tc = ac[2];
                    for(int i=s2;i<m;i++){
                        if(bv[i] == av[2]){
                            cost = min(tc, cc[i]);
                            tc -= cost;
                            cc[i] -= cost;
                            tr += cost;
                            if(tc == 0) break;
                        }
                    }
                    //cout << s1 << "," << s2 << ":" << tr << endl;
                    res = max(res, tr);
                }
            }
        }
        printf("Case #%d: %I64d\n", _t, res);
    }
    return 0;
}
