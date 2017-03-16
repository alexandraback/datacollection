#include <cstdio>
#include <algorithm>
using namespace std;

int n,u[10];

int main()
{
    int sTT;
    scanf("%d", &sTT);
    for (int TT = 1; TT <= sTT; ++TT)
    {
        printf("Case #%d: ", TT);
        scanf("%d", &n);
        if (n == 0)
            printf("INSOMNIA\n");
        else
        {
            int co = 10;
            fill(u, u + 10, 0);
            for (int l = n; ; l += n)
            {
                for (int t = l; t > 0; t /= 10) 
                    if (++ u[t % 10] == 1) -- co;
                if (co == 0)
                {
                    printf("%d\n", l);
                    break;
                }
            }
        }
    }
    return 0;
}
