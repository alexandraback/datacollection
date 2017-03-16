#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>

using namespace std;   
bool visited[201][201][501];
bool ok[201][201];

int main(){      
    
    
    queue<pair<pair<int,int>,string> >Q;
    string gainor[201][201];
    memset(visited,0,sizeof(visited));
    memset(ok,0,sizeof(ok));
    
    
    Q.push( make_pair(make_pair(100,100),""));
    gainor[100][100]="";
    visited[100][100][0]=1;
    ok[100][100]=1;
    
    int di[4]={0,1,0,-1};
    int dj[4]={-1,0,1,0};
    string dir[4]={"S","E","N","W"};
    
    while(!Q.empty()){
        pair<pair<int,int>,string> P = Q.front();
        Q.pop();
        string s=P.second;
        pair<int,int>X=P.first;
        int val=s.size()+1;
        
        if(s.size()>500)break;
        
        for(int i=0;i<4;i++){
            int x=X.first+di[i]*val;
            int y=X.second+dj[i]*val;
            if(x>=0 && x<=200 && y>=0 && y<=200){
                if(!ok[x][y]){
                    gainor[x][y]=s+dir[i];
                }
                
                if(!visited[x][y][val]){
                    visited[x][y][val]=1;
                    Q.push(make_pair(make_pair(x,y),s+dir[i] ));    
                }
                
                ok[x][y]=1;    
            }    
        }
        
    }
    
    
    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        int a,b;
        cin>>a>>b;
        cout<<"Case #"<<caso<<": "<<gainor[a+100][b+100]<<endl;    
    }
    
    
    return 0;
}
