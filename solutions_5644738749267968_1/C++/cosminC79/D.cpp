#include <cstdio>
#include <algorithm>
#include <cstring>
#define NMAX 1005
using namespace std;
int tests, n;
double A[NMAX], B[NMAX];
bool mark[NMAX];

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    
    scanf("%d", &tests);
    for (int test_no = 1; test_no <= tests; test_no++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lf", &A[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lf", &B[i]);
        sort(A + 1, A + n + 1);
        sort(B + 1, B + n + 1);
        memset(mark, false, sizeof(mark));
        
        int who, score = 0;
        for (int i = 1; i <= n; i++)
        {
            who = -1; 
            for (int j = 1; j <= n; j++)
                if (!mark[j] && B[j] > A[i])
                {
                    who = j;
                    break ;
                }
            if (who != -1)
            {
                mark[who] = true;
                continue ;
            }
            else
            {
                score++;
                for (int j = 1; j <= n; j++)
                    if (!mark[j])
                    {
                        mark[j] = true;
                        break ;
                    }
            }
        }
        
        int l = 1, r = n, score2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (A[i] > B[l])
            {
                score2++;
                l++;
            }
            else
                r--;
        }
        
        printf("Case #%d: %d %d\n", test_no, score2, score);
    }
    return 0;
}

