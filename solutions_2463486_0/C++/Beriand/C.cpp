#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;

long long t[10000];

bool pal (long long co)
{
     char pom[20];
     int x,y;
     
     for (x=0; co; co/=10)
         pom[x++]=co%10;
     
     for (y=0; y<x && pom[y]==pom[x-y-1]; y++);
     
     if (y==x)
        return 1;
     
     return 0;
}     

int main ()
{
    long long z,a,b,c,d,e,nr=0;
    
    for (a=1; a<=10000000; a++)
        if (pal(a) && pal(a*a))
                   t[nr++]=a*a;
    
    scanf ("%lld", &z);
    
    for (a=1; a<=z; a++)
    {
        scanf ("%lld%lld", &b, &c);
        
        for (d=e=0; d<nr; d++)
            if (t[d]>=b && t[d]<=c)
               e++;
        
        printf ("Case #%lld: %lld\n", a, e);
    }                   
                                      
    getchar();
    getchar();
    return 0;
}
