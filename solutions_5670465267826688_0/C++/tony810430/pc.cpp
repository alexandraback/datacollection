#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;


int T,X,L;
int cas;
char c[10005];
int cv[10005];
int pre[10005];
int suf[10005];

int t[5][5];

void initial_table()
{
    t[1][1] = 1, t[1][2] = 2, t[1][3] = 3, t[1][4] = 4;
    t[2][1] = 2, t[2][2] =-1, t[2][3] = 4, t[2][4] =-3;
    t[3][1] = 3, t[3][2] =-4, t[3][3] =-1, t[3][4] = 2;
    t[4][1] = 4, t[4][2] = 3, t[4][3] =-2, t[4][4] =-1;
}

void print(int v)
{
    int V = abs(v);
    if (v < 0)printf("-");
    if (V == 1)printf("1");
    else if(V == 2)printf("i");
    else if(V == 3)printf("j");
    else printf("k");
}
/*
void check()
{
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            print(t[i][j]);
            printf(" ");
        }
        puts("");
    }
}
*/
void solve()
{
    for (int i = 0; i < L; i++) {
        cv[i] = c[i]-'i'+2;
    }

    pre[0] = cv[0];
    for (int i = 1; i < L; i++) {
        int v = abs(pre[i-1]);
        pre[i] = t[v][cv[i]] * (v/pre[i-1]);
    }

    suf[L-1] = cv[L-1];
    for (int i = L-2; i >= 0; i--) {
        int v = abs(suf[i+1]);
        suf[i] = t[cv[i]][v] * (v/suf[i+1]);
    }
/*
    for (int i = 0; i < L; i++) {
        print(cv[i]);
        printf(" ");
        print(pre[i]);
        printf(" ");
        print(suf[i]);
        puts("");
    }
*/
}

bool solve_small()
{
    for (int i = 0; i < L*X; i++) {
        cv[i] = c[i%L]-'i'+2;
    }

    int v = 1, step = 2;
    for (int i = 0; i < L*X; i++) {
        int V = abs(v);
        v = t[V][cv[i]] * (v/V);

        if (v == step) {
            v = 1, step = step+1;
        }
    }

    if (v == 1 && step >= 5)
        return true;

/*

    int i;
     v = 1;
    for (i = 0; i < L*X; i++) {
        int V = abs(v);
        v = t[V][cv[i]] * (v/V);

        if (v == 2) break;
    }


    int j;
    v = 1;
    for (j = L*X-1; j >= 0; j--) {
        int V = abs(v);
        v = t[cv[j]][V] * (v/V);

        if (v == 4)break;
    }


    if (j-i-1 <= 0)return false;
    v = 1;
    for (i = i+1; i < j; i++) {
        int V = abs(v);
        v = t[cv[i]][V] * (v/V);
    }

    return (v==3);*/
}


int main()
{
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("C-small-attempt4.out", "w", stdout);

    initial_table();

    scanf(" %d",&T);
    for (cas = 1; cas <= T; cas++) {
        scanf(" %d %d",&L, &X);
        scanf(" %s",&c);

        //solve();
        bool res = solve_small();
        if (res)printf("Case #%d: YES\n",cas);
        else    printf("Case #%d: NO\n",cas);
    }

    return 0;
}
