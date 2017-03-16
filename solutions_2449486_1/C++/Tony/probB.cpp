
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAXN 100

using namespace std;

string solve(vector <vector <int> > a) {
    int N = a.size();
    int M = a[0].size();
    if (N == 1 || M == 1)
        return "YES";
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    */

    int minVal = 100;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            minVal = min(minVal, a[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (a[i][j] == minVal) {
                int k;

                for (k = 0; k < M; k++)
                    if (a[i][k] != minVal)
                        break;
                if (k == M) {
                    vector <vector <int> > b;
                    for (k = 0; k < N; k++)
                        if (k != i)
                            b.push_back(a[k]);
                    return solve(b);
                }

                for (k = 0; k < N; k++)
                    if (a[k][j] != minVal)
                        break;
                if (k == N) {
                    vector <vector <int> > b(N);
                    for (k = 0; k < M; k++)
                        if (k != j)
                            for (int l = 0; l < N; l++)
                                b[l].push_back(a[l][k]);
                    return solve(b);
                }

                return "NO";
            }
    return "";
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        vector <vector <int> > a(N, vector <int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> a[i][j];
        cout << "Case #" << t << ": " << solve(a) << endl;
    }
}

