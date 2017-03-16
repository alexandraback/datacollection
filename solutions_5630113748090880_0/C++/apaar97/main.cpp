#include <bits/stdc++.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
#define lli long long int
#define li long int

using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("C:\\Users\\atul5095\\Downloads\\B-small-attempt0.in","r",stdin);
    freopen("B-small-output.out","w",stdout);
    //freopen("C:\\Users\\atul5095\\Downloads\\B-large.in","r",stdin);
    //freopen("B-large-output.out","w",stdout);
    lli t,c;
    cin>>t;
    for(c=1;c<=t;c++)
    {   cout<<"Case #"<<c<<": ";
        lli n,i,j,x,arr[2501]={0};
        cin>>n;
        for(i=1;i<2*n;i++)
        {   for(j=1;j<=n;j++)
            {   cin>>x;
                arr[x]++;
            }
        }
        for(i=1;i<=2500;i++)
            if(arr[i]%2)
                cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
