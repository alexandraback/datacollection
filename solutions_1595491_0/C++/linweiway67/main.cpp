#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("aa.txt","r",stdin);
    freopen("bb.txt","w",stdout);
    int cas,ta=1;
    cin >> cas;
    while(cas--)
    {
        int sum1=0,sum2=0,x,n,p,s;
        int i;
        scanf("%d%d%d",&n,&s,&p);
        for(i=0; i<n; i++)
        {
            cin >> x;
            if(x % 3 == 0)
            {
                if(x / 3 >= p) sum1++;
                else if(x/3+1>=p && x!=0) sum2++;
            }
            else
            if(x % 3 == 1)
            {
                if(x / 3+1 >= p) sum1++;
            }
            else
            {
                if(x / 3 + 1 >= p) sum1++;
                else if(x/3+2>=p) sum2++;
            }

        }
        printf("Case #%d: %d\n",ta++,sum1+(sum2>=s?s:sum2));
    }
    return 0;
}
