#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int N=4;

char a[N+2][N+2], t[256];

bool judge(int mask) {
    for (int i=1; i<=N; i++) {
        bool ok=true;
        for (int j=1; j<=N; j++)
            if ((a[i][j]&mask)==0) {
                ok=false;
                break;
            }
        if (ok) {
            return true;
        }
    }
    for (int j=1; j<=N; j++) {
        bool ok=true;
        for (int i=1; i<=N; i++)
            if ((a[i][j]&mask)==0) {
                ok=false;
                break;
            }
        if (ok) {
            return true;
        }
    }
    {
        bool ok=true;
        for (int i=1; i<=N; i++)
            if ((a[i][i]&mask)==0) {
                ok=false;
                break;
            }
        if (ok) {
            return true;
        }
        ok=true;
        for (int i=1; i<=N; i++)
            if ((a[i][N-i+1]&mask)==0) {
                ok=false;
                break;
            }
        if (ok) {
            return true;
        }
    }
    return false;
}

bool isfull() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            if (a[i][j]==0) {
                return false;
            }
    }
    return true;
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int total, tt=0;
    scanf("%d", &total);
    t['X']=1;
    t['O']=2;
    t['T']=3;
    while (total--) {
        for (int i=1; i<=4; i++) {
            scanf("%s", a[i]+1);
        }

        for (int i=1; i<=N; i+=1) {
            for (int j=1; j<=N; j+=1) {
                a[i][j]=t[a[i][j]];
            }
        }
        printf("Case #%d: ", ++tt);
        if (judge(1)) {
            printf("X won\n");
        } else if (judge(2)) {
            printf("O won\n");
        } else if (isfull()) {
            printf("Draw\n");
        } else {
            printf("Game has not completed\n");
        }
    }
}