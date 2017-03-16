//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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
        int C,D,V;
        vector<int> nominaly;
        scanf("%d%d%d", &C, &D, &V);
        nominaly.resize(D+1);
        for(int i = 1;i <= D;i++)
            scanf("%d", &nominaly[i]);
        
        LL najw = 0;
        int p = 0, wyn = 0;
        while(najw < V)
        {
            if(p < D && nominaly[p+1] <= najw+1)
            {
                p++;
                najw += (LL)C*nominaly[p];
            }
            else
            {
                wyn++;
                najw += (LL)C*(najw+1);
            }
        }
        
        printf("Case #%d: %d\n", ti, wyn);
    }
    return 0;
}
