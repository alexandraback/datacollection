#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        vector<int> f(N);
        for(int i=0;i<N;i++){
            cin >> f[i];
            f[i]--;
        }
        
        
        vector<int> root(N, -1);
        vector<int> cyc(N, 0);
        vector<int> path(N, 0);
        
        for(int i=0;i<N;i++){
            vector<int> travel(N, -1);
            int ind = i;
            int cnt = 0;
            while(travel[ind]==-1){
                travel[ind] = cnt;
                cnt++;
                ind = f[ind];
            }
            cyc[i] = cnt - travel[ind];
            root[i] = ind;
            path[i] = travel[ind]+1;
        }
        
        /*
        for(int i=0;i<N;i++){
            cout << i << ": " << f[i] << " " << cyc[i] << " " << root[i] << endl;
        }*/
        
        int best = 0;
        for(int i=0;i<N;i++) if(cyc[i]>best) best = cyc[i];
        
        vector<int> paths(N, 0);
        for(int i=0;i<N;i++){
           if(cyc[i]==2){
               paths[root[i]] = max(paths[root[i]], path[i]);
           }
        }
        int tpaths = 0;
        for(int i=0;i<N;i++) tpaths += paths[i];
        best = max(best, tpaths);
        
        cout << "Case #" << t << ": " << best << endl;
    }

    return 0;
}