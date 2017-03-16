#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int n;
char tab[1007];
vector <int> wek;
int wyn;

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        wek.clear();
        scanf("%d%s", &n, tab);
        for (int i=0; i<=n; i++)
        {
            for (char j='1'; j<=tab[i]; j++)
            {
                wek.push_back(i);
            }
        }
        wyn=0;
        for (int i=0; i<wek.size(); i++)
        {
            wyn=max(wyn, wek[i]-i);
        }
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}
