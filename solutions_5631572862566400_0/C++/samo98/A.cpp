#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
vector<vector<int> > W;
vector<int> V;
int dfs(int vrch)
{
    int vrat=0;
    for(int i=0;i<W[vrch].size();i++)
    {
        int sused=W[vrch][i];
        if(sused==V[vrch])continue;
        vrat=max(vrat,1+dfs(sused));
    }
    return vrat;
}
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>n;V.assign(n,0);
        int odpoved=0;
        W.clear();W.assign(n,vector<int>(0));
        vector<int> dvojice;
        for(int i=0;i<n;i++)
        {
            cin>>V[i];V[i]--;
            W[V[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(V[V[i]]==i)dvojice.push_back(i);
        }
        vector<int> vela(dvojice.size(),0);
        for(int i=0;i<dvojice.size();i++)
        {
            vela[i]=dfs(dvojice[i]);
            odpoved+=vela[i];
        }
        odpoved+=dvojice.size();
        vector<int> bol(n,-1),kedy(n,-1);
        for(int i=0;i<dvojice.size();i++)bol[dvojice[i]]=-2;
        for(int i=0;i<n;i++)
        {
            if(bol[i]>=0 || bol[i]==-2)continue;
            int kde=i;
            bol[i]=0;
            while(true)
            {
                int stary=kde;
                kde=V[kde];
                if(bol[kde]==-2 || (kedy[kde]>=0 && kedy[kde]!=i))break;
                if(bol[kde]==-1){kedy[kde]=i;bol[kde]=bol[stary]+1;continue;}
                odpoved=max(odpoved,bol[stary]+1-bol[kde]);
                break;
            }
        }
        cout <<"Case #"<<ij<<": "<<odpoved<<endl;
    }
    return 0;
}
