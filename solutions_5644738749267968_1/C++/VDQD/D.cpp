#include <bits/stdc++.h>
using namespace std;

const int ZZ = 1000000;

int N;
int a[1111], b[1111];

void runTest(){
    scanf("%d", &N);
    double x;
    for (int i = 0; i < N; i++){
        scanf("%lf", &x);
        a[i] = int(x * ZZ + 1e-4);
    }
    for (int i = 0; i < N; i++){
        scanf("%lf", &x);
        b[i] = int(x * ZZ + 1e-4);
    }
    sort (a, a + N);
    sort (b, b + N);
    int S_WAR = 0, S_DWAR = 0;
    int ib = 0, db = 0;
    for (int i = 0; i < N; i++){
        //printf("%d %d\n", a[i], b[i]);
        while (ib < N && a[i] > b[ib]) ib++;
        //
        if (ib == N) S_WAR++;
        else ib++;
        //
        if (a[i] > b[db]) S_DWAR++, db++;
    }
    printf("%d %d\n", S_DWAR, S_WAR);
}

int main(){
    freopen("D.inp","r",stdin);
    freopen("D.out","w",stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        fprintf(stderr, "Test %d\n", i);
        runTest();
    }
    return 0;
}
