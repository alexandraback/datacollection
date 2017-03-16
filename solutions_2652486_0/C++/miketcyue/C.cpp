#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;


int a[100];
int R,n,m,k;

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=1;
    while (T--)
    {
        printf("Case #%d:\n",cas++);
        scanf("%d%d%d%d",&R,&n,&m,&k);
        int num2,num4,num3,num5;
        for (int i=1;i<=R;i++)
        {
            num2=0;
            num4=0;
            num3=0;
            num5=0;
            int p4=0,p2=0;
            if (p4>3 && p2<4) num4++;
            for (int j=1;j<=k;j++)
            {
                scanf("%d",&a[j]);
                if (a[j]%2==0) p2++;
                if (a[j]%4==0) p4++;
                if (a[j]%8==0 && num4<1) num4=1;
                if (a[j]%16==0 && num4<2) num4=2;
                if (a[j]%64==0) num4=3;
                if (a[j]%3==0 && num3<1) num3=1;
                if (a[j]%5==0 && num5<1) num5=1;
                if (a[j]%9==0 && num3<2) num3=2;
                if (a[j]%25==0 && num5<2) num5=2;
                if (a[j]%27==0) num3=3;
                if (a[j]%125==0) num5=3;
            }
            num2=3-num3-num5-num4;
            for (int j=0;j<num3;j++)
                printf("3");
            for (int j=0;j<num5;j++)
                printf("5");
            for (int j=0;j<num4;j++)
                printf("4");
            for (int j=0;j<num2;j++)
                printf("2");
            puts("");
        }
    }
}
