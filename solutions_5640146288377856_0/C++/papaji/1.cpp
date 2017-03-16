#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    int temp,r,c,w,ans;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        scanf("%d%d%d",&r,&c,&w);
        ans+=(r-1)*(c/w);
        temp=c/w;
        ans+=temp;
        if(temp*w==c)
            ans=ans+w-1;
        else
            ans+=w;
        printf("Case #%d: %d\n",i,ans);
    }


    return 0;
}
