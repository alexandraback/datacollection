#include <iostream>
using namespace std;

int N, M;
int pattern[100][100];
int tallestinrow[100];
int tallestincolumn[100];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        for (int j = 0; j < M; j++) {
            tallestincolumn[j] = 1;
        }
        for (int i = 0; i < N; i++) {
            tallestinrow[i] = 1;
            for (int j = 0; j < M; j++) {
                cin >> pattern[i][j];
                if (pattern[i][j] > tallestinrow[i]) tallestinrow[i] = pattern[i][j];
                if (pattern[i][j] > tallestincolumn[j]) tallestincolumn[j] = pattern[i][j];
            }
        }
        bool good = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (pattern[i][j] < tallestinrow[i] && pattern[i][j] < tallestincolumn[j]) good = false;
            }
        }
        cout << "Case #" << t << ": ";
        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
