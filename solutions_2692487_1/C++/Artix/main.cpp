#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int T;
int A,N;
int tab[101];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d", &A,&N);

        for(int i = 0; i < N; i++)
            scanf("%d", &tab[i]);
        sort(tab, tab+N);

        int res = N;
        int nbAdd = 0;

        for(int i = 0; i < N; i++)
        {
            if(tab[i] < A)
                A+=tab[i];
            else
            {
                res = min(res, nbAdd+(N-i));
                if(A==1)
                {
                    nbAdd=N;
                    break;
                }
                while(tab[i] >= A)
                {
                    A+=A-1;
                    nbAdd++;
                }
                A+=tab[i];
            }
        }
        res=min(res, nbAdd);

        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
