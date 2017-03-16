#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef long long LL;
using namespace std;

char C[10], J[10];
char in[20];
int ten[] = {1, 10, 100, 1000};

int anscc, ansjj, ansmin;
void dfs(int pt)
{
    if (pt == strlen(in))
    {
        if (strcmp(in, "1920") == 0)
            int aa = 5;

        int n = atoi(in);
        int or = strlen(C);
        int cc = n / ten[or];
        int jj = n % ten[or];

        int diff = abs(cc - jj);
        if (diff < ansmin)
        {
            anscc = cc;
            ansjj = jj;
            ansmin = diff;
        }
        else if (diff == ansmin)
        {
            if (anscc > cc)
            {
                anscc = cc;
                ansjj = jj;
            }
            else if (ansjj > jj)
            {
                anscc = cc;
                ansjj = jj;
            }
        }

        return;
    }

    if (in[pt] == '?')
    {
        for (int i = 0; i < 10; i++)
        {
            in[pt] = i + '0';
            dfs(pt+1);
            in[pt] = '?';
        }
    }
    else
        dfs(pt+1);
}

void solve()
{
    scanf("%s %s", C, J);
    strcpy(in, C);
    strcat(in, J);
    
    ansmin = 100000000;
    dfs(0);
    printf("%0*d %0*d\n", strlen(C), anscc, strlen(J), ansjj);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int cases;
    scanf("%d\n", &cases);

    for(int i = 1; i <= cases; i++)
    {
        printf("Case #%d: ", i);
        solve();        
    }
	return 0;

}
