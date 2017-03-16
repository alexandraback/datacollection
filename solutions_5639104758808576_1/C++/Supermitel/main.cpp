#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int t, n, x;
int ind;
int add;

int main()
{
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    scanf("%d\n", &t);
     char aux;

    for(int i = 0; i < t; i++)
    {
        scanf("%d ", &n);
        ind = 0;
        add = 0;

        for(int i = 0; i <= n; i++)
        {
            scanf("%c", &aux);
            x = aux - '0';
            if(x == 0) continue;
            if(ind < i)
            {
                add += i - ind;
                ind = i;
            }
            ind += x;
        }

        scanf("\n");
        printf("Case #%d: %d\n", i+1, add);

    }

    return 0;
}
