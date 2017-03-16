#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/in.txt");
ofstream cout("/Users/yangsiyu/Documents/HelloWorld/HelloWorld/out.txt");

int a[100],ans,r,n,ee;

void work(int e,int k,int sum)
{
    if (k==n+1)
    {
        if (sum>ans)
            ans=sum;
        return;
    }
    int i;
    for (i=0;i<=e;i++)
    {
        work(min(e-i+r,ee),k+1,sum+i*a[k]);
    }
}

int main()
{
    int t;
    int i,count=0;
    cin>>t;
    while (t--)
    {
        count++;
        cin>>ee>>r>>n;
        for (i=1;i<=n;i++)
            cin>>a[i];
        ans=0;
        work(ee,1,0);
        cout<<"Case #"<<count<<": "<<ans<<endl;
    }
    return 0;
}