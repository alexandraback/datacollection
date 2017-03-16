#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
   // freopen("1.in","r",stdin);
   // freopen("2.txt","w",stdout);
    int t,a,b,tp;
    scanf("%d",&t);
    for(int ca =1; ca <= t; ++ca)
    {
        scanf("%d%d", &a, &b);
        int cnt = 0;
        for(int i=a; i<=b; i++)
        {
            tp = i;
            int k = log10(i+0.0);
            int wei= pow(10+0.0,k);
            int v[10],vz=0;
            while(k--)
            {
                int r = tp/10;
                tp = (tp%10) * wei + r;
                bool flag=false;
                for(int j=0; j<vz; j++)
                {
                    if(v[j] == tp )
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                v[vz++] = tp;
                if( tp <= b && tp >= a  && tp > i)
                {
                     ++cnt;
                }
            }
        }
        printf("Case #%d: %d\n",ca,cnt);
    }

    return 0;
}
