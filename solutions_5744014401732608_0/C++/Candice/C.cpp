//
// Created by Yuxiang LI on 09/04/16.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T;
long long B,M;
vector<long long> ways(10);
vector<vector<int> > g(10);

bool dfs(int i, int j){
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
}

int main(){
    ifstream in("B-small-1.in");
    ofstream out("output.out");
    in >> T;
    for(int cases = 1; cases <= T; cases++){
        in >> B >> M;
        out << "Case #" << cases << ": ";
        ways.clear();
        g.clear();
        for(int i = 0; i < B; i++){
            ways.push_back(0);
        }
        ways[0] = 1;
        vector<int> tmp(B);
        for(int i = 0; i < B; i++)
            tmp[i] = 0;
        for(int i = 0; i < B; i++){
            g.push_back(tmp);
        }
        if (dfs(0,1)){
            out << "POSSIBLE" << endl;
            for(int i = 0; i < B; i++){
                for(int j = 0; j < B; j++){
                    out << g[i][j];
                }
                out << endl;
            }
        }else{
            out << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}