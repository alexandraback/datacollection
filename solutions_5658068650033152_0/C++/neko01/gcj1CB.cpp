/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eqs=1e-8;
int main()
{
    freopen("C-small-attempt0.in" , "r" , stdin);
    freopen("C-small-attempt0.out" , "w" , stdout);
    int t,cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d: ",++cnt);
        if(m<n)
            swap(m,n);
        if(n<=2)
        {
            printf("%d\n",k);
            continue;
        }
        int ans=0;
        if(n==3)
        {
            if(k<5)
                ans=k;
            else if(k<8)
                ans=4+(k-5);
            else if(k<11)
            {
                if(m>=4)
                    ans=6+(k-8);
                else
                    ans=4+(k-5);
            }
            else if(k<=14)
            {
                if(m>=5)
                    ans=8+(k-11);
                else
                    ans=6+(k-8);
            }
            else
            {
                if(m==6)
                    ans=10+(k-14);
                else
                    ans=8+(k-11);
            }
            printf("%d\n",ans);
            continue;
        }
        if(n==4)
        {
            if(m==4)
            {
                ans=k;
                if(k>=5)
                    ans--;
                if(k>=8)
                    ans--;
                if(k>=10)
                    ans--;
                if(k>=12)
                    ans--;
            }
            else
            {
                ans=k;
                if(k>=5)
                    ans--;
                if(k>=8)
                    ans--;
                if(k>=10)
                    ans--;
                if(k>=12)
                    ans--;
                if(k>=14)
                    ans--;
                if(k>=16)
                    ans--;
            }
            printf("%d\n",ans);
            continue;
        }
    }
    return 0;
}
