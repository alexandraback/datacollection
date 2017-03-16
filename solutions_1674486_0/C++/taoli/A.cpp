#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;

#define MAX 1005

bool Map[MAX][MAX]={0};

bool Visit[MAX] = {0};

int InDegree[MAX] = {0};

bool Mark[MAX] = {0};

int T,N,M,to;

bool BFS(int s){
    Mark[s]= true;
    for(int i=1;i<=N;i++){
        if(Map[s][i]){
            if(Mark[i])
              return true;
            else{
               Mark[i] = true;
               if(BFS(i))
                 return true;
            }
        }
    }
    return false;
}


int main(int argc,char *argv[]){

    ofstream f;
    f.open("D:/out.in");



    scanf("%d",&T);

    for(int i=1;i<=T;i++){
        scanf("%d",&N);
        memset(Map,0,sizeof(Map));
        memset(Visit,0,sizeof(Visit));
        memset(InDegree,0,sizeof(InDegree));
        for(int j=1;j<=N;j++){
            scanf("%d",&M);
            while(M--){
                scanf("%d",&to);
                Map[j][to] = true;
                InDegree[to] += 1;
            }
        }
        int start = -1;
        bool found = false;
        while(!found){
            start = -1;
            for(int j=1;j<=N;j++)
                if((!Visit[j])&&(InDegree[j]==0)){
                   start = j;
                   Visit[j] = true;
                   break;
                }
            if(start == -1)
                break;
            memset(Mark,0,sizeof(Mark));
            found = BFS(start);
        }

        f<<"Case #"<<i<<": ";
        cout<<"Case #"<<i<<": ";
        if(found){
            cout<<"Yes"<<endl;
            f<<"Yes"<<endl;
        }

        else{
            cout<<"No"<<endl;
            f<<"No"<<endl;
        }

    }

    f.close();

}
