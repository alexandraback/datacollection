#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 1000000005
#define eps 1e-10
#define PI acos(-1.0)
#define LL long long

using namespace std;

int K, L, S, la, lb;

char A[10], B[10], C[10];

double ans;

int maxc;

int Get()
{
    int temp = 0;
    for (int i = 0; i + lb <= S; i++)
    {
        int tag = 1;
        for (int j = 0; j < lb; j++)
            if (C[i + j] != B[j])
            {
                tag = 0;
                break;
            }
        temp += tag;
    }
    return temp;
}

void Dfs(int cur)
{
    if (cur >= S)
    {
        int temp = Get();
        ans = ans + 1.0 * temp;
        maxc = max(maxc, temp);
        return;
    }
    for (int j = 0; j < la; j++)
    {
        C[cur] = A[j];
        Dfs(cur + 1);
    }
    return;
}

int main()
{
    int T, cas = 0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s", A);
        scanf("%s", B);
        la = strlen(A); lb = strlen(B);
        ans = 0.0; maxc = 0;
        Dfs(0);
        for (int i = 0; i < S; i++)
            ans = ans / (1.0 * la);
        printf("Case #%d: %f\n", ++cas, 1.0 * maxc - ans);
    }
    return 0;
}
