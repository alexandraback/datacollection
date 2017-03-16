#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int TestCase;
    scanf("%d", &TestCase);
    
    for (int T = 1; T <= TestCase; ++T)
    {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        
        printf("Case #%d:", T);
        for (int i = 1; i <= K; ++i)
            printf(" %d", i);
        printf("\n");
    }
    return 0;
}
