#include <iostream>
#include <cstdio>

using namespace std;

int cnt[3000];

int main()
{
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        int N;
        scanf("%d", &N);

        for(int i = 0; i < 3000; i++) cnt[i] = 0;

        for(int Ni = 0; Ni < N*2-1; Ni++)
            for(int Nj = 0; Nj < N; Nj++)
            {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }

        printf("Case #%d:", Ti);

        for(int i = 0; i < 3000; i++)
            if( cnt[i]&1 ) printf(" %d", i);

        puts("");
    }
}
