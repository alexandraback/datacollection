#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <list>
#include <functional>
#include <utility>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h);i>(l);--i)
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
//    ifstream cin("D:\\in.txt");
//    ofstream cout("D:\\out.txt");
//    freopen("D:\\in.txt", "r", stdin);
//    freopen("D:\\out.txt", "w", stdout);
    int T;
    cin >> T;
    REP(i,T) {
        int N;
        cin >> N;
        vector<VI> V(N);
        VI C(N);
        VI M(N);
        REP(j,N) {
            cin >> M[j];
            V[j].resize(M[j]);
            REP(k,M[j]) {
                int p;
                cin >> p;
                V[j][k] = --p;
                ++C[p];
            }
        }
        bool ans = false;
        REP(j,N) {
            if (C[j]) {
                continue;
            }
            set<int> S;
            queue<int> Q;
            S.insert(j);
            Q.push(j);
            while (!Q.empty()) {
                int f = Q.front();
                Q.pop();
                REP(k,M[f]) {
                    int p = V[f][k];
                    if (S.find(p) != S.end()) {
                        ans = true;
                        break;
                    }
                    S.insert(p);
                    Q.push(p);
                }
                if (ans) {
                    break;
                }
            }
            if (ans) {
                break;
            }
        }
        if (ans) {
            cout << "Case #" << i + 1 << ": Yes" << endl;
        } else {
            cout << "Case #" << i + 1 << ": No" << endl;
        }
    }
    return 0;
}
