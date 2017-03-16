//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef long double LD;
const int INF = 1000000009;

int main()
{
    int t;
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        int r,c,w;
        scanf("%d%d%d", &r, &c, &w);
        
        int strzaly = c/w;
        int wyn = strzaly*r+(w-1)+(c%w != 0);
        
        printf("Case #%d: %d\n", ti, wyn);
    }
    return 0;
}
