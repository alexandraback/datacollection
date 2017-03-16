#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<limits>
#include<utility>
#define PB push_back
#define MP make_pair
#define _F first
#define _S second
#define PP system("PAUSE");

using namespace std;

void solve(void){
    int X, Y;
    scanf("%d%d", &X, &Y);
    if(X > 0){
        for(int i = 0; i < X*2; i++){
            if(i&1) printf("E");
            else printf("W");
        }
    }
    else{
        for(int i = 0; i < -(X*2); i++){
            if(i&1) printf("W");
            else printf("E");
        }
    }

    if(Y > 0){
        for(int i = 0; i < Y*2; i++){
            if(i&1) printf("N");
            else printf("S");
        }
    }
    else{
        for(int i = 0; i < -(Y*2); i++){
            if(i&1) printf("S");
            else printf("N");
        }
    }
    puts("");
    return;
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
