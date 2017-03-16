#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

long double C[1100][1100], D[1100][1100];

void init() {
    C[1][0] = 0.5;
    C[1][1] = 0.5;
    for (int i = 2; i <= 1000;++i) {
        C[i][0] = C[i-1][0]*0.5;
        C[i][i] = C[i][0];
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j])*0.5;
    }

    D[1][0] = 1;
    D[1][1] = 0.5;
    for (int i = 2; i <= 1000; ++i) {
        D[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            D[i][j] = D[i][j-1]*(i-j+1)*0.5/j;
    }
}

int main() {
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    int T, c;
    cin>>T;
    init();
    //cout << C[3][0] << " " << C[3][1] << " " << C[3][2] << " " << C[3][3]<< endl;
    for (c = 0;c < T; ++c) {
        int n, N, x, y;
        cin>>N>>x>>y;
        n = (abs(x)+abs(y))/2+1;
        if (N >= 2*n*n-n) {
            printf("Case #%d: ", c+1);
            cout << "1.0" << endl;
            continue;
        }
        if (N <= 2*(n-1)*(n-1)-n+1) {
            printf("Case #%d: ", c+1);
            cout << "0.0" << endl;
            continue;
        }
        N -= 2*(n-1)*(n-1)-n+1;
        if (N < y+1) {
            printf("Case #%d: ", c+1);
            cout << "0.0" << endl;
            continue;
        }
        if (x == 0) {
            printf("Case #%d: ", c+1);
            cout << "0.0" << endl;
            continue;
        }
        y = abs(y);
        //cout << N << " " << y << endl;
        long double ans = 0, sum = 0;

        for (int i = 0; i <= min(N, 2*n-2); ++i) {
            if (N-i <= 2*n-2) {
                if (N-i == 2*n-2 || i == 2*n-2)
                    sum += D[N][2*n-2];
                else sum += C[N][i];
            }
        }

        for (int i = 0; i < y+1; ++i) {
            if (N-i <= 2*n-2) {
                if (N-i == 2*n-2 || i == 2*n-2)
                    ans += D[N][2*n-2];
                else ans += C[N][i];
            }
        }
        printf("Case #%d: ", c+1);
        cout << 1.0-ans/sum << endl;
    }
    return 0;
}
