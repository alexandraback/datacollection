#include <iostream>
#include <vector>
using namespace std;

int T, D;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        int ans = 0x7fffffff, P;
        vector<int> inp;

        cin >> D;
        for(int i=0; i<D; i++){
            cin >> P;
            inp.push_back(P);
        }

        for(int h=1024; h>=1; h--){
            int splits = 0;

            for(int v : inp)
                splits += (v + h - 1) / h - 1;

            ans = min(ans, splits + h);
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

}
