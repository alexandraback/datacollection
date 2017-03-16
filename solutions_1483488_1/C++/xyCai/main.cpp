#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
//    freopen("C-large.in","r",stdin);
//    freopen("C-large.out","w",stdout);
    int t;
    int a,b;
    int digit[10],dnum;
    int ans;
    int tem,i,j,k;
    int curans[10],curcnt=0;
    scanf("%d",&t);

    for(int cases = 1;cases<=t;cases++)
    {
        ans = 0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++)
        {
            dnum = 0;
            memset(curans,-1,sizeof(curans));
            curcnt = 0;
            tem = i;
            while(tem)
            {
                digit[dnum++] = tem%10;
                tem /= 10;
            }
//            for(j=0;j<dnum;j++) cout<<digit[j]<<" ";cout<<endl;
            for (j=dnum-1;j>=0;--j)
            {
//                if (digit[j] == 0) continue;
                tem = 0;
                for(k=j;k>=0;k--)
                {
                    tem *= 10;
                    tem += digit[k];
                }
                for(k=dnum-1;k>j;k--)
                {
                    tem *= 10;
                    tem += digit[k];
                }
                if(tem>=a && tem<= b && i<tem)
                {
                    for(k = 0;k<curcnt;++k)
                    {
                        if(curans[k] == tem)
                            break;
                    }
                    if(k==curcnt) {ans++;curans[curcnt++] = tem;}
                }
            }
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
