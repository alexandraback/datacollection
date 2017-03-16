#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int T ;scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int arr[1000], n;
        scanf("%d", &n);
        for(int lx = 0;lx < n;lx++)
            scanf("%d", arr+lx);
        int ans = 1000;
        for(int lx = 1;lx <= 1000;lx++){
            int cnt = lx;
            for(int ly = 0;ly < n;ly++)
                cnt += (arr[ly]+lx-1)/lx - 1;
            ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", lt, ans);
    }
    return 0;
}       
