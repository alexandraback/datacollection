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
        int D;
        cin >> D;
        vector<int> P(D);
        for(int i=0;i<D;i++) cin >> P[i];
        
        int best = 1000;
        for(int M=1;M<=1000;M++){
            int spec = 0;
            for(int i=0;i<D;i++) spec+= (P[i]-1)/M;
            if(spec+M<best) best = spec+M;
        }
        
        cout << "Case #" << t << ": " << best << endl;    
    }

    return 0;
}