#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>

using namespace std;

void printSolution(int R, int C, int r, int c, int lb, int rt){
    cout << '\n';
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            if(i == 0 && j == 0) cout << "c";
            else if((i < r && j < c) ||
               (i == r && j < lb) ||
               (j == c && i < rt)) cout << ".";
            else cout << "*";
        }
        cout << '\n';
    }
}

void printImpossible(){
    cout << '\n' << "Impossible" << '\n';
}

void solve(){
    int R, C, M;
    cin >> R >> C >> M;
    int N = R*C-M;
    if(N == 1){
        printSolution(R, C, 1, 1, 0, 0);
        return;
    }
    else if(N <= 0) printImpossible();
    for(int r=1; r<=R; ++r){
        if(r*C == N && (r > 1 || R == 1)){
            printSolution(R, C, r, N/r, 0, 0);
            return;
        }
        if(N/r < C && N/r > 1 && N-N/r*r > 1){
            printSolution(R, C, r, N/r, 0, N-N/r*r);
            return;
        }
        if(N/r < C && N/r > 1 && N-N/r*r == 0 && (r > 1 || R == 1)){
            printSolution(R, C, r, N/r, 0, N-N/r*r);
            return;
        }
        if(r > 2 && N/r < C && N/r > 2 && N-N/r*r == 1){
            printSolution(R, C, r-1, N/r, N/r-1, N-N/r*r+1);
            return;
        }
    }
    printImpossible();
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        cout << "Case #" << t+1 << ": ";
        solve();
    }
}
