#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector < vector <int > > graf;
int vis[10000];
bool diamant=false;
int dfs(int i,int r){
    for(int j=0;j<graf[i].size();j++){
        int y=graf[i][j];
        //cout<<"from i "<<i<<" to "<<y<<endl;
        //cout<<"visited "<<vis[y]<<endl;
        //cout<<"root "<<r<<endl;
        if(vis[y]==r){diamant=true;}
        vis[y]=r;
        dfs(y,r);
    }
}
int main(){
    int T,N,M,x,y;
    ifstream ifile;
    ifile.open("input.txt");
    ofstream ofile;
    ofile.open("output.txt");
    ifile>>T;
    for(int i=0;i<T;i++){
        ifile>>N;
        diamant=false;
        graf.clear();
        graf.resize(N+1);
        vis[0]=0;
        for(int j=0;j<N;j++){
            ifile>>M;
            vis[j+1]=0;
            for(int a=0;a<M;a++){
                ifile>>x;
                graf[j+1].push_back(x);
            }
        }
        //cout<<"CAse "<<i+1<<endl;
        for(int a=1;a<=N;a++){
            if(!vis[a]){
                //cout<<"from "<<a<<endl;
                vis[a]=a;
                dfs(a,a);
            }
        }
        ofile<<"Case #"<<i+1<<":";
        if(diamant) ofile<<" Yes\n";
        else ofile<<" No\n";
    }
    return 0;
}
