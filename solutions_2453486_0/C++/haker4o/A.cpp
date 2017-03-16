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

bool checkWon(vector<string> &v, char c) {
    int i, j;
    for(i=0; i<4; ++i) {
        for(j=0; j<4; ++j) {
            if (v[i][j] == c || v[i][j] == 'T') continue;
            break;
        }
        if (j == 4) return true;
    }
    for(i=0; i<4; ++i) {
        for(j=0; j<4; ++j) {
            if (v[j][i] == c || v[j][i] == 'T') continue;
            break;
        }
        if (j == 4) return true;
    }
    for(i=0; i<4; ++i) {
        if (v[i][i] == c || v[i][i] == 'T') continue;
        break;
    }
    if (i == 4) return true;
    for(i=0; i<4; ++i) {
        if (v[i][3-i] == c || v[i][3-i] == 'T') continue;
        break;
    }
    if (i == 4) return true;
    return false;
}

bool checkDraw(vector<string> &v) {
    for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) {
        if (v[i][j] == '.') return false;
    }
    return true;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i, j;
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        vector<string> v(4);
        cout<<"Case #"<<T<<": ";
        for(i=0; i<4; ++i) {
            cin>>v[i];
        }
        if (checkWon(v, 'X')) {
            cout<<"X won";
        } else if (checkWon(v, 'O')) {
            cout<<"O won";
        } else if (checkDraw(v)) {
            cout<<"Draw";
        } else {
            cout<<"Game has not completed";
        }
        cout<<endl;
    }
    return 0;
}
