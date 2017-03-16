#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;


int T,XX,L;
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

bool solve()
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

    int S;
    if (suf[0] == 1) S = 1;
    else    S = 4;

    int X=1,Y,Z;
    bool stepI, stepJ;
    for (int x = 0; x < 4; x++) {
        Y = 1;
        for (int y = 0; y < 4; y++) {
            /*=========================================*/
            int i;
            stepI = stepJ = false;
            if (X != 2) {
                for (i = 0; i < L; i++) {
                    if (t[abs(X)][abs(pre[i])]*(X*pre[i]/abs(X)/abs(pre[i])) == 2) {
                        stepI = true;
                        break;
                    }
                }
            }else {
                stepI = true;
                i = -1;
            }


            int v = 1;
            for (i = i+1; i < L; i++) {
                v = t[abs(v)][cv[i]] * (v/abs(v));
                if (v == 3) {
                    stepJ = true;
                    break;
                }
            }

            i++;
            if ((i < L && t[abs(suf[i])][abs(Y)]*(Y*suf[i]/abs(Y)/abs(suf[i])) == 4) || (i == L && Y == 4)) {
                if ((XX-x-y-1) >= 0 && (XX-x-y-1)%S == 0 && stepI && stepJ) {
                    return true;
                }
            }
            /*=========================================*/
            Z = 1;
            for (int z = 0; z < 4; z++) {
                stepI = stepJ = false;
                if ( X != 2) {
                    for (i = 0; i < L; i++) {
                        if (t[abs(X)][abs(pre[i])]*(X/abs(X))*(pre[i]/abs(pre[i])) == 2) {
                            stepI = true;
                            break;
                        }
                    }
                } else {
                    stepI = true;
                    i = -1;
                }


                int j;
                for (i = i+1, j = 0; i < L && j < L; j++) {
                    int tmp = t[abs(suf[i])][abs(Z)]*(Z*suf[i]/abs(Z)/abs(suf[i]));
                    if (t[abs(tmp)][abs(pre[j])]*(tmp*pre[j]/abs(tmp)/abs(pre[j])) == 3) {
                        stepJ = true;
                        break;
                    }
                }

                j++;
                if ((j < L && t[abs(suf[j])][abs(Y)]*(Y*suf[j]/abs(Y)/abs(suf[j])) == 4) || (j == L && Y == 4)) {
                    if ((XX-x-y-z-2) >= 0 && (XX-x-y-z-2)%S == 0 && stepI && stepJ) {
                        return true;
                    }
                }

                Z = t[abs(Z)][abs(suf[0])] * (Z/abs(Z)) * (suf[0]/abs(suf[0]));
            }
            /*=========================================*/
            Y = t[abs(Y)][abs(suf[0])] * (Y/abs(Y)) * (suf[0]/abs(suf[0]));
        }
        X = t[abs(X)][abs(suf[0])] * (X/abs(X)) * (suf[0]/abs(suf[0]));
    }

    return false;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    initial_table();

    scanf(" %d",&T);
    for (cas = 1; cas <= T; cas++) {
        scanf(" %d %d",&L, &XX);
        scanf(" %s",&c);

        bool res = solve();

        if (res)printf("Case #%d: YES\n",cas);
        else    printf("Case #%d: NO\n",cas);
    }

    return 0;
}
