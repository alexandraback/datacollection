#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int tab[1000005],m;
int rev(int n)
{
    int rem,rev=0;
    while(n!=0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    return rev;
}
int recu(int n)
{
    int keb;
    if(n==1)
        return 1;
    if(tab[n]==0)
    {
        keb=rev(n);
        if(n%10!=0&&keb<n)
            tab[n]=min(recu(keb),recu(n-1))+1;
        else
            tab[n]=recu(n-1)+1;
    }
    return tab[n];
}
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i=0;
    scanf("%d",&t);
    for(i=1;i<=1000000;i++)
    {
        recu(i);
    }
    i=0;
    while(t--)
    {
        i++;
        scanf("%d",&m);
        printf("Case #%d: %d\n",i,recu(m));
    }
    scanf(" ");
}
