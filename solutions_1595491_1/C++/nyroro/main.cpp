#include <iostream>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int _;
    scanf("%d",&_);
    for(int ti=1;ti<=_;ti++)
    {
        int n,s,p;
        int arr[101];
        cin>>n>>s>>p;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int u=arr[i]/3;
            int v=arr[i]%3;
            bool flag=false;
            if(v==0)
            {
                if(u>=p)ans++;
                else if(s&&u&&u+1>=p)
                {
                    s--;
                    ans++;
                }
            }
            else if(v==1)
            {
                if(u+1>=p)ans++;
            }
            else
            {
                if(u+1>=p)ans++;
                else if(u+2>=p&&s)
                {
                    ans++;s--;
                }
            }
        }
        cout<<"Case #"<<ti<<": "<<ans<<endl;
    }
    return 0;
}
