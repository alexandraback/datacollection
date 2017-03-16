#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "B.in"
#define FILEOUT "B.out"



int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){

        int  B;
        ll M;
        cin >> B >> M;

        ll powp = 1;
        for (int i = 0; i < B - 2; ++i) {
            powp *= 2ll;
        }


        cout << "Case #" << _ << ": ";
        //Output answer
        if (powp <  M) {
            cout << "IMPOSSIBLE";
        } else {

            vector<int> powers;
            while (M >= 1) {
                powers.push_back(M % 2ll);
                M /= 2ll;
            }

            int matrix[B][B];
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    matrix[i][j] = 0;
                }
            }

            for (int i = (int)powers.size() - 1 ; i >= 0; --i) {
                if (powers[i] == 1) {
                    int cnt = i + 2;
                    int low = B - cnt;
                    for (int j = low; j < B; ++j) {
                        for (int k = j + 1; k < B; ++k) {
                            matrix[j][k] = 1;
                        }
                    }
                    if (low > 0) {
                        matrix[0][low] = 1;
                    }
                }
            }

            cout << "POSSIBLE";
            for (int i = 0; i < B; ++i) {
                cout << "\n";
                for (int j = 0; j < B; ++j) {
                    cout << matrix[i][j];
                }
            }
        }


        cout << endl;
    }
    return 0;
}