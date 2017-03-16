#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int f[1<<10][1<<10];
int R, C, W;

int calc(int st, int p){
    int sum = 0;
    
    for (int i = p+1; i < C; i++)
    if (st&(1<<i)) break;
    else sum++;
    if (sum >= W) return -2;
    
    int tmp = 0;
    for (int i = p-1; i>=0; i--)
    if (st&(1<<i)) break;
    else tmp++;
    if (tmp >= W) return -2;
    
    sum+=tmp;
    if (sum+1 < W) return -1;
    if (sum + 1 ==W) return W - 1;
    else return W;
}


int main(){
    int tt;
    cin >> tt;
    for (int tcas = 1; tcas <= tt; tcas++){
        cin >> R >> C >> W;
        
        int ans = C;
        for (int st = 1; st<(1<<C); st++)
            {
                int tmp = __builtin_popcount(st);
                int nxt = -1;
                for (int i = 0; i < C; i++)
                    if ((1<<i)&st){
                        int put = calc(st, i);
                        if (put == -1) continue;
                        if (put == -2){
                            nxt = -1;
                            break;
                        }
                        nxt = max(put, nxt);
                    }
                if (nxt == -1) continue;
                ans = min(tmp+nxt, ans);
            }
        printf("Case #%d: ", tcas);
        cout << ans * R << endl;
    }
}
        
