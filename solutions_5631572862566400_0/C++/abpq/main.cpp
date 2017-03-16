#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;
int t,n,num;
int fri[103][103];
vector<int> frnd[103];
int checked[103];
int visited[103];
int dfs(int n){
    visited[n]=1;
    checked[n]++;
    int maxi=0;
    int temp;
    long ss=frnd[n].size();
    for(int i=0;i<ss;i++){
        if(visited[frnd[n][i]]==-1 && (checked[frnd[n][i]]<2)){
            temp=dfs(frnd[n][i]);
            visited[frnd[n][i]]=-1;
            if(temp>maxi)
                maxi=temp;
        }
    }
    return maxi+1;
}
int dfsALL(){
    int maxii=0;
    int tem=0;
    for(int i=1;i<=n;i++){
        tem=dfs(i);
        if(tem>maxii)
            maxii=tem;
    }
    return maxii;
}
int main(){
    ofstream output;
    ifstream fcin;
    fcin.open("in.in");
    output.open("outout.out");

    fcin>>t;
    for(int i=1;i<=t;i++){
        memset(fri,-1,sizeof(fri));
        memset(visited,-1,sizeof(visited));
        memset(checked,0,sizeof(checked));
        fcin>>n;
        for(int j=1;j<=n;j++){
            fcin>>num;
            if(fri[j][num]==-1){
                frnd[j].push_back(num);
                frnd[num].push_back(j);
                fri[j][num]=1;
                fri[num][j]=1;
            }
        }
        output<<"Case #"<<i<<": ";
        output<<dfsALL()<<"\n";
        for(int j=1;j<=n;j++){
            frnd[j].clear();
        }
    }
    return 0;
}
