#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;



long long t,r,b;
int z;
long long ptx;

long long hitung(long long x)
{
     return x*x;
}

long long htg(long long w)
{
     return (( w+1+w) * (w+1-w));
}

void cari_bound()
{
     
     long long mn=1;
     long long mx=707106780;
     
     long long pt=1;
     
     while (mn<=mx)
     {
           long long mid=(mn+mx)/2;
           
           long long hasil = htg(r)*mid;
           cout << mid << " " << hasil << endl;
           
           if (hasil< b)
           {
                if (mid> pt) pt=mid;
                mn=mid+1;
           }
           else
           mx=mid-1;
     }
     ptx=pt;
}

void bin()
{
     long long mn=1;
     long long mx=(b/htg(r))+2;
     if (mx > 707106780) mx=707106780;
     
     long long mid;
     
     long long mdx=0;
     
     while (mn<=mx)
     {
           mid=(mn+mx)/2;

           
           long long hasil= ( (2* ((r+1+r)* (r+1-r)) + ((mid-1)*4)) * mid) /2;
           
//           cout << mid << " " << hasil << endl;
           
           if (hasil > b)
           {
               mx = mid-1;
           }
           else
           {
               if (mdx < mid) mdx=mid;
               mn= mid+1;
           }
           
     }
     
     printf("Case #%d: %lld\n",z,mdx);
     
}

int main ()
{
    scanf("%lld",&t);
    for (z=1; z<=t; z++)
    {
        scanf("%lld%lld",&r,&b);
        
        /*
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
        */
        
//        cari_bound();
//        cout << ptx << endl;
        bin();
    }
    
//    system("pause");
    return 0;
}
