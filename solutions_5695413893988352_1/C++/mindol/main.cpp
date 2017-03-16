#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[20],b[20];
int len;
long long QQ,AA,BB;
long long pow10[20];
void f(long long nowA,long long nowB,int place)
{
    if(abs(nowA-nowB)*pow10[len-place] > QQ) return;
    if(place==len)
    {
        long long diff=abs(nowA-nowB);
        if(QQ>diff){ QQ=diff, AA=nowA, BB=nowB; }
        else if(QQ==diff && nowA<AA){ QQ=diff, AA=nowA, BB=nowB; }
        else if(QQ==diff && nowA==AA && nowB<BB){ QQ=diff, AA=nowA, BB=nowB; }
        return;
    }

    long long newA=nowA*10, newB=nowB*10;
    if(a[place]=='?' && b[place]=='?')
    {
        if(nowA<nowB) f(newA+9,newB+0,place+1);
        else if(nowA>nowB) f(newA+0,newB+9,place+1);
        else
        {
            f(newA+0,newB+0,place+1);
            f(newA+0,newB+1,place+1);
            f(newA+1,newB+0,place+1);
        }
    }
    else if(a[place]=='?')
    {
        int num=b[place]-'0';
        if(nowA<nowB) f(newA+9,newB+num,place+1);
        else if(nowA>nowB) f(newA+0,newB+num,place+1);
        else
        {
            if(num-1>=0) f(newA+num-1,newB+num,place+1);
            f(newA+num,newB+num,place+1);
            if(num+1<=9) f(newA+num+1,newB+num,place+1);
        }
    }
    else if(b[place]=='?')
    {
        int num=a[place]-'0';
        if(nowA>nowB) f(newA+num,newB+9,place+1);
        else if(nowA<nowB) f(newA+num,newB+0,place+1);
        else
        {
            if(num-1>=0) f(newA+num,newB+num-1,place+1);
            f(newA+num,newB+num,place+1);
            if(num+1<=9) f(newA+num,newB+num+1,place+1);
        }
    }
    else f(newA+a[place]-'0',newB+b[place]-'0',place+1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    pow10[0]=1;
    for(int i=1;i<=18;i++)
        pow10[i]=pow10[i-1]*10;
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++,puts(""))
    {
        scanf("%s %s",a,b);
        len=strlen(a);
        QQ=(1ll<<62);
        f(0,0,0);
        printf("Case #%d: ",mindol);

        long long M=1;
        for(int i=1;i<len;i++) M*=10;
        for(;M;M/=10) printf("%lld",AA/M), AA%=M;
        printf(" ");
        M=1;
        for(int i=1;i<len;i++) M*=10;
        for(;M;M/=10) printf("%lld",BB/M), BB%=M;
    }
    return 0;
}
