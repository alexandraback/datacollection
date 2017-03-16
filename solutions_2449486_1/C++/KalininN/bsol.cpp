#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 105;

int p[maxn][maxn];
int n, m;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) scanf("%d", &p[i][j]);
        }
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool canv = true;
                for (int k = 0; k < n; k++) canv = canv && (p[k][j] <= p[i][j]);
                bool canh = true;
                for (int k = 0; k < m; k++) canh = canh && (p[i][k] <= p[i][j]);
                can = can && (canv || canh);
            }
        }
        printf("Case #%d: ", T);
        printf("%s\n", (can ? "YES" : "NO"));
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
