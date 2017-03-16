#include <bits/stdc++.h>
using namespace std;
int e[1000];
vector<int> r[1000];
int n;
bool v[1000];
int mcyc,cyc2;
void dfs(int o,int i,int l)
{
    if(v[i])
    {
        if(i!=o)return;
        mcyc=max(mcyc,l);
        return;
    }
    v[i]=1;
    dfs(o,e[i],l+1);
}
int rdfs(int i)
{
    int s=0;
    for(auto &j:r[i])
        s=max(s,rdfs(j));
    return s+1;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int q=1;q<=t;q++)
    {
        cin >> n;
        for(auto &i:r)
            i.clear();
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            e[i]=a-1;
            r[a-1].push_back(i);
        }
        mcyc=cyc2=0;
        for(int i=0;i<n;i++)
        {
            fill(v,end(v),0);
            dfs(i,i,0);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(e[i]==j && e[j]==i)
                {
                    cyc2+=2;
                    int si=0,sj=0;
                    for(auto &k:r[i])
                        if(k!=j)
                            si=max(si,rdfs(k));
                    for(auto &k:r[j])
                        if(k!=i)
                            sj=max(sj,rdfs(k));
                    cyc2+=si+sj;
                }

            }
        }
        cout << "Case #" << q << ": " << max(mcyc,cyc2) << "\n";
    }
    return 0;
}
