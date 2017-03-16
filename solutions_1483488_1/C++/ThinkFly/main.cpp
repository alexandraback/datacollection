#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
int count(int n,int q,int a,int b)
{
    int base = 10;
    int ret = 0;
    int p = q;
    map <long long int,int> yy;
    while (n >= base)
    {
        int y = n/base + (n%base)*p;
        base *= 10;
        p /= 10;
        if (y < n && y>=a)
        {
            long long int u = y*10000000.0+n;
            if (yy.find(u) == yy.end()) {
                yy[u] = 1;
                ret++;
            }
        }
    }
    return ret;
}
int main()
{
    int n_test_case;
    scanf("%d",&n_test_case);
    for (int i=0;i<n_test_case;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        int p=1;
        while (a/p && b/p)p*=10;
        if (a/p || b/p)
        {
            printf("Case #%d: %d\n",i+1,0);
            continue;
        }
        int cnt =0;
        for (int j=a;j<=b;j++) {
            cnt += count(j,p/10,a,b);
        }
        printf("Case #%d: %d\n",i+1,cnt);
    }
    return 0;
}