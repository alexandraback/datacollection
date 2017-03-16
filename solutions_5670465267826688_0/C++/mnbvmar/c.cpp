#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxLen = 10005;
char str[MaxLen];
int N;
LL X;

void input(){
    scanf("%d%lld%s", &N, &X, str);
}

const int transition[4][4] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

int transform(int x, int y){
    bool addFour = (x>=4) ^ (y>=4);
    
    return transition[x%4][y%4] ^ (addFour?4:0);
}

char convtoint(char c){
    if(c == 'i') return 1;
    if(c == 'j') return 2;
    if(c == 'k') return 3;
    assert(false);
}

void test(){
    input();

    static const int Infty = 1e9;

    int shortestPref = Infty, shortestSuf = Infty;

    int finalQuat = 0;
    for(int i = 0; i < N; i++){
        finalQuat = transform(finalQuat, convtoint(str[i]));
    }
    int finalfinalQuat = 0;
    for(LL i = 0; i < X%4; i++){
        finalfinalQuat = transform(finalfinalQuat, finalQuat);
    }
    if(finalfinalQuat != 4){
        printf("NO\n");
        return;
    }

    int current = 0;
    for(int i = 0; i < 4*N; i++){
        current = transform(current, convtoint(str[i%N]));
//        printf("after #%d current is %d\n", i, current);
        if(current == 1){
            shortestPref = i+1;
            break;
        }
    }

    current = 0;
    for(int i = 0; i < 4*N; i++){
        current = transform(convtoint(str[N-i%N-1]), current);
        if(current == 3){
            shortestSuf = i+1;
            break;
        }
    }

    if(shortestPref == Infty || shortestSuf == Infty ||
            shortestPref + shortestSuf > N*X){
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        test();
    }
}
