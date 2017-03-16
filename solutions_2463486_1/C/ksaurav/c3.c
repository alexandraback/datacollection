#include<stdio.h>
 
long long int f(long long int a)
{
        if(a>=4004009004004) return 39;
if(a>=4000008000004) return 38;
if(a>=1234567654321) return 37;
if(a>=1232346432321) return 36;
if(a>=1214428244121) return 35;
if(a>=1212225222121) return 34;
if(a>=1210024200121) return 33;
if(a>=1024348434201) return 32;
if(a>=1022325232201) return 31;
if(a>=1020304030201) return 30;
if(a>=1004006004001) return 29;
if(a>=1002003002001) return 28;
if(a>=1000002000001) return 27;
if(a>=40000800004) return 26;
if(a>=12345654321) return 25;
if(a>=12102420121) return 24;
if(a>=10221412201) return 23;
if(a>=10000200001) return 22;
if(a>=404090404) return 21;
if(a>=400080004) return 20;
if(a>=125686521) return 19;
if(a>=123454321) return 18;
if(a>=121242121) return 17;
if(a>=104060401) return 16;
if(a>=102030201) return 15;
if(a>=100020001) return 14;
if(a>=4008004) return 13;
if(a>=1234321) return 12;
if(a>=1002001) return 11;
if(a>=44944) return 10;
if(a>=40804) return 9;
if(a>=14641) return 8;
if(a>=12321) return 7;
if(a>=10201) return 6;
if(a>=484) return 5;
if(a>=121) return 4;
if(a>=9) return 3;
if(a>=4) return 2;
if(a>=1) return 1;
return 0;
 
}
 
int main()
{
        long long int t,test,a,b;
        scanf("%lld",&test);
        for(t=1;t<=test;t++)
        {
                scanf("%lld%lld",&a,&b);
                printf("Case #%lld: %lld\n",t,f(b)-f(a-1));
        }
return 0;
 
}
