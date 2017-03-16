#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int dp[3000000];
bool mk[20];
int a[600];

void findans(int find, int n)
{
    int tmp = find;
    while(tmp > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (mk[i])continue;
            if (tmp - a[i] >= 0)
            {
                if (dp[tmp - a[i]] >= 1)
                {
                    mk[i] = true;
                    printf("%d ", a[i]);
                    tmp -= a[i];
                }
            }
        }
    }
    printf("\n");
}

void run()
{
    
    int n = 0;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int find = -1;
    for (int j = 0; j < n; j++)
    {
        for (int i = sum; i >= 0; i--)
        {
            if (i > 0 && dp[i] == 0)continue;
            int k = i + a[j];
            dp[k]++;
        }
    }
    
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i] >= 2)
        {
            find = i;
            break;
        }
    }
    
    //printf("find %d\n", find);
    
    if (find == -1)
    {
        printf("Impossible\n");
    }
    else
    {
        memset(mk, false, sizeof(mk));   
        findans(find, n);
        findans(find, n);
    }
    
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    
    int N = 0;
    scanf("%d", &N);
    getchar();
    for (int k = 1; k <= N; k++)
    {
        printf("Case #%d:\n", k);
        run();
    }
    return 0;
}
