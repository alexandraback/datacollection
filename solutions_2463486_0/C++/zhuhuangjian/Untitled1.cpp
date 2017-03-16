#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int m;
char s1[20],s2[20];
int a,b;
bool is_p(int b)
{
     int i=0;
    int j;
    int c[10];
    while(b)
    {
        c[i]=b%10;
        b/=10;
        i++;
    }
    int s=0,t=i-1;
    while(s<=t)
    {
        if(c[s]!=c[t])
        {
            return false;
        }
        s++;
        t--;
    }
    return true;
}
bool is_ok(int a)
{
    int tag1=0,tag2=0,tag3=0;
    if((sqrt(a*1.0)/1)*(sqrt(a*1.0)/1)==a)
    tag1=1;

    int c=sqrt(a*1.0)/1;
    if(is_p(a))
    tag2=1;
    if(is_p(c))
    tag3=1;
    if(tag1+tag2+tag3==3)
    return true;

    return false;
}
int main()
{
    //freopen("A.in","r",stdin);
  //  freopen("A.txt","w",stdout);
    int k=1;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        int i;
        int ans=0;
        for(i=a;i<=b;i++)
        if(is_ok(i))
        ans++;

        printf("Case #%d: %d\n",k++,ans);
    }
    return 0;
}
