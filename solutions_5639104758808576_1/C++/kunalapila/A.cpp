#include<bits/stdc++.h>

using namespace std;

int main()
{
    static int T, m, sum, ans, a[100000];
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>m;
        for(int j=0;j<=m;j++)
            scanf("%1d",&a[j]);
        sum=0;
        ans=0;
        for(int j=0;j<=m;j++)
        {
            if(sum<j)
            {
                ans+=(j-sum);
                sum=j;
            }
            sum+=a[j];
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
