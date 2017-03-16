//
//  main.cpp
//  C
//
//  Created by ianto on 5/8/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {
    string id;
    int first;
    int second;
    int times;
} combination;

typedef struct{
    int J, P , S;
} outfit;

bool valid(outfit ofit, vector<combination> *combs, int K){
    vector<combination> cbs = *combs;
    bool jp = false, js = false, ps = false;
    for (int i = 0; i < cbs.size(); i++) {
        combination cb = cbs[i];
        if (cb.id == "jp" && cb.first == ofit.J && cb.second == ofit.P) {
            if (cb.times == K) {
                return false;
            }
            cb.times++;
            jp = true;
        }
        if (cb.id == "js" && cb.first == ofit.J && cb.second == ofit.S) {
            if (cb.times == K) {
                return false;
            }
            cb.times++;
            js = true;
        }
        if (cb.id == "ps" && cb.first == ofit.P && cb.second == ofit.S) {
            if (cb.times == K) {
                return false;
            }
            cb.times++;
            ps = true;
        }
        cbs[i] = cb;
    }
    if (!jp) {
        cbs.push_back({"jp", ofit.J, ofit.P, 1});
    }
    if (!js) {
        cbs.push_back({"js", ofit.J, ofit.S, 1});
    }
    if (!ps) {
        cbs.push_back({"ps", ofit.P, ofit.S, 1});
    }
    *combs = cbs;
    return true;
}

int main(int argc, const char * argv[]) {
//    freopen("test.txt", "r", stdin);
    //    freopen("C-small-attempt0.in.txt", "r", stdin);
    //    freopen("C-large.in.txt", "r", stdin);
    
    int T; cin >> T;
    
    for (int Case = 1; Case <= T; Case++) {
        int J, P, S, K; cin >> J >> P >> S >> K;
        
        int mi = min(min(J, P), S);
        
        vector<combination> combs;
        vector<outfit> result;
        if (mi == S) {
            for (int j = 1; j <= J; j++) {
                for (int p = 1; p <= P; p++) {
                    for (int s = 1; s <= S; s++) {
                        if (valid({j, p, s}, &combs, K)) {
                            result.push_back({j, p, s});
                        }
                    }
                }
            }
        }
        else if (mi == P){
            for (int j = 1; j <= J; j++) {
                for (int s = 1; s <= S; s++) {
                    for (int p = 1; p <= P; p++) {
                        if (valid({j, p, s}, &combs, K)) {
                            result.push_back({j, p, s});
                        }
                    }
                }
            }
        }
        else if (mi == J){
            for (int p = 1; p <= P; p++) {
                for (int s = 1; s <= S; s++) {
                    for (int j = 1; j <= J; j++) {
                        if (valid({j, p, s}, &combs, K)) {
                            result.push_back({j, p, s});
                        }
                    }
                }
            }
        }
        
        
        cout << "Case #" << Case << ": " << result.size() << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].J << " " << result[i].P << " " << result[i].S << endl;
        }
    }
    
    return 0;
}
