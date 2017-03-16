#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int ans;
int T,A,B;

void check(int a)
{
    int c=a,t=1,d,p=1;
    int b[10],n=0;
    int s[10],m=0;
    while(a)
    {
        b[n++]=a%10;
        a/=10;
        t*=10;
    }
    n--;
    for(int i=n-1;i>=0;i--)
    {
        t/=10; p*=10;
        if(b[i]==0) continue;
        d=c%t*p+c/t;
        if(d>=A&&d<=B)
        {
            if(d>c)
            {
                bool temp=false;
                for(int j=0;j<m;j++)
                {
                    if(s[j]==d)
                    {
                        temp=true;
                        break;
                    }
                }
                if(!temp)
                {
                    ans++;
                    s[m++]=d;
                }
            }
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        ans=0;
        scanf("%d%d",&A,&B);
        for(int i=A;i<=B;i++)
        {
            check(i);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
