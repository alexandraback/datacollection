#include<iostream>
#include<stdio.h>
using namespace std;
int pow10(int a)
{
    int i,ans=1;
    if(a==0)
        return 1;
    for(i=0;i<a;i++)
        ans=ans*10;
    return ans;              
}
int getl(int a)
{
    int l=0;
    while(a!=0)
    {
        l++;
        a/=10;
    }
    return l;
}
int work(int a,int c,int l)
{
    int m[10],i=0,ans=0,j,tem=a;;
    if(l==1)  return -1;
    while(a!=0)
    {
        m[i++]=a%10;
        a/=10;  
    }
    for(j=0;j<c;j++)
        ans+=m[c-1-j]*pow10(l-1-j);
    ans+=tem/pow10(c);
    return ans;
}
int main()
{
    //freopen("cpp.in","r",stdin);
    //freopen("cpp.out","w",stdout);
    int i,j,n,a,b,ans,l,t,times=0,used[10],l1,k,f;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        times++;
        ans=0;
        for(i=a;i<=b;i++)
        {
           l=getl(i);
           l1=0;
           for(j=1;j<l;j++)
           {
               t=work(i,j,l);
               f=0;
               if(t!=-1&&t<=b&&getl(t)==l&&t>i)
               {
                  for(k=0;k<l1;k++)
                       if(t==used[k])
                       {
                           f=1;
                           break;
                       }
                  if(f==0)
                  {
                       used[l1]=t;
                       l1++;
                       ans++;
                  }     
               }
           }
        }
        cout<<"Case #"<<times<<": "<<ans<<endl;
    }
}
