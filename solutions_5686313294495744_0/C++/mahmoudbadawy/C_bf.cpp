#include <bits/stdc++.h>
#define cbits(x) __builtin_popcount(x)

using namespace std;

string a[20],b[20];
int n;
int mem[1<<17];

int go(int mask)
{
    int ind=cbits(mask);
    if(ind>=n)
    {
        return 0;
    }
    if(mem[mask]!=-1) return mem[mask];
    mem[mask]=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        bool ok1=0,ok2=0;
        for(j=0;j<n;j++)
        {
            if(!(mask&(1<<j))) continue;
            if(a[i]==a[j]) ok1=1;
            if(b[i]==b[j]) ok2=1;
        }
        mem[mask]=max(mem[mask],(ok1&&ok2)+go(mask|(1<<i)));
    }
    return mem[mask];
}

int main()
{
    freopen("C_small.in","r",stdin);
    freopen("C_small.out","w",stdout);
    int t;
    cin >> t;
    int tc;
    for(tc=1;tc<=t;tc++)
    {
        cin >> n;
        int i;
        for(i=0;i<n;i++)
            cin >> a[i] >> b[i];
        memset(mem,-1,sizeof mem);
        cout << "Case #" << tc << ": " << go(0) << endl;
    }
}
