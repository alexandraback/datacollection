#include <iostream>
#include <map>
using namespace std;

int t, r, n, m, k, p[100];
int selected[100];
int ans[100];
long long ppp;

long long pro()
{
    map<int, int> hash;
    int limit=1<<n;
    for(int i=0; i<limit; ++i)
    {
        int temp=1;
        for(int j=0; j<n; ++j)
            if(i&(1<<j))
                temp*=selected[j+1];
        /*if(hash.find(temp)!=hash.end()) ++hash[temp];
        else hash[temp]=1;
        cout<<hash[temp]<<endl;*/
        hash[temp]+=1;
    }
    long long tt=1;
    for(int i=1; i<=k; ++i)
    {
        tt*=hash[p[i]];
        //cout<<"p"<<p[k]<<" "<<k<<endl;
    }
    return tt;
}

void permutate(int layer, int start)
{
    if(layer==n+1)
    {
        //for(int i=1; i<=n; ++i)
        //    cout<<selected[i];
        //cout<<endl;
        //for(int i=1; i<=k; ++i)
        //    cout<<p[i];
        //cout<<endl;
        long long pp = pro();
        for(int i=1; i<=n;)
        {
            int j=i+1, rep=1;    
            for(; j<=n; ++j)
                if(selected[j]==selected[i])
                    ++rep;
            pp*=rep;
            i=j;
        }
        //cout<<pp<<endl;
        if(pp>ppp)
        {
            ppp=pp;
            for(int i=1; i<=n; ++i)
                ans[i]=selected[i];
        }
        return;
    }
    for(int i=start; i<=m; ++i)
    {
        selected[layer]=i;
        permutate(layer+1, i);
    }
}

void calculate()
{
    ppp=-1;
    permutate(1, 2);
    for(int i=1; i<=n; ++i)
        cout<<ans[i];
    cout<<endl;
}

int main()
{
    cin>>t>>r>>n>>m>>k;
    cout<<"Case #1:"<<endl;
    for(int i=1; i<=r; ++i)
    {
        for(int j=1; j<=k; ++j)
            cin>>p[j];
        calculate();
    }
    return 0;
}
