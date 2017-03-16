#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a1[200],a2[200];
string ans1,ans2;
int b[100005],n;
int min1=INT_MAX;
int func(int i)
{
    //printf("%s %s %d\n",a1,a2,i);
    int j,k;
    if(i==n)
    {
        ll p=0,q=0;
        for(j=0;j<n;j++)
        {
            ll z=pow(10,n-j-1);
            p+=(a1[j]-'0')*z;
            q+=(a2[j]-'0')*z;
        }
        ll r=p-q;
        if(r<0)
        r=-r;
        if(r<min1)
        {
            ans1="";
            ans2="";
            for(j=0;j<n;j++)
            {ans1+=a1[j];
            ans2+=a2[j];}
            min1=r;
        }
    }
    else
    {
        if(a1[i]=='?' && a2[i]=='?')
        {
            for(j=0;j<=9;j++)
            {
                for(k=0;k<=9;k++)
                {


                a1[i]='0'+j;
                a2[i]='0'+k;
                func(i+1);
                a1[i]='?';
                a2[i]='?';
                }
            }
        }
        else
        {
            if(a1[i]=='?')
            {
                for(j=0;j<=9;j++){
                  a1[i]='0'+j;
                //a2[i]='0'+k;
                func(i+1);
                a1[i]='?';
                }
                //a2[i]='?';
            }
            else
            if(a2[i]=='?')
            {
                for(j=0;j<=9;j++){
                a2[i]='0'+j;
                //a2[i]='0'+k;
                func(i+1);
                a2[i]='?';
                }
                //a2[i]='?';
            }
            else
            {
                func(i+1);
            }
        }
    }
}
int main()
{
    ll t,p,i,j,r,c=1;

    freopen("B-small-attempt0 (4).in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s%s",&a1,&a2);
        n=strlen(a1);
        min1=INT_MAX;
        func(0);

        printf("Case #%lld: ",c++);
        cout<<ans1<<' '<<ans2;

        printf("\n");
        /*for(i=0;i<100;i++)
        {
            if(b[i]>0)
            {
                printf("%c",i);
                //break;
            }
        }*/

    }
    return 0;
}
