#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int _T;
    scanf("%d",&_T);
    for(int T = 0; T < _T; T++){
        printf("Case #%d: ", T+1);
        int C, D, V;
        scanf("%d%d%d",&C,&D,&V);
        int coins[D];
        for(int i = 0; i < D; i++) scanf("%d",&coins[i]);
        sort(coins, coins + D);
        int max = 0, cur = 0, ans = 0;
        while(max < V){
            if(cur < D){
                if(max + 1 < coins[cur]){
                    ans ++;
                    max += C * (max + 1);
                }
                else{
                    while(max + 1 >= coins[cur] && cur < D){
                        max += C * coins[cur];
                        cur ++;
                    }
                }
            }
            else{
                ans ++;
                max += C * (max + 1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
