#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<PI, PI > PII;
const double eps=1e-5;
const int inf=1e5;
const double pi=acos(-1.0);
const int N=1e6+5;

int num[2505];
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for(int i=0;i<2*n-1;i++)
            for(int j=0;j<n;j++)
            {
                int x;
                scanf("%d", &x);
                num[x]++;
            }
        printf("Case #%d: ", ca++);
        int flag=0;
        for(int i=1;i<=2500;i++)
            if(num[i]%2==1)
               flag++;
        int ff=0;
        for(int i=1;i<=2500;i++)
        {
            if(num[i]%2==1)
            {
                printf("%d", i), ff++;
                if(ff==flag)
                    puts("");
                else
                    putchar(' ');
            }
        }
    }
    return 0;
}
