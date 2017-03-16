#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

bool optdos(long long n)
{
    long long uno = 1;
    for(long long i = 0; i<63;i++)
    {
        if(n == (uno<<i))
            return true;
    }
    return false;
}

int main()
{
    int cont,T;
    long long a,b,x,y,z;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        scanf("%lld/%lld",&a,&b);
        x=a;
        y=b;
        while(y!=0)
        {
            z = y;
            y = x % y;
            x = z;
        }
        a/=x;
        b/=x;
        printf("Case #%d: ",k);
        if(optdos(b))
        {
            cont = 0;
            while(b>a)
            {
                b/=2;
                cont++;
            }
            if(cont<=40)
                printf("%d\n",cont);
            else
                printf("impossible\n");
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
