#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 103456


string s;

int mp[105][55];
int n;
int b[2677],a[5555];

int main()
{
    int T;
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    cin>>T;

    for (int _=1;_<=T;_++)
    {
        int n;
        cin>>n;
        memset(b,0,sizeof(b));
        for (int i=1;i<2*n;i++)
        for (int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            b[x]++;
        }

        int t=0;
        for (int i=1;i<=2500;i++)
        if (b[i]&1) a[++t]=i;

        printf("Case #%d: ",_);
        for (int i=1;i<t;i++) cout<<a[i]<<" ";
        cout<<a[n]<<endl;

    }
    return 0;
}
