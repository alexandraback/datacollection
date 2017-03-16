#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        bool ans=false;
        int x,r,c;
        cin>>x>>r>>c;
        int n=min(r,c);
        int m=max(r,c);
        if(n==1)
        {
            if(m==1)
            {
                ans=x==1;
            }
            else if(m==2)
            {
                ans=x<=2;
            }
            else if(m==3)
            {
                ans=x==1;
            }
            else if(m==4)
            {
                ans=x<=2;
            }
        }
        if(n==2)
        {
            if(m==2)
            {
                ans=x<=2;
            }
            else if(m==3)
            {
                ans=x<=3;
            }
            else if(m==4)
            {
                ans=x<=2;
            }
        }
        if(n==3)
        {
            if(m==3)
            {
                ans=(x==1||x==3);
            }
            else if(m==4)
            {
                ans=x<=4;
            }
        }
        if(n==4)
        {
            if(m==4)
            {
                ans=(x<=2||x==4);
            }
        }
        if(!ans)
        {
            cout<<"Case #"<<tt<<": RICHARD"<<endl;
        }
        else
        {
            cout<<"Case #"<<tt<<": GABRIEL"<<endl;
        }
    }
    return 0;
}
