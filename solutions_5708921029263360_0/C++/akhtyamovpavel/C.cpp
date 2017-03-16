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
#define FILEIN "C.in"
#define FILEOUT "C.out"


struct triple {
    int a, b, c;
};

void check(const vector<triple> & t, int J, int P, int S, int K) {
    int A[J][P];
    int B[J][S];
    int C[P][S];
    bool AAA[J][P][S];
    for (int i = 0; i < J; ++i) {
        for (int j = 0; j < P; ++j) {
            for (int k = 0; k < P; ++k) {
                AAA[i][j][k] = false;
                A[i][j] = 0;
                B[i][k] = 0;
                C[j][k] = 0;
            }
        }
    }
    cout << endl;
    cout << t.size() << endl;
    cout << K << endl;
    for (auto tr: t) {
        cout << tr.a << " " << tr.b << " " << tr.c << endl;
        A[tr.a][tr.b]++;
        B[tr.a][tr.c]++;
        C[tr.b][tr.c]++;
        cout << A[tr.a][tr.b]++ << " " << B[tr.a][tr.c] << " " << C[tr.b][tr.c] << endl;
        if (A[tr.a][tr.b] > K) {
            cout << "FJKJFDKA\n";
        }
        if (B[tr.a][tr.c] > K) {
            cout << "FJKJFDKB\n";
        }
        if (C[tr.b][tr.c] > K) {
            cout << "FJKJFDKC\n";
        }
        if (AAA[tr.a][tr.b][tr.c]) {
            cout << "jfdkjlsjklsfd\n";
        } else {
            AAA[tr.a][tr.b][tr.c] = true;
        }
    }
}


int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){


        int J, P, S;
        cin >> J >> P >> S;

        int K;
        cin >> K;
        int mapping[P][P];
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                mapping[i][j] = (i + j) % P;
            }
        }

        cout << "Case #" << _ << ": ";
        vector<triple> result;
        if (J == 0) {
            if (P == 1) {
                int answer = min(S, K);
                cout << answer;
                for (int i = 0; i < answer; ++i) {
                    triple tr;
                    tr.a = 0;
                    tr.b = 0;
                    tr.c = i;
                    result.push_back(tr);
                    cout << "\n" << 1 << " " << 1 << " " << i + 1;
                }
            } else {
                int answer = P * min(S, K);
                cout << answer;
                for (int i = 0; i < P; ++i) {
                    for (int j = 0; j < min(S, K); ++j) {
                        triple tr;
                        tr.a = 0;
                        tr.b = i;
                        tr.c = j;
                        result.push_back(tr);
                        cout << "\n" << 1 << " " << i + 1 << " " << j + 1;
                    }
                }
            }
        } else {
            int oneTryCount = J * P;
            int newK = min(S, K);
            cout << J * P * newK;
            for (int k = 0; k < newK; ++k) {
                for (int i = 0; i < J; ++i) {
                    for (int j = 0; j < P; ++j) {
                        triple tr;
                        tr.a = i;
                        tr.b = j;
                        tr.c = mapping[i][j];
                        result.push_back(tr);
                        cout << "\n" << i + 1 << " " << j + 1 << " " << mapping[i][j] + 1;
                        mapping[i][j] = (mapping[i][j] + 1) % S;
                    }
                }
            }
        }
        // check(result, J, P, S, K);

        
        //Output answer
        

        cout << endl;
    }
    return 0;
}