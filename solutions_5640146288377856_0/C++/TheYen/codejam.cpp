#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("kk.in","r",stdin);
    freopen("kanish.out","w",stdout);
    int t,p=0;
    cin>>t;
    while(t--)
    {
        int a[500];
        memset(a,0,sizeof a);
        int r,c,m,w,ct=0,i,j;
        cin>>r>>c>>m;
        printf("Case #%d: ",++p);
        if(r==1)
        {

            j=c-m+1;
            int as=0;
            for(i=j;i<=c;i++)
                a[i]=1;
            for(i=1;i<=c;i=i+m)
            {
                if(a[i]==0)
                    as++;
                else
                    break;
            }
            cout<<as+m<<endl;
        }
        else
        {
            ct=ceil(c/m)*(r-1);
            cout<<ct<<endl;

            j=c-m+1;
            int as=0;
            for(i=j;i<=c;i++)
                a[i]=1;

            for(i=1;i<=c;i=i+m)
            {
              //  cout<<"hi"<<endl;
                if(a[i]==0)
                    as++;
                else
                    break;
            }
            cout<<ct+as+m<<endl;

        }
    }
    return 0;
}
