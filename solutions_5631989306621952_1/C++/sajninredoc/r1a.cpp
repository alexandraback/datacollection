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
        string S;
        cin >> S;
        
        string best = "";
        best += S[0];
        for(int i=1;i<S.length();i++){
//            cout << S[i] << " " << best << endl;
            if(S[i] >= best[0]){
                best.insert(0, 1, S[i]);
            }else if(S[i] < best[0]){
                best += S[i];
            }
        }
        
        cout << "Case #" << t << ": " << best << endl;    
    }

    return 0;
}