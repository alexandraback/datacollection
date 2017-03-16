#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define F first
#define S second
vector<vector<int> > v;

vector<int> tsort;

int n,h;
bool vis[1004];
int dp=0,dpi=0;
void dfs(int i,int dpth){
if(vis[i])return;
//cout<<" "<<i<<endl;
vis[i]=1;

for(int j=0; j<v[i].size(); j++)
    if(!vis[v[i][j]]){
            if((dpth+1)>dp){
                dp=dpth+1;
                 dpi=i;
            }
     dfs(v[i][j],dpth+1);}


}





int main()
{
    freopen("C-small-attempt0 (1).in","rt",stdin);
    freopen("out.txt","wt",stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
     v=   vector<vector<int> > (1003);
            dp=0;dpi=0;
       int d,mx=0;
       cin>>n;
       for(int j=1; j<=n; j++){
            cin>>d;
         v[j].push_back(d);
        v[d].push_back(j);
       }
      memset(vis,0,sizeof vis);
      for(int j=1; j<=n; j++){
        if(!vis[j])
            dfs(j,1);
      }

      memset(vis,0,sizeof vis);

dfs(dpi,1);


//v.clear();


cout<<"Case #"<<i<<": "<<dp<<endl;
    }
    return 0;
}
