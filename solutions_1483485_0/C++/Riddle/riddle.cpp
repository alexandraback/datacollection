#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long LL;

LL X, Y;
int e_gcd(int a, int b){
    if(b == 0){
        X = 1;
        Y = 0;
        return a;
    }
    int d = e_gcd(b, a % b);
    LL l = X;
    X = Y;
    Y = l - (a / b) * Y;
    return d;
}

LL calc(LL X, LL Y){
    if(X >= 0 && Y >= 0) return max(X, Y);
    if(X < 0) return Y - X;
    return X - Y;
}

LL solve(LL X, LL Y, LL ax, LL bx, LL d){
    LL Min = 1LL << 60;
    for(int i = -10000; i <= 10000; ++i){
        LL tX = ax * i + X, tY = -i * bx + Y;
        Min = min(Min, calc(tX, tY));
    }
    return Min;
}

double B[100000];

int main(){

    B[0] = 1;
    double pre = B[0];
    double x = 30;
    for(int i = 1; i < 1000000000; ++i){
        int p = i % 2, q = p ^ 1;
        B[p] = (1.0 + (i - 1.0)/ B[q]) * x /i;

        if(i % 100==0)
         { printf(" %d %.10f %.10f\n", i,  B[p], B[p]/pre); pre= B[p];getchar();}
    }
    int T;scanf("%d", &T);
    while(T --){
        int A, B, a, b;
        scanf("%d%d%d%d", &A, &B, &a, &b);
       // A = rand() % 1000, B = rand() %1000, a = rand()%1000 + 1, b = rand() % 1000 + 1;
        if(A > B) swap(A, B);
        if(A == B){
            puts("0");
            continue;
        }
        int cha = B - A;
        int d = e_gcd(a, b);
        if(cha % d){
            puts("-1");
            continue;
        }
        LL Min = 1LL << 60;
        cha /= d;
        X *= cha, Y *= cha;
        LL ax = b / d, bx = a / d;
        LL temp = (Y - X) / (ax + bx);
        for(LL i = temp - 100; i <= temp + 100; ++i){
            LL tX = X + i * ax, tY = Y - i * bx;
            Min = min(Min, calc(tX, tY));
        }
        cout << Min <<' '<< solve(X, Y, ax, bx, d)<< endl;
        if(Min != solve(X, Y, ax, bx, d)){
            printf("%d %d %d %d\n", A, B, a, b);
            getchar();
        }
    }
}

