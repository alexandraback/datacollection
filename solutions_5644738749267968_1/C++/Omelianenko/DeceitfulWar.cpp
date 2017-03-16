#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

const int N=1001;
using namespace std;

#define ll long long

double q, a[N], b[N];
int num, x, y, t, i, n, l;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    cin>>t;
    while(t--)
    {
        l=1;
        x=0;
        num++;
        cin>>n;
        for(i=1; i<=n; i++)
            cin>>a[i];
        for(i=1; i<=n; i++)
            cin>>b[i];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        for(i=1; i<=n; i++)
            if(l<=n&&b[i]>a[l])l++;
        y=n-l+1;
        l=1;
        for(i=1; i<=n; i++)
            if(l<=n&&a[i]>b[l])l++;
        x=l;
        cout<<"Case #"<<num<<": "<<x-1<<" "<<y<<endl;
    }
}

