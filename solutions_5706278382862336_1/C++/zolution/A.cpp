#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

long long int twop[62];
long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void init()
{
    twop[0]=1;
    for(int h=1;h<62;h++) twop[h]=2*twop[h-1];
}
    
int main()
{
    init();
    freopen("inputA.in","r",stdin);
    freopen("outputA1.txt","w",stdout);
    int co=0;
    scanf("%d",&co);
    for(int po=0;po<co;po++)
    {
        long long int p=0;
        long long int q=0;
        char test[300];
        scanf("%s",test);
        int len=strlen(test);
        int flag=0;
        while(1)
        {
            if(test[flag]=='/') break;
            p = p*10 + (test[flag]-'0'); 
            flag++;
        }
        flag++;
        while(flag<len)
        {
            q = q*10 + (test[flag]-'0'); 
            flag++;
        }        
        long long int gr=gcd(p,q);
        p = p/gr;
        q = q/gr;
        bool flag2=false;
        for(int h=0;h<62;h++)
        {
            if(q==twop[h])
            {
                flag2=true;
                break;
            }
        }
        if(flag2==false)
        {
            printf("Case #%d: impossible\n",po+1);
        }
        else
        {
            //long double rt=q/p;
            for(int h=1;h<62;h++)
            {
                if(q/twop[h]<=p)
                {
                    printf("Case #%d: %d\n",po+1,h);
                    break;
                }
            }
        }
    }

            
        
}
