#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

#define PB push_back
#define MP make_pair
#define SL size()
#define LE length()
#define INFI 2000000000
#define X first
#define Y second
#define MIN(a,b) ((a)<(b)?(a):(b))

int T,K,N;
int CH_TYPE[205];
map<int,int> CHESTS[205];
void printi(vector<int> &seen){ 
        for(int i = 1; i <= N;i++){
            for(int j = 0;j<int(seen.SL);j++){
                if(seen[j] == i) cout<<" "<<j;
            }
        }cout<<endl;
}

bool isPossible(map<int,int> &keys, vector<int> &seen){
     int ty[205],ke[205];  
     for(int i=0;i<= N;i++) ty[i] = ke[i] = 0;

     for(map<int,int>::iterator it = keys.begin(); it != keys.end() ;it++){
        if(it->first > N) break;
        ke[it->first] += it->second;
     }
     for(int n = 1; n <= N; n++){
         if(seen[n]) continue;
         ty[CH_TYPE[n]]++;
         for(map<int,int>::iterator it = (CHESTS[n]).begin(); it != (CHESTS[n]).end(); it++){
            ke[it->first] += it->second;
         }
     }
     
     for(int i = 1; i <= N; i++) {
             if(ty[i] > ke[i]) return false;
             for(int n = 1;n<=N;n++){
                 if(seen[n])continue;
                 if(CH_TYPE[n] == i && ((CHESTS[n])[i] == ke[i]) ){
                      //         cout<<"N: "<<n<<" I: "<<i<<" TY: "<<ty[i]<<" KE: "<<ke[i]<<endl;
                    return false;
                 }
             }
     }
     return true;
}
     
bool dfs(int source,int cant, vector<int> &seen, map<int,int> &keys){
     if(cant == N){
        printi(seen);
        return true;
     }
     
     //recover source keys
     map<int,int>::iterator it;
     for(it = (CHESTS[source]).begin(); it != (CHESTS[source]).end(); it++){
         keys[it->first] += it->Y;
     }
     if(!isPossible(keys,seen)){
        return false;
     }
    /* int source_keys = int(CHESTS[source].SL);
     
     for(int i = 0;i<source_keys;i++){
         keys[CHESTS[source][i]]++;   
     }*/ //cout<<source<<" "<<cant<<endl;
     //printi(seen);
     bool ok = false;
     
     for(int n = 1; !ok && n <= N;n++){
         if(seen[n])continue;
         it = keys.find(CH_TYPE[n]);
         if(it != keys.end() && it->Y > 0){
               (it->Y)--;
               seen[n] = cant + 1;
               ok = dfs(n, cant + 1, seen, keys);
               seen[n] = 0;
               (it->Y)++;
         }
     }
     
     //asign keys to the previous state
     /*for(int i = 0;i<source_keys;i++){
         keys[CHESTS[source][i]]--;   
     }*/
      for(it = (CHESTS[source]).begin(); it != (CHESTS[source]).end(); it++){
         keys[it->first] -= it->Y;
     }    
     return ok;
}
     
int main(){    
    cin>>T;
    for(int kases = 1;kases <= T; kases++){
        cin>>K>>N;
        int ac;
        map<int,int> keys; for(int i = 1;i<=N;i++) keys[i] = 0;
        map<int,int>::iterator it;
        vector<int> seen(N+1,0);
        for(int i = 0;i<K;i++){ cin>>ac; keys[ac]++;}
        for(int n = 1;n<=N;n++){
           int k; cin>>CH_TYPE[n]>>k;
           CHESTS[n].clear();
           for(int j = 0;j < k;j++){
               cin>>ac;// CHESTS[n].PB(ac);
               (CHESTS[n])[ac]++;
           }
        }
        cout<<"Case #"<<kases<<":";
        bool ok = false;
        if(isPossible(keys, seen)){
            for(int n = 1; !ok && n <= N; n++){
                it = keys.find(CH_TYPE[n]);
                if(it != keys.end() && it->Y > 0){
                  seen[n] = 1;
                  (it->Y)--;
                  ok = dfs(n, 1, seen, keys);
                  (it->Y)++;
                  seen[n] = 0;
                }
            }
        }
        
        if(!ok) cout<<" IMPOSSIBLE"<<endl;
    }
}
