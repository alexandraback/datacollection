#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int tab[1005];
int heh[1005];

int n;

int war()
{
    int kon = n - 1;
    int s = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(tab[i] > heh[kon])
            s++;
        else
            kon--;
    }
    return s;
}

int yolo_war()
{
    int s = 0;
    int poc = 0;
    for(int i = 0; i < n; i++)
    {
        if(tab[i] > heh[poc])
            s++, poc++;
    }
    return s;
}

int wczytaj()
{
    long double x;
    scanf("%Lf", &x);
    return (int) round(x * 1e6);
}

void przyp()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        tab[i] = wczytaj();
    for(int i = 0; i < n; i++)
        heh[i] = wczytaj();
    sort(tab, tab + n);
    sort(heh, heh + n);
    printf("%d %d\n", yolo_war(), war());
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        printf("Case #%d: ", i);
        przyp();
    }
    return 0;
}
