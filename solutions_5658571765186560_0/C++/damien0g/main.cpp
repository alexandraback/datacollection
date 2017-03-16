#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int ct = 1; ct <= T; ct++)
    {
        int X, R, C;
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: ", ct);

        if((X > max(R, C)) || ((X > 2) && ((X+2)/2 > min(R, C))) || ((R*C)%X) || (X >= 7))
            printf("RICHARD\n");
        else
            printf("GABRIEL\n");
    }
    return 0;
}
