#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int t,ans,a[2000],n;

int main()
{
    ifstream cin("B-small-attempt0.in");
    ofstream cout("B-small-attempt0.out");
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ans=1000000000;
        for(int i=1;i<=1000;i++)
        {
            int ans1=i;
            for(int j=0;j<n;j++)
                ans1+=(a[j]-1)/i;
            ans=min(ans,ans1);
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}
