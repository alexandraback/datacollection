#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    int R,C,W;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d", &R, &C, &W);
        int ans = (C+W-1)/W + W-1;
        printf("Case #%d: %d\n", t, ans); 
    }
}

