#include <iostream>
#include <cstdio>

using namespace std;

int T; int A, B, K; int Ans;

int main()
{

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        Ans = 0;
        scanf("%d %d %d", &A, &B, &K);

        for(int Ai = 0; Ai < A; Ai++)
            for(int Bi = 0; Bi < B; Bi++)
                if( (Ai&Bi) < K ) Ans++;

        printf("Case #%d: %d\n", Ti, Ans);
    }
}
