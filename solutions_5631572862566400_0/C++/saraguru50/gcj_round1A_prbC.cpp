#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<vector>

using namespace std;

vector<long long>v[15];

bool visited[60];

long long maxm=1;

void dfs(long long root,long long next,long long val){

    long long i;
    visited[next]=true;
    if(val>maxm)maxm=val;
    for(i=0;i<v[next].size();i++){
        if(!visited[v[next][i]]){
            dfs(root,v[next][i],val+1);
        }
    }



}

int main(){

    freopen("gcj_round1A_input_prbC.txt","r",stdin);
    freopen("gcj_round1A_output_prbC.txt","w",stdout);
    int t,r;
    cin>>t;
    for(r=1;r<=t;r++){
        long long n,i,j,temp,ans=0;
        cin>>n;
        maxm=1;
    for(i=1;i<=n;i++){
            v[i].clear();
            visited[i]=false;
    }
    for(i=1;i<=n;i++){
        cin>>temp;
        v[i].push_back(temp);
        v[temp].push_back(i);
    }
    for(i=1;i<=n;i++){
        dfs(i,i,1);
        if(maxm>ans)ans=maxm;
        for(j=1;j<=n;j++)visited[i]=false;
        maxm=1;
    }
    cout<<"Case #"<<r<<": ";
    cout<<ans<<"\n";
}

return 0;




}
