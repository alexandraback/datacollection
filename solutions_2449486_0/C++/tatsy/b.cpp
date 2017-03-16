#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <complex>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T, N, M, V;
int F[101][101];
char B[101][101];

bool subsolve(int i, int j) {
    bool vert = true;
    rep(k,M) {
        if(F[i][k] > F[i][j]) { vert = false; break; }
    }

    bool horz = true;
    rep(k,N) {
        if(F[k][j] > F[i][j]) { horz = false; break; }
    }
    
    return vert || horz;
}

bool solve() {
    rep(i,N) {
        rep(j,M) {
            if(!subsolve(i, j)) return false;
        }
    }
    return true;
}

int main() {
    cin >> T;
    repa(t,1,T) {
        memset(F, 0, sizeof(int) * 101 * 101);
        cin >> N >> M;
        V = 0;
        rep(i,N) {
            rep(j,M) {
                cin >> F[i][j];
                V = max(V, F[i][j]);
            }
        }

        printf("Case #%d: ", t);
        cout << (solve() ? "YES" : "NO") << endl;
    }
}
