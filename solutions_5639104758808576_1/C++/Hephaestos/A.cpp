#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <deque>
#include <cstdint>

using namespace std;


void main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i){
        int r=0;
        int smax;
        cin >> smax;
        char c;
        //vector<int> s;
        int su = 0;
        for (int j = 0; j <= smax; ++j){
            cin >> c;
            int n = static_cast<int>(c-48);
            if (su < j){
                r += j - su;
                su = j;
            }
            su += n;
        }
        cout << "Case #" << i + 1 << ": " << r << endl;
    }
}