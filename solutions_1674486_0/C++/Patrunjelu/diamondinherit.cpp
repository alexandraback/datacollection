#include <stdio.h>
using namespace std;
const int maxval = 0x3f3f3f3f;

int n;
int matrice[2000][2000];
int matinit[2000][2000];

void emptymat(int n)
{
    for (int i = 1; i <=n; ++i)
    {
        for (int j =1; j<=n; ++j)
        {
            matrice[i][j] = maxval;
            matinit[i][j] = maxval;
        }
    }
}

long minimum(long a, long b)
{
    if (a < b) return a;
    else return b;
}

void FLOYROYD()
{
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <=n; ++i)
        for (int j = 1; j<=n; ++j)
        matrice[i][j] = minimum(matrice[i][j], matrice[i][k] + matrice[k][j]);
}

bool HasTwoWays(int nods, int nodd)
{
    int countt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (matinit[nods][i] != maxval)
        {
                if (matrice[i][nodd] != maxval)
                {
                    ++countt;
                }
                if (i == nodd)
                    ++countt;
        }
    }
    if (countt >= 2)
        return true;
    else
    return false;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("diamondinh.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d", &n);
        int numinh;
        emptymat(n);
        bool foundtwoways = false;
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &numinh);
            int sec;
            for (int q = 0; q < numinh; ++q)
            {
                scanf("%d", &sec);
                matrice[sec][j] = 1;
                matinit[sec][j] = 1;
            }
        }
         FLOYROYD();
                for (int z = 1; z <= n; ++z)
                {
                    for (int x = 1; x <= n; ++x)
                    {
                        if ((HasTwoWays(z,x)) && (!foundtwoways))
                        {
                            printf("Case #%d: %s\n", i, "Yes");
                            foundtwoways = true;
                            break;
                        }
                    }
                }
         if (!foundtwoways)
                {
                    printf("Case #%d: %s\n", i, "No");
                }

                /*for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <=n; ++j)
                    {
                        printf("%d ", matrice[i][j]);
                    }
                    printf("\n");
                }*/
    }

}
