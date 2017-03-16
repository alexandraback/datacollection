#include <cstdio>
#include <algorithm>

using namespace std;

typedef long double ld;

ld przyp()
{
    ld c, f, x;
    scanf("%Lf%Lf%Lf", &c, &f, &x);
    ld ile = 2.0L;
    ld wyn = x / 2;
    ld czas = 0.0L;
    while(czas < wyn)
    {
        wyn = min(wyn, czas + x / ile);
        czas += c / ile;
        ile += f;
    }
    return wyn;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
        printf("Case #%d: %.8Lf\n", i, przyp());
    return 0;
}
