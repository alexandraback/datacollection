#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
     freopen("D-large.in","r",stdin);
    freopen("d.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("Case #%d: ",ca);

        if(b*c%a !=0) {puts("RICHARD"); continue;}

        if(a > b && a> c) {puts("RICHARD");continue;}

        if(a<3)  {puts("GABRIEL");continue;}

         if(a==3)
            {
                if(min(b,c)>1)
                  puts("GABRIEL");
                else puts("RICHARD");
              continue;
         }

         if(a<7)
         {
             if(min(b,c)>2)
                  puts("GABRIEL");
                else puts("RICHARD");
              continue;
         }

         puts("RICHARD");
    }
    return 0;
}
