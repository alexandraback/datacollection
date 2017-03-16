#include <iostream>
#include <cstdio>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

long long gcd (long long x , long long y)
{
    if(y==0)
        return x;
    return gcd (y,x%y);
}

int main()
{
    freopen("myfile.txt","r",stdin);
    freopen("myfile2.txt","w",stdout);

    int t, number =1;
    scanf("%d",&t);
    while(number<=t)
    {
        long long x,y;
        scanf("%lld/%lld",&x,&y);
        long long gc = gcd(x,y);
        double fraction = (double)x/(double)y;
        int counter=0;
        while (fraction<1)
        {
            counter++;
            fraction*=2;
        }
        y=y/gc;
        double check = log2((double)y);
        long long tx = check;
        if(check-tx!=0)
            cout << "Case #" << number << ": impossible" <<endl;
        else
            cout << "Case #" << number << ": " << counter << endl;
        number++;
    }
}
