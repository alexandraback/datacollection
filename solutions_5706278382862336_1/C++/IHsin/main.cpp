#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<cstring>
#include <cmath>
#include<algorithm>
#include<stack>
using namespace std;

int T;
long long  den;
long long  num;
int n;
void get()
{
    if(den%2==0)
    {
        den/=2;
    }
    else
    {
        num*=2;
    }
    n++;
  //  cout<<num<<" "<<den<<endl;

}
bool solve()
{
    while(true)
    {
        if(n>40) return false;
        get();
        if(num==den) return true;
        if(num>den)
        {
           // n++;
            num-=den;
            double den2=log(den)/log(2);
            //cout<<den2-int(den2)<<endl;
           // cout<<<<endl;
            if((den2-(long long)(den2))!=0)
            {
              //  cout<<"ff";
                return false;
                //printf("impossible/n");
            }
            else
            {
             //   cout<<num%2<<endl;
                if(num%2==1&&num<den)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

        }
    }
}
long long gcd(long long  x,long long  y )
{
   if(x < y) return gcd(y,x);  // x>y
   if( y == 0) return x;  // if y=0, x is GCD
   else
   {
        if( !(x%2) )
        {
          if( !(y%2) )  //x,y both even
               return 2*gcd(x >> 1, y >> 1);
           else      // x is even, y is odd
               return gcd(x >> 1, y );
         }
         else
         {
           if( !(y%2) )  // x is  odd,  y is even
               return gcd(x, y >> 1);
           else       // x, y both odd
               return gcd(y,x-y);
         }
    }
}
//long int kgcd(long int a, long int b)
//{
//    if (a == 0) return b;
//    if (b == 0) return a;
//    if (!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1;
//    else if (!(b & 1)) return kgcd(a, b>>1);
//    else if (!(a & 1)) return kgcd(a>>1, b);
//    else return kgcd(abs(a - b), min(a, b));
//}

int main()
{
 //freopen("input.txt","r",stdin);
 freopen("A-large.in","r",stdin);
 freopen("a-large.out","w",stdout);

    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld/%lld",&num,&den);
        long long d=gcd(num,den);
        num/=d;
        den/=d;
        n=0;
        if(solve())
        {
            printf("Case #%d: %d\n",i,n);
        }
        else
        {
            printf("Case #%d: impossible\n",i);
        }
    }
    return 0;
}
