#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>

#define MAXN 1000

using namespace std;

int n;
int a[MAXN][MAXN];
bool start[MAXN];
bool visited[MAXN];

void revercedfs(int s ){
   // cout<<"{ s = "<<s+1<<endl;
    visited[s]=1;
    bool out=0;
    for(int i = 0; i < n ; ++i){
        if(a[s][i]){
            out = 1;
            if ( visited[i] == 0){
                revercedfs(i);
            }
        }
    }
    if(out == 0){
        start[s] = 1;
    }
   /// cout<<"start["<<s+1<<"]="<<start[s]<<"}"<<endl;
}

bool dfs(int s){
 //   cout<<"{ s = "<<s+1<<endl;
    visited[s] = 1;
    for(int i = 0 ; i < n ; ++i){
        if(a[i][s] && i!=s){
            if(visited[i]==0){
                if(dfs(i)==0){
                    return 0;
                }
            }else{
                //cout<<"#!@%^$"<<i;
                return 0;
            }
        }
    }
    //cout<<"}"<<endl;
    return 1;
}


void go(){
    int size;
    cin >> n;
    memset(start,0,sizeof(start));
    memset(visited,0,sizeof(visited));
    memset(a,0,sizeof(a));
    for(int i = 0 ; i < n ;++i){
        cin>>size;
        for(int j = 0 ; j < size; ++j){
            int x;
            cin>>x;
            --x;
            a[i][x] = 1;
        }
    }
    for(int j = 0 ; j < n ; ++j){
        if(visited[j] == 0)
            revercedfs(j);
    }
    /*cout<<endl;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    for(int i = 0 ; i < n ; ++i){
        if(start[i]){
            //cout<<i+1<<" ";
            memset(visited,0,sizeof(visited));
            if(!dfs(i)){
                cout<<"Yes";
                return;
            }
        }
    }
    cout<<"No";
}

int main(){
    int T;
    cin>>T;
    for(int test = 0 ; test < T ; ++test){
        cout<<"Case #"<<test+1<<": ";
        go();
        cout<<endl;
    }
}
