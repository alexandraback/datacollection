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

int R, C, W;



int main(){
    int tt;
    cin >> tt;
    
    for (int tcas = 1; tcas <= tt; tcas++){
        cin >> R >> C >> W;
        int ans = 0;
        if (W == 1) ans = C;
        else {
            for (int i = W-1; i<C; i+=W)
                if (i + W <C)
                    ans++;
                else {
                    if (C-(i-W)-1 >= W+1)
                        ans+=W+1;
                    else ans += W;
                }
        }
        printf("Case #%d: ", tcas);
        cout << ans * R << endl;
    }
}
        
