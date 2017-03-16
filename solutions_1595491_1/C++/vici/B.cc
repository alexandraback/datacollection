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
#define maxn 111
using namespace std;

int state[maxn];

int main(){
  //  freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("BLarge.out", "w", stdout);
    int t, n, s, p, a;
    int mid, high;
    scanf("%d", &t);
    for(int _ca=1;_ca<=t;_ca++){
        scanf("%d%d%d", &n, &s, &p);
        memset(state, 0, sizeof(state));
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            for(int x=0;x<=10;x++){
                for(int y=x;y<=10;y++){
                    int z = a - x - y;
                    if(z - x > 2) continue;
                    if(z - x == 2){
                        if(z >= p) state[i] |= 1;
                    }
                    else{
                        if(z >= p) state[i] |= 2;
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            if(s == 0) break;
            if(state[i] == 1){
                s--;
                res++;
            }
        }
        for(int i=0;i<n;i++){
            if(state[i] == 3){
                res++;
                if(s == 0) continue;
                else s--;
            }
        }
        for(int i=0;i<n;i++){
            if(state[i] == 0 && s > 0) s--;
        }
        for(int i=0;i<n;i++){
            if(state[i] == 2){
                if(s > 0) s--;
                else res++;
            }
        }
        printf("Case #%d: %d\n", _ca, res);
    }
    return 0;
}
