#include<iostream>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
int K,N;
int numkeys[201];
int path[21];
int keytype[20];
vector<int> new_keys[20];
static bool visited[1048576];
bool found;
void init(){
    for (int i=0;i<201;i++) numkeys[i] = 0;
    found = false;
    for (int i=0;i<(1<<N);i++) visited[i] = false;
    for (int i=0;i<N;i++) new_keys[i].clear();
    for (int i=0;i<N;i++) path[i] = N-i;
}
void dfs(int dep,int num){
    if (num==(1<<N)-1){
        path[N] = (1<<N)-1;
        found = true;
        return;
    }
    path[dep] = num;
    visited[num] = true;
    for(int i=0;i<N;i++){
        if (((num&(1<<i))==0) && (numkeys[keytype[i]]>0) && (!visited[num^(1<<i)])){
            //cout<<"searching...";
            numkeys[keytype[i]]--;
            for (vector<int>::iterator it = new_keys[i].begin(); it<new_keys[i].end(); it++){
                numkeys[*it]++;
            }
            dfs(dep+1,(num^(1<<i)));
            numkeys[keytype[i]]++;
            for (vector<int>::iterator it = new_keys[i].begin(); it<new_keys[i].end(); it++){
                numkeys[*it]--;
            }
        }
        if (found) return;
    }
    //cout<<dep;
}
int main(){
    ifstream in("D.in"); ofstream out("D.out");
    int T;
    in>>T;
    //cout<<T<<"\n";
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        int K;
        in>>K>>N;
        init();
        //cout<<K<<" "<<N<<"\n";
        for (int i=0;i<K;i++){
            int a;
            in>>a;
            //cout<<a<<" ";
            numkeys[a]++;
        }
        //cout<<"\n";
        for (int i=0;i<N;i++){
            in>>keytype[i];
            int n;
            in>>n;
            for (int j=0;j<n;j++){
                int a;
                in>>a;
                new_keys[i].push_back(a);
            }
        }
        //for (int i=0;i<N;i++) cout<<keytype[i]<<" "<<numkeys[keytype[i]]<<"\n";;cout<<"\n";
        dfs(0,0);
        if (found){
            for (int i=0;i<N;i++){
                for (int j=0;j<N;j++){
                    if ((path[i]^path[i+1])==(1<<j)){
                        out<<j+1<<" ";
                        break;
                    }
                }
            }
            //cout<<"\n";
        }
        else{
            out<<"IMPOSSIBLE";
        }
        out<<"\n";
    }
}
