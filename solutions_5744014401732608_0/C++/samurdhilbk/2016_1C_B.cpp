#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;

map<int,ll> mp;

pr next(pr current,int b){
    if(current==make_pair(0,0)) return make_pair(0,1);
    if(current.second<b-1) return make_pair(current.first,current.second+1);
    else if(current.first<b-1) return make_pair(current.first+1,0);
    else return make_pair(-1,-1);
}

ll num(vector<vector<int> > & grid,int s,int b){
    if(s==b-1) return 1;
    ll sm=0;
    for(int i=0;i<b;i++){
        if(grid[s][i]==1) sm+=num(grid,i,b);
    }
    mp[s]=sm;
    return sm;
}

int main(){
    ios_base::sync_with_stdio(false);
    int tt;
    cin>>tt;
    for(int t=0;t<tt;t++){
        mp.clear();
        ll b,m;
        cin>>b>>m;
        vector<int> tmp(b,0);
        vector<vector<int> > grid(b,tmp);
        for(int i=0;i<b-1;i++){
            for(int j=i+1;j<b;j++) grid[i][j]=1;
        }
        pr current=make_pair(0,0);
        while(true){
            ll ret=num(grid,0,b);
            //cout<<ret<<endl;
            
            if(ret<m){
                printf("Case #%d: IMPOSSIBLE\n",t+1);
                break;
            }
            if(ret==m){
                printf("Case #%d: POSSIBLE\n",t+1);
                for(int i=0;i<b;i++){
                    for(int j=0;j<b;j++) printf("%d",grid[i][j]);
                    printf("\n");
                }
                break;
            }
            else{
                current=next(current,b);
                if(current.first==current.second) current=next(current,b);
                //cout<<current.first<<" "<<current.second<<endl;
                if(current==make_pair(-1,-1)){
                    printf("Case #%d: IMPOSSIBLE\n",t+1);
                    break;
                }
                grid[current.first][current.second]=0;
            }
        }
    }
}