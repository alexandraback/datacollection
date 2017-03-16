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
int a[1001];
int b[1001];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int i,j,x,y,k;
    int t,T;
    T=readInt();
    for(t=1;t<=T;t++)
    {
        x=readInt();
        y=readInt();
        k=readInt();
        for(i=0;i<1001;i++)a[i]=0;
        for(i=0;i<x;i++)
            for(j=0;j<y;j++)a[i&j]++;
        int ans=0;
        for(i=0;i<k;i++)ans+=a[i];
        cout<<"Case #"<<t<<": ";
        writeInt(ans);
        pc('\n');
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


