#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("B-large (1).in","r",stdin);
    freopen("1a2large.txt","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n;
        cin>>n;
        int a[2501]={0};
        int ans[n];
        int min=2501,max=0;
        for(int i=0;i<((2*n)-1);i++)
        {
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                a[x]++;
                if(x<min)
                    min=x;
                if(x>max)
                    max=x;
            }
        }
        int w=0;
        for(int r=min;r<=max;r++)
        {
            if(a[r]%2)
                ans[w++]=r;
        }

        cout<<"Case #"<<q<<": ";
        for(int u=0;u<n;u++)
            cout<<ans[u]<<" ";
        cout<<"\n";

    }
    return 0;
}
