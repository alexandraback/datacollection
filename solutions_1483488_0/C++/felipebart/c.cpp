#include <cstdio>

using namespace std;

int max_pw10(int x)
{
    int ret = 1;
    while(ret <= x)
    {
        ret *= 10;
    }
    
    return ret/10;
}

bool isvalid(int x, int a, int b)
{
    return ((a <= x) && (x <= b));
}

int cycle_size(int x, int pw10, int a, int b)
{
    int ret = 0;
    int i = x;
    do
    {
        if(isvalid(i, a, b))
        {
            ++ret;
        }
        i = i/10 + (i%10)*pw10;
        if((i < x) && isvalid(i, a, b))
        {
            return 0;
        }
    }while(i != x);
    
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int resp = 0;
        int totpw = max_pw10(a);
        for(int i=a;i<=b;++i)
        {
            int cs = cycle_size(i, totpw, a, b);
            resp += (cs*(cs-1))/2;
        }
        
        printf("Case #%d: %d\n", lp, resp);
    }
    return 0;
}