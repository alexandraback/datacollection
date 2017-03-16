#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int inf = 0x7fffffff;

char word[522000][11];
int len[522000];
int dn;

int f[51][51];
char s[51];

void read_dict()
{
    dn = 0;
    FILE *f = fopen("garbled_email_dictionary.txt", "r");
    while (fscanf(f, "%s", word[dn++]) != EOF);
    fclose(f);
    for (int i=0; i<dn; i++)
    {
        len[i] = strlen(word[i]);
    }
/*
    const char * x = "cxdejax";
    for (int i=0; i<dn; i++)
    {
        if (strlen(x) != len[i]) continue;
        int dif =0;
        for (int j=0; j<len[i]; j++)
            if (x[j] != word[i][j]) dif++;
        if (dif == 2) printf("%s\n", word[i]);

    }
*/
}

void cal(int pos, int di, int &first, int &last, int &cost)
{
    first = last = inf;
    cost = 0;
    int prev = -1000;
    for (int i=0; i<strlen(word[di]); i++)
    {
        if (word[di][i] != s[pos+i])
        {

            if (prev + 5 > i)
            {
                cost = inf;
                return;
            }
            if (first == inf) first = pos + i;
            last = pos + i;
            prev = i;
            cost++;
        }
    }
}

 int main()
 {
     read_dict();


   freopen("C-small-attempt0.in", "r", stdin);
//    freopen("A-large.in", "r", stdin);
    freopen("cout.txt", "w", stdout);

     int cas, T;
     scanf("%d", &T);
     int i, j, k, cost, first, last, n, ans;
     for (int cas=1; cas<=T; cas++)
     {
         scanf("%s", s);
         n = strlen(s);
         for (i=0; i<=n; i++)
            for (j=0; j<=n; j++)
              f[i][j] = inf;
         f[0][0] = 0;
         for (i=0; i<=n; i++)
         {
            for (j=0; j<dn; j++)
                if (i + len[j] <= n)
            {
                cal(i, j, first, last, cost);
                if (cost == inf) continue;

                for (k=0; k<=n && k<=max(0,first-5); k++)
                    if (f[i][k] != inf)
                    {
                        if (last == inf)
                        {
                            f[i+len[j]][k] = min(f[i+len[j]][k], f[i][k] +cost);
                            //printf("f[%d][%d]=%d\n", i+len[j], k, f[i+len[j]][k]);
                        }
                        else
                        {
                            f[i+len[j]][last] = min(f[i+len[j]][last], f[i][k] +cost);
                            //printf("f[%d][%d]=%d\n", i+len[j], last, f[i+len[j]][last]);
                        }
                    }
            }
         }
        ans = inf;
        for (k=0; k<=n; k++)
            ans = min(ans, f[n][k]);
        printf("Case #%d: %d\n", cas, ans);
     }
     return 0;
 }
/*
4
cxdejax
10
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
