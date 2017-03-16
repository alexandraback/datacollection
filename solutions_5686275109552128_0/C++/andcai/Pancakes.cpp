#include <fstream>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int best;
multiset<int> p;
void DFS(int moves){
    multiset<int>::iterator it;
    it = p.end();
    it--;
    int val = *it;
    if(best>moves+val) best = moves + val;
    if(moves>=best) return;
    p.erase(it);
    for(int i = 2; i<=sqrt(val+0.1); i++){  //round-off safety
        int x;
        for(x = 0; x < val%i; x++){
            p.insert(val/i+1);
        }
        for(; x < i; x++){
            p.insert(val/i);
        }
        DFS(moves+i-1);
        for(x = 0; x < val%i; x++){
            it = p.find(val/i+1);
            p.erase(it);
        }
        for(; x < i; x++){
            it = p.find(val/i);
            p.erase(it);
        }
    }
    p.insert(val);
}

int main(){
    ifstream fin ("inputB.txt");
    ofstream fout ("outputB.txt");
    int T, D, pi;
    fin >> T;
    for(int x = 1; x <= T; x++){
        p.clear();
        multiset<int>::iterator it;
        fin >> D;
        for(int i = 0; i < D; i++){
            fin >> pi;
            p.insert(pi);
        }
        it = p.end();
        it--;
        best = *it;
        DFS(0);
        fout << "Case #" << x << ": " << best << '\n';
    }
}
