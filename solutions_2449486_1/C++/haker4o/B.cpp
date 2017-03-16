#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[128][128];
int n, m;

bool checkRow(int r, int num) {
    for(int i=0; i<m; ++i) {
        if (a[r][i] > num) return false;
    }
    return true;
}

bool checkCol(int c, int num) {
    for(int i=0; i<n; ++i) {
        if (a[i][c] > num) return false;
    }
    return true;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int i, j, k;
    int T, NT;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cout<<"Case #"<<T<<": ";
        cin>>n>>m;
        for(i=0; i<n; ++i) for(j=0; j<m; ++j) {
            cin>>a[i][j];
        }
        for(k=1; k<=100; ++k) {
            vector<bool> rows, cols;
            for(i=0; i<n; ++i) {
                rows.push_back(checkRow(i, k));
            }
            for(i=0; i<m; ++i) {
                cols.push_back(checkCol(i, k));
            }
            for(i=0; i<n; ++i) {
                for(j=0; j<m; ++j) {
                    if (a[i][j] == k && !rows[i] && !cols[j]) break;
                }
                if (j < m) break;
            }
            if (i < n) break;
        }
        if (k < 101) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
