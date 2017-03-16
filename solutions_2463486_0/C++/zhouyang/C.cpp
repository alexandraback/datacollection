#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int t,s,e;
bool f2(char ch[])
{
    int len=strlen(ch);
    int flag=1;
    for(int i=0;i<len;i++)
    {
        if(ch[i]!=ch[len-i-1])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

bool f(int num)
{
    char ch[10];
    int p=0;
    while(num)
    {
        ch[p++]=num%10-'0';
        num/=10;
    }
    ch[p]='\0';
    return f2(ch);
}
bool judge(int num)
{
    int s=(int)sqrt(num);
    if(s*s==num&&f(num)&&f(s))
    return true;
    return false;
}
int main ()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("b.txt","w",stdout);
    scanf("%d",&t);
    for(int l=1;l<=t;l++)
    {
        scanf("%d%d",&s,&e);
        int ans=0;
        for(int i=s;i<=e;i++)
        {
            if(judge(i))
            ans++;
        }
        printf("Case #%d: %d\n",l,ans);
    }
}
