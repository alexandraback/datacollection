#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[20],b[20];
int len;
int QQ,AA,BB;
void f(int nowA,int nowB,int place)
{
    if(place==len)
    {
        int diff=abs(nowA-nowB);
        if(QQ>diff){ QQ=diff, AA=nowA, BB=nowB; }
        else if(QQ==diff && nowA<AA){ QQ=diff, AA=nowA, BB=nowB; }
        else if(QQ==diff && nowA==AA && nowB<BB){ QQ=diff, AA=nowA, BB=nowB; }
        return;
    }

    int newA=nowA*10, newB=nowB*10;
    if(a[place]=='?' && b[place]=='?')
    {
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                f(newA+i,newB+j,place+1);
    }
    else if(a[place]=='?')
    {
        for(int i=0;i<=9;i++)
            f(newA+i,newB+b[place]-'0',place+1);
    }
    else if(b[place]=='?')
    {
        for(int i=0;i<=9;i++)
            f(newA+a[place]-'0',newB+i,place+1);
    }
    else f(newA+a[place]-'0',newB+b[place]-'0',place+1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++,puts(""))
    {
        scanf("%s %s",a,b);
        len=strlen(a);
        QQ=1e9;
        f(0,0,0);
        printf("Case #%d: ",mindol);

        int M=1;
        for(int i=1;i<len;i++) M*=10;
        for(;M;M/=10) printf("%d",AA/M), AA%=M;
        printf(" ");
        M=1;
        for(int i=1;i<len;i++) M*=10;
        for(;M;M/=10) printf("%d",BB/M), BB%=M;
    }
    return 0;
}
