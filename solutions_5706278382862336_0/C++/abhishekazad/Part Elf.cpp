#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<climits>
#include<stack>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define KEY_NOT_FOUND -1
#ifndef ONLINE_JUDGE
    #undef gc
    #undef pc
    #define gc getchar
    #define pc putchar
#endif // ONLINE_JUDGE
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;
inline int readInt();
inline void writeInt(int a);
long long readLongLong();
void writeLongLong(long long res);
LL power(LL base,LL exp,LL x);
LL mulmod(LL a,LL b,LL c);
ULL gcd(ULL a,ULL b)
{
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int isAPower(ULL v)
{
  int f;

f = (v & (v - 1)) == 0;

//Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:

f = v && !(v & (v - 1));
return f;

}
ULL logBase2(ULL x)
{
    ULL i=0;
    while(x!=1)
    {
        x=x>>1;
        i++;
    }
    return i;
}
ULL pow2roundup (ULL x)
{
    if(isAPower(x))return x;
    if (x < 0)
        return 0;
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x=x>>1;
    return x+1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t,T,i,j;
    ULL a,b,x;
    char temp;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        //scanf("%ull",&a);
        cin>>a;

        //scanf("%c",&temp);
        cin>>temp;
        //scanf("%ull",&b);
        cin>>b;
        //cout<<"a"<<a<<"b"<<b<<endl;
        //b=readLongLong();
        x=gcd(a,b);
        a=a/x;
        b=b/x;
        if(isAPower(b))
        {
            cout<<"Case #"<<t<<": "<<logBase2(b/pow2roundup(a))<<endl;
        }
        else
        {
            cout<<"Case #"<<t<<": "<<"impossible"<<endl;
        }
    }
    return 0;
}
void writeInt(int a)
{
    char s[11];
    register int t = -1;
    do
    {
        s[++t] = a % 10 + '0';
        a /= 10;
    }while(a > 0);
    while(t >= 0)pc(s[t--]);
    //pc('\n');
}
int readInt()
{
    char c=gc();
    int ans=0;
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&& c<='9')
    {
        ans=ans*10+c-'0';
        c=gc();
    }
    return ans;
}
long long readLongLong()
{
   long long res=0;
   char ch;
   ch=gc();
   while(ch<'0' || ch>'9')
       ch=gc();
   while(ch>='0' && ch<='9')
   {
       res=(res*10)+ch-48;
       ch=gc();
   }
   return res;
}
void writeLongLong(long long res)
{
   long long rev,count=0,n;
   rev=res;
   if(res==0)
   {
       pc('0');
       pc('\n');
       return;
   }
   while(rev%10==0)
   {
       rev=rev/10;
       count++;
   }
   rev=0;
   n=res;
   while(n)
   {
       rev=(rev*10)+(n%10);
       n=n/10;
   }
   while(rev)
   {
       pc((rev%10)+48);
       rev=rev/10;
   }
   while(count--)
   pc('0');
   //pc('\n');
}
LL power(LL base,LL exp,LL x)
{
         long long ans=0;
         if(exp==0)
                   return 1;
         ans=power(base,exp>>1,x);
         ans=(ans*ans)%x;
         if(exp & 1)
                ans=(ans*base)%x;
         return ans;
}

LL mulmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


