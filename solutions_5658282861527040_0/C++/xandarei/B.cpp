#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    unsigned long long A,B,C,T,cont;
    scanf("%llu",&T);

    for(int k=1;k<=T;k++)
    {
        scanf("%llu %llu %llu",&A,&B,&C);
        cont = 0;
        for(int a=0;a<A;a++)
            for(int b=0;b<B;b++)
            {
                if((a&b) < C)
                    cont++;
            }
        printf("Case #%d: %llu\n",k,cont);
    }
    return 0;
}
