#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
int n,r,k,m;
int T;
int data[105];
int ans[5];
bool is2;
void guess()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=k;i++)
    {
        if(data[i]%2==0)
            is2=1;
        int cnt = n;
        for(int j=0;j<n;j++)
        {
            if(ans[j] && data[i]%ans[j]==0)
            {
                data[i]/=ans[j];
                cnt--;
            }
        }
        if(data[i]==2)
        {
            if(!ans[0])
                ans[0]=2;
            else if(!ans[1])
                ans[1]=2;
            else if(!ans[2])
                ans[2]=2;
            data[i]/=2;
        }
        if(cnt==1 && data[i]!=1)
        {
            if(!ans[0])
                ans[0]=data[i];
            else if(!ans[1])
                ans[1]=data[i];
            else if(!ans[2])
                ans[2]=data[i];
            data[i]/=data[i];
        }
        if(data[i]%16==0)
        {
            if(!ans[0])
                ans[0]=4;
            else if(!ans[1])
                ans[1]=4;
            else if(!ans[2])
                ans[2]=4;
            data[i]/=4;
        }
        if(data[i]%5==0)
        {
            if(!ans[0])
                ans[0]=5;
            else if(!ans[1])
                ans[1]=5;
            else if(!ans[2])
                ans[2]=5;
            data[i]/=5;
        }
        if(data[i]%5==0)
        {
            if(!ans[0])
                ans[0]=5;
            else if(!ans[1])
                ans[1]=5;
            else if(!ans[2])
                ans[2]=5;
            data[i]/=5;
        }
        if(data[i]%3==0)
        {
            if(!ans[0])
                ans[0]=3;
            else if(!ans[1])
                ans[1]=3;
            else if(!ans[2])
                ans[2]=3;
            data[i]/=3;
        }
        if(data[i]%3==0)
        {
            //cout<<"come here"<<endl;
            if(!ans[0])
                ans[0]=3;
            else if(!ans[1])
                ans[1]=3;
            else if(!ans[2])
                ans[2]=3;
            data[i]/=3;
        }
        for(int j=0;j<n;j++)
        {
            if(ans[j] && data[i]%ans[j]==0)
            {
                data[i]/=ans[j];
                cnt--;
            }
        }
        if(cnt==1 && data[i]!=1)
        {
            //cout<<"i am here"<<endl;
            if(!ans[0])
                ans[0]=data[i];
            else if(!ans[1])
                ans[1]=data[i];
            else if(!ans[2])
                ans[2]=data[i];
            data[i]/=data[i];
        }
    }
//    for(int j=0;j<n;j++)
//    {
//        cout<<ans[j]<<" ";
//    }
//    cout<<endl;
}
int main()
{
    freopen("C-small-1-attempt3.in","r",stdin);
    freopen("out3.1.txt","w",stdout);
    int cas =1;
    cin>>T;
    while(T--)
    {
        printf("Case #%d:\n",cas++,ans);
        cin>>r>>n>>m>>k;
        is2=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>data[j];
            }
            guess();
//            for(int j=0;j<n;j++)
//            {
//                cout<<ans[j]<<" ";
//            }
//            cout<<endl;
//            cout<<"hahah done"<<endl;
            for(int j=0;j<n;j++)
            {
                //cout<<"j "<<j<<" "<<ans[j]<<endl;
                if(ans[j])
                {                  //  cout<<"fuck"<<endl;
                    cout<<ans[j];
                    continue;
                }
                else if(is2)
                {
                    //cout<<"hehe"<<endl;
                    if(rand()&1)
                        cout<<"2";
                    else
                        cout<<"4";
                }
                else
                {
                    int t=rand();
                    while(!(t>=2&&t<=m))
                    {
                        t=rand();
                    }
                    cout<<t;
                }
            }
            cout<<endl;
        }

    }
    return 0;
}
