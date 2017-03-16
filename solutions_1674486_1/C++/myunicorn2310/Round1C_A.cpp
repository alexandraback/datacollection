#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 2000;
int n;
int Path[MAXN];
int inheritsFrom[MAXN][MAXN];
int nInherits[MAXN];

bool expand(int current) {
    for (int i = 0; i < nInherits[current]; i++) {
        int next = inheritsFrom[current][i];
        if (Path[next] != -1) {
            return true;
        } else {
            Path[next] = 1;
            if (expand(next)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int ntests;
    cin >> ntests;
    for (int test = 1; test <= ntests; test++) {      
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nInherits[i];
            for (int j = 0; j < nInherits[i]; j++) {
                cin >> inheritsFrom[i][j];
                inheritsFrom[i][j]--;
            }
        }
        bool hasDiamond = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Path[j] = -1;
            }
            Path[i] = 1;
            if (expand(i)) {
                hasDiamond = true;
                break;
            }
        }
        printf("Case #%d: ",test);
        if (hasDiamond) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
}