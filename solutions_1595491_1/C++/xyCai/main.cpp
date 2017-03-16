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
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t;
    int n,p,s;
    int sco;
    int x,y;
    int ans;
    scanf("%d",&t);
    for(int cases = 1;cases<=t;cases++)
    {
        ans = 0;
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&sco);
            x = sco/3;
            y = sco%3;
//            cout<<x<<" "<<y<<endl;
            if(x >= p) ans++;
            else if (x == p-1)
            {
                if(y) ans++;
                else if(s && x)
                {
                    s--;
                    ans++;
                }
            }
            else if (x == p-2)
            {
                if(y==2 && s) {s--;ans++;}
            }
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
