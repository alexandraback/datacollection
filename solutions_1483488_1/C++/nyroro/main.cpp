#include <iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
bool vis[2000001];
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)
            vis[i]=false;

        int d=1;
        int n=a;
        while(n/10)
        {
            d*=10;
            n/=10;
        }

        set<int> s;
        int sum=0;

        for(int j=a;j<=b;j++)
        {
            if(!vis[j])
            {
                vis[j]=true;
                int nn=0;

                int v=j;
                do
                {
                    int first=v%10;
                    v=v/10+first*d;
                    if(v<=b&&v>=a)
                    {
                        vis[v]=true;
                        nn++;
                    }
                }while(v!=j);
                sum+=(nn-1)*nn/2;
            }
        }

        cout<<"Case #"<<ti<<": "<<sum<<endl;
    }
    return 0;
}
