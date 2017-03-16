#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;


int N;
bool rec(map<int,vector<int> > &sol, vector<int> &n, vector<int> &psol, int i, int s){
     if(i == N && sol.count(s)){
          cout << sol[s][0];
          for(int i=1;i<sol[s].size();i++)
                  cout << " " << sol[s][i];
          cout << endl;
          cout << psol[0];
          for(int i=1;i<psol.size();i++)
                  cout << " " << psol[i];
          cout << endl;
          return true;
     }
     else if(i == N){
          sol[s] = psol;
          return false;
     }
     if(rec(sol, n, psol, i+1, s)) return true;
     psol.push_back(n[i]);
     bool r = rec(sol,n,psol,i+1,s+n[i]);
     psol.resize(psol.size()-1);
     return r;
}

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
            cin >> N;
            vector<int> n(N);
            for(int i=0;i<N;i++) cin >> n[i];
            
            cout << "Case #" << t << ":" << endl;
            map<int, vector<int> > sol;
            vector<int> psol;
            if(!rec(sol, n, psol, 0, 0))
                         cout << "Impossible" << endl;
    }
}
