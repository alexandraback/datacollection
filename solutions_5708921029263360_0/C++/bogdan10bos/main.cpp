#include <bits/stdc++.h>

using namespace std;

#define FILE_IO

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int a[15][15][15];
int f[5];
int r1, r2, r3;
vector <piii> v, trp;
vector <int> prm;
int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);

        int J, P, S, K;
        scanf("%d%d%d%d", &J, &P, &S, &K);

        int ans = J * P * min(S, K);
        printf("%d\n", ans);
        memset(a, 0, sizeof(a));

        for(int j = 1; j <= J; j++)
            for(int p = 1; p <= P; p++)
                for(int i = 1; i <= min(S, K); i++)
                {
                    int mn = K + 1;
                    int mn2 = K + 1;
                    int ind = 0;
                    for(int s = 1; s <= S; s++)
                    {
                        if(a[0][p][s] < mn)
                        {
                            mn = a[0][p][s];
                            mn2 = a[j][0][s];
                            ind = s;
                        }
                        else if(a[0][p][s] == mn && a[j][0][s] < mn2)
                        {
                            mn = a[0][p][s];
                            mn2 = a[j][0][s];
                            ind = s;
                        }
                    }

                    int s = ind;
                    printf("%d %d %d\n", j, p, s);
                    a[j][0][s]++;
                    a[0][p][s]++;
                }
    }


    return 0;
}
