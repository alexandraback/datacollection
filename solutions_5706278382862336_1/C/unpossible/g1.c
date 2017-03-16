#include<stdio.h>
#define ll long long
ll gcd(ll x,ll y)
{
    if(y==0)
    return x;
    return gcd(y,x%y);
}
int main()
{
    int p=1,t,i,j,k,l;
    long long a,b,c;
   /* freopen("i11.in","r",stdin);
    freopen("output.txt","w",stdout);
    */char s[1005];
    scanf("%d",&t);
    while(t--)
    {
        a=0,b=0,i=0;
        scanf(" %s",s);
        while(s[i]!='/')
        {
            a=a*10+s[i]-'0';
            i++;
        }
        i++;
        while(s[i]!='\0')
        {
            b=b*10+s[i]-'0';
            i++;
        }
        c=gcd(a,b);
        a/=c;
        b/=c;
        if(b&(b-1))
        printf("Case #%d: impossible\n",p++);
        else
        {
            k=0;
            while(a<b)
            a*=2,k++;
            printf("Case #%d: %d\n",p++,k);
        }
    }
    return 0;
}
