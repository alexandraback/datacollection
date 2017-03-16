#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

#define maxn 1000000
using namespace std;

int h[2550];
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int kase=1;kase<=T;kase++)
    {
        for (int i=0;i<2550;i++) h[i] = 0;
        int n;
        scanf("%d", &n);
        for (int i=0;i<2*n-1;i++)
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d", &x);
                h[x]++;
            }
        printf("Case #%d:", kase);
        for (int i=0;i<2550;i++)
            if (h[i] % 2 == 1) printf(" %d", i);
        printf("\n");
    }
    return 0;
}
