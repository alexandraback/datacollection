#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int a[10000], n;


int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
    int TT;
    scanf("%d", &TT);
    for (int T=1;T<=TT;++T)
    {
        printf("Case #%d:", T);
        scanf("%d", &n);
        for (int i =0;i<n;++i)
            scanf("%d", a + i);
        double s = 0;
        for (int i =0;i<n;++i)
            s += a[i];
        for (int i=0;i<n;++i)
        {
            double l = 0, r = s;
            while (r-l>1e-7)
            {
                double mid = (l+r)/2;
                double need = 0;
                for (int j=0;j<n;++j)
                    if (j!=i)
                        need += max(0.0, mid + a[i] - a[j]);
                if (need + mid < s)
                    l = mid;
                else
                    r = mid;
            }
            printf(" %.6f", (l+r)/2/s*100);
        }
        printf("\n");
    }
}
