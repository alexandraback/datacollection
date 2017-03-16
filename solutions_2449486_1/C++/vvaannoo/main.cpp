#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>
using namespace std;
int k = 0;
bool checkLines(int **p, int I, int J, int n, int m){
    int l = 0, c = 0;
    for(int i = 0; i < n; i++){
        k++;
        if(p[i][J] > p[I][J]) l=1;
    }
    for(int j = 0; j < m; j++){
        k++;
        if(p[I][j] > p[I][J]) c=1;
    }
    l+=c;
    return l == 2;
}
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int n, m, **p;
        string ans = "YES";
        bool br = true;
        cin >> n >> m;
        p = new int*[n];
        for(int i = 0; i < n; i++){
            p[i] = new int[m];
            for(int j = 0; j < m; j++){
                cin >> p[i][j];
            }
        }
        for(int i = 0; i < n && br; i++){
            for(int j = 0; j < m && br; j++){
                if(checkLines(p, i, j, n, m)){
                    ans = "NO";
                    br = false;
                }
            }
        }
        delete [] p;
        
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
