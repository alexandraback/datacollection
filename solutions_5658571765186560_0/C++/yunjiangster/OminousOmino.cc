#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    string line;
    getline(cin, line);
    int T = atoi(line.c_str());
    int X,R,C;
    for (int i =0; i < T; ++i){
        getline(cin,line);
        stringstream ss(line);
        ss >> X >> R >> C;
        bool gab;
        bool canFit = true;
        for (int j = 0; j < X;++j){
            int k = X -j;
            if (min(j+1,k) > min(R,C) || max(j+1,k) > max(R,C)){
                canFit = false;
            }
        }
        if (!canFit){
            gab = false;
        }else if ( (R * C) % X != 0 || R < 1 || C < 1 ){
            gab = false;
        }else if (R == 1 || C == 1){
            gab = true;
        }else if (X > 6){
            gab = false;
        }else if (R == 2 || C == 2){
            if (X > 3){
                gab = false;
            }else{
                gab = true;
            }
        }else if (R == 3 || C == 3){
            if (X == 4 && max(R,C) == 3){   // doesn't happen
                gab = false;
            }else if (X == 5 && max(R,C) == 5){
                gab = false;
            }else if (X == 6){
                gab = false;
            }else {
                gab = true;
            }
        }else if (R ==4 || C ==4 ){
            if (X == 6){
                gab = false;
            }else{
                gab = true;
            }
        }else {
            gab = true;
        }
        string ans;
        if (gab){
            ans = "GABRIEL";
        }else{
            ans = "RICHARD";
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}
