#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
ofstream fout("BFFs.out");
const int MAX_N=1024;
int t,n,bf[MAX_N],cur[MAX_N],idx=1,ans=0,realn;
bool used[MAX_N];
void solve()
{
    bool l=0;
    if(ans)return;
    if(idx==n+1)
    {
        for(int i=1;i<=n;++i)
        {
            if(i==1)
            {
                if(cur[n]!=bf[cur[i]]&&cur[i+1]!=bf[cur[i]]){l=1;break;}
            }
            else if(i==n)
            {
                if(cur[1]!=bf[cur[i]]&&cur[i-1]!=bf[cur[i]]){l=1;break;}
            }
            else if(cur[i+1]!=bf[cur[i]]&&cur[i-1]!=bf[cur[i]]){l=1;break;}
        }
        if(l==0)ans=n;
        return;
    }
    for(int i=1;i<=realn;++i)
    {
        if(!used[i])
        {
            used[i]=true;
            cur[idx]=i;
            ++idx;
            solve();
            --idx;
            used[i]=false;
        }
    }
}
int main()
{
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>bf[i];
        realn=n;
        while(n)
        {
            if(ans)break;
            solve();
            --n;
        }
        fout<<"Case #"<<o<<": "<<ans<<"\n";
        ans=0;
        idx=1;
    }
    return 0;
}
