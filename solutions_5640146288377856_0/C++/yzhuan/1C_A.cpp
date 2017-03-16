#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int get_min(int row_len, int w) {
    int cursor = w;
    int cnt = 0;
    while(cursor <= row_len) {
        cnt ++;
        cursor += w;
    }
    return cnt;
}

int get_max(int row_len, int w) {
    int cursor = w;
    int cnt = 0;
    while(cursor <= row_len) {
        cnt ++;
        cursor += w;
    }
    if(cursor - w == row_len) cnt --;
    cnt += w;
    return cnt;
}

int main(int argc, char* argv[]) {
    // freopen("1c_a.large.in", "r", stdin);
    // freopen("1c_a.large.out", "w", stdout);
    freopen("1c_a.small.in", "r", stdin);
    freopen("1c_a.small.out", "w", stdout);
    
    int T;
    int R,C,W;
    while(scanf("%d",&T)!=EOF) {
        for(int k=1; k<=T; k++) {
            scanf("%d%d%d",&R,&C,&W);
            int total = 0;
            total += (R-1) * get_min(C, W);
            total += get_max(C, W);
            printf("Case #%d: %d\n",k,total);
        }
    }
    return 0;
}
