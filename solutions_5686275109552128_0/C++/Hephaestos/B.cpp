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
        int n;
        cin >> n;
        vector<int> P;
        for (int j = 0; j < n; ++j){
            int p;
            cin >> p;
            P.push_back(p);
        }
        sort(P.begin(), P.end());
        int r;
        for (r = 1; r <= 1000; ++r){
            bool possible = false;
            for (int ns = 0; ns < r; ++ns){
                auto CP(P);
                int us = 0;
                possible = true;
                for (int j = n - 1; j >= 0; --j){
                    while (CP[j] > r - ns){
                        CP[j] -= (r - ns);
                        ++us;
                    }
                    if (us > ns) {
                        possible = false;
                        break;
                    }
                }
                if (possible) break;
            }
            if (possible) break;
        }
        cout << "Case #" << i + 1 << ": " << r << endl;
    }
}