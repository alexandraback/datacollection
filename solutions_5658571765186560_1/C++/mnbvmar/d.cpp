#include <bits/stdc++.h>

using namespace std;

int X, R, C;

void input(){
    scanf("%d%d%d", &X, &R, &C);
}

void test(){
    input();

    if(C > R) swap(R, C);

    bool ok = false;

    switch(X){
        case 1:
            ok = (R >= 1 && C >= 1);
            break;

        case 2:
            ok = (R >= 2 && C >= 1);
            break;

        case 3:
            ok = (R >= 3 && C >= 2);
            break;

        case 4:
            ok = (R >= 4 && C >= 3);
            break;

        case 5:
            ok = (R >= 5 && C >= 4) || (R >= 10 && C >= 3);
            break;

        case 6:
            ok = (R >= 6 && C >= 4);
            break;

        default:
            ok = false;
            break;
    }

    if((R*C) % X != 0) ok = false;

    printf(ok ? "GABRIEL\n" : "RICHARD\n");
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        test();
    }
}
