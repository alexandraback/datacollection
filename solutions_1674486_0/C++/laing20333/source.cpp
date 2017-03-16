#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
#include <memory.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int adj[1003][1003];
int isuse[1003];
int nnode;
int end=0;
int counter=0;
void dfs(int pos){
    if(pos==end){
        counter++;
        return ;
    }
    int i,k,m;
    for(i=1;i<=nnode;i++){
        if(adj[pos][i]&&!isuse[i]){
            isuse[i]=1;
            dfs(i);
            isuse[i]=0;
        }
    }
    return;

}







int main(){
    //freopen("input.txt","r",stdin);
    freopen("A-small-attempt0(1).in","r",stdin);
    freopen("output.txt","w",stdout);

    int ntest;
    while(cin>>ntest){
        int tt;
        for(tt=0;tt<ntest;tt++){

        printf("Case #%d: ",tt+1);

        cin>>nnode;

        memset(adj,0,sizeof(adj));
        memset(isuse,0,sizeof(isuse));
        int i,k,m;
        int num,node;
        for(i=1;i<=nnode;i++){
            cin>>num;
            for(k=1;k<=num;k++){
                cin>>node;
                adj[node][i]=1;
            }
        }
        int isfind=0;
        for(i=1;i<=nnode;i++){

            for(k=1;k<=nnode;k++){
                if(i==k){
                    continue;
                }
                end=k;
                counter=0;
                dfs(i);
                if(counter>=2){
                    isfind=1;
                    i=k=nnode+1;
                    break;
                }
            }
        }
        if(isfind){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;




        }

    }


    return 0;
}
