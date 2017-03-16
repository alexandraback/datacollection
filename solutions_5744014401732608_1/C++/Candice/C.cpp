//
// Created by Yuxiang LI on 09/04/16.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T;
long long B,M,MM;
vector<int> factor(100);
vector<vector<int> > g(100);

/*bool dfs(int i, int j){
    if (i == B - 1){
        if (ways[B-1] == M)
            return true;
        else
            return false;
    }
    g[i][j] = 1;
    ways[j] += ways[i];
    if (j < B-1) {
        if (dfs(i, j + 1))
            return true;
    }
    else {
        if (dfs(i + 1, i + 2))
            return true;
    }
    g[i][j] = 0;
    ways[j] -= ways[i];
    if (j < B-1){
        if (dfs(i, j + 1))
            return true;
    }else{
        if (dfs(i + 1, i + 2))
            return true;
    }
    return false;
}*/

int main(){
    ifstream in("BB-large.in");
    ofstream out("output1.out");
    in >> T;
    for(int cases = 1; cases <= T; cases++){
        in >> B >> M;
        out << "Case #" << cases << ": ";
        long long maxi = 1;
        factor[0] = 0; factor[1] = 0; factor[2] = 0;
        for(int i = 3; i <= B; i++) {
            maxi *= 2;
            factor[i] = 0;
        }

        //cout << cases <<' ' << B << ' ' << M << endl;

        if (maxi < M) {
            out << "IMPOSSIBLE" << endl;
            continue;
        }

        MM = M;
        int i = 0;
        while(M != 0){
            factor[i] = M % 2;
            M = M/2;
            i++;
        }

        g.clear();
        vector<int> tmp(B);
        for(int i = 0; i < B; i++){
                g.push_back(tmp);
        }

        for(int i = 0; i < B-1; i++){
            for(int j = i+1; j < B-1; j++){
                g[i][j] = 1;
            }
        }
        for(int i = 0; i < B-1; i++){
            if (factor[i] == 1 && maxi != MM)
                g[i+1][B-1] = 1;
            if (maxi == MM)
                g[i][B-1] = 1;
        }
        out << "POSSIBLE" << endl;
        for(int i = 0; i < B; i++){
            for(int j = 0; j < B; j++){
                out << g[i][j];
            }
            out << endl;
        }
    }
    return 0;
}