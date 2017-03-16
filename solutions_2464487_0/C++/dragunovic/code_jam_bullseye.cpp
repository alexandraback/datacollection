#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

long long t,r,b;

long long hitung(long long x)
{
     return x*x;
 }

int main ()
{
    scanf("%lld",&t);
    for (int z=1; z<=t; z++)
    {
        scanf("%lld%lld",&r,&b);
        
        int p=0;
        long long temp=0;
        int ctr=0;
        while (b - temp > 0)
        {
            temp = hitung(r+1+p) - hitung(r+p);
            
            if (b-temp >= 0) {
                b-=temp;
                ctr+=1;
            }
            
            p+=2;
        }
        
        printf("Case #%d: %d\n",z,ctr);
    }
    
//    system("pause");
    return 0;
}
