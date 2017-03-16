#include <iostream>
#include<algorithm>

using namespace std;

long long MAX,ans,k,p,n,m,a[200];

int main()
{
    int qw;
    cin>>qw;
    for(int q=1;q<=qw;q++)
    {
        cin>>k>>n>>m;
        MAX=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        p=ans=MAX=0;
        while(MAX<m)
        {
            if(p>=n || a[p]>MAX+1)
                ans++,MAX+=(MAX+1)*k;
            else
            {
                MAX+=k*a[p];
                p++;
            }
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}
