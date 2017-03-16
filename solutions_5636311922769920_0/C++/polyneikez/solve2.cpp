#include<bits/stdc++.h>

std::vector < int > solve(int k, int c, int s);

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int k,c,s;
        vector < int > ret;
        cin >> k >> c >> s;
        
        ret = solve(k,c,s);
        
        if (ret.empty()){
            cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE" << endl;        
        }else{
            cout << "Case #" << i + 1 << ":";
            for (int j = 0; j < ret.size(); j++){
                cout << " " << ret[j]; 
            }
            cout << endl;
        }
    }
}

vector < int > solve(int k, int c, int s){

    vector <int > ret;
    for (int i = 1; i <= k; i++){
        ret.push_back(i);
    }
    
    return ret;
}
