#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int xx[22];
int n;
vector<int>x[2000000];
void ddd(int h,int all,int b)
{
    if(h==n+1)
    {
        if(b==0)return ;
        x[all].push_back(b);
        return ;
    }
    ddd(h+1,all,b*2);
    ddd(h+1,all+xx[h],b*2+1);
}
int main()
{
int t;
cin>>t;
for(int ii=1;ii<=t;ii++)
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>xx[i];
    for(int i=0;i<2000000;i++)x[i].clear();
    ddd(1,0,0);
   // cout<<"==";
    bool f=0;
    //for(int i=0;i<2000000;i++)if(x[i].size()!=0)cout<<x[i].size()<<" "<<i<<endl;
    for(int i=0;i<2000000;i++)
    {

        for(int j=0;j<x[i].size();j++)
        {

            for(int k=j+1;k<x[i].size();k++)
            {

                if((x[i][j]&x[i][k])==0)
                {
                    cout<<"Case #"<<ii<<":"<<endl;
                    bool g=0;
                    int h=1;
                    for(int f=(1<<(n-1));f>=1;f/=2)
                    {
                        if((f&x[i][j])>0)
                        {
                            if(g)cout<<" ";
                            cout<<xx[h];
                            g=1;
                        }
                        h++;
                    }
                    cout<<endl;
 g=0;
                     h=1;
                    for(int f=(1<<(n-1));f>=1;f/=2)
                    {
                        if((f&x[i][k])>0)
                        {
                            if(g)cout<<" ";
                            cout<<xx[h];
                            g=1;
                        }
                        h++;
                    }
                    cout<<endl;
                    f=1;
                }
                if(f)break;
            }
            if(f)break;
        }
        if(f)break;
    }
    if(!f)cout<<"Impossible\n";
}
return 0;
}
