#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long ull;
int T;

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d", &T);
	for (int cse = 1; cse <= T; cse++)
	{
	    int g[100][100];
	    memset(g, 0, sizeof(g));
	    int b;
	    ull m;
	    scanf("%d %llu", &b, &m);
	    //printf("%d %llu\n", b, m);
	    for (int i = 0; i < b - 1; i++)
            for (int j = i + 1; j < b - 1; j++)
                g[i][j] = 1;
        ull maxp = 1;
        for (int i = 2; i < b; i++)
            maxp *= 2;
        //printf("%llu\n", maxp);
        bool flag;
        if (m > maxp)
        {
            flag = false;
            //im
        }
        else if (m == maxp)
        {
            flag = true;
            for (int i = 0; i < b - 1; i++)
                g[i][b - 1] = 1;
        }
        else
        {
            flag = true;
            for (int i = 1; m; i++)
            {
                //printf("%d ", m % 2);
                g[i][b - 1] = m % 2;
                m /= 2;
            }
        }
        //printf("\n");
        if (flag)
        {
            printf("Case #%d: POSSIBLE\n", cse);
            for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < b; j++)
                    printf("%d", g[i][j]);
                printf("\n");
            }
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE\n", cse);
        }
	}
	return 0;
}
