#include <bits/stdc++.h>
using namespace std;

vector<bool> ps;

void flipStack(int n){
    for(int i = 0; i < n/2; i++){
        swap(ps[i], ps[n-1]);
    }
    for(int i = 0; i < n; i++){
        ps[i] = !ps[i];
    }
}

int main(){
    int n;
    cin >> n;
    for(int ii = 1; ii <= n; ii++){
        ps.clear();
        string line;
        cin >> line;
        for(char c : line){
            ps.push_back(c == '-' ? false : true);
        }
        
        int numflips = 0;
        while(true){
            bool frontval = ps[0];
            bool notsame = true;
            for(int i = 0; i < ps.size(); i++){
                if(frontval != ps[i]){
                    numflips++;
                    flipStack(i);
                    notsame = false;
                    break;
                }
            }
            if(!notsame) continue;
            else break;
        }
        if(!ps[0]) numflips++;
        cout << "Case #" << ii << ": " << numflips << endl;;
    }
}
