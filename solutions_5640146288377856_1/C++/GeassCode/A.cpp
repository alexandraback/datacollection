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
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
    int N;
    cin >> N;
    for (int t = 1; t <= N; t++){
        cin >> R >> C >> W;
        int ans = 0;
        for (int i = W-1; i<C; i+=W)
            if (i + W <C)
                ans++;
            else {
                if (C-i-2 >= 0)
                    ans+=W+1;
                else ans += W;
            }
        if (W == 1) ans = C;
        printf("Case #%d: %d\n", t, ans * R);
    }
    return 0;
}

