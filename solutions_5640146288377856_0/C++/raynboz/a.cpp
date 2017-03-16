#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>

using namespace std;

int solve() {
    int R, C, W;
    scanf("%d %d %d\n", &R, &C, &W);
    int L = 0;
    if(C % W != 0) L = 1;
    return R*(C/W) + (W-1) + L;
}

int main() {
    freopen("Ain.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    int T;
    cin >> T;

    for(int i=1; i<=T; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
