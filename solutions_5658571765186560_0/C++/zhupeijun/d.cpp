#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int X, R, C;
        scanf("%d %d %d", &X, &R, &C);
        int ans;
        if(R > C) swap(R, C);
        if(X == 1) ans = 0;
        else if(X == 4) {
            if((R == 3 && C == 4) || (R == 4 && C == 4)) ans = 0;
            else ans = 1;
        }
        else if(X == 3) {
            if ((R == 2 && C == 3) || (R == 3 && C == 4) ||
                (R == 3 && C == 3)) ans = 0;
            else ans = 1;
        } else if(X == 2) {
            if( (R == 1 && C == 2) || (R == 1 && C == 4) ||
                (R == 2 && C == 2) || (R == 2 && C == 3) ||
                (R == 2 && C == 4) || (R == 3 && C == 4) ||
                (R == 4 && C == 4)) ans = 0;
            else ans = 1;
        }
        printf("Case #%d: ", ci);
        if(ans == 0) printf("GABRIEL\n");
        else printf("RICHARD\n");
    }
    return 0;
}

