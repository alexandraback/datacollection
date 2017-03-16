#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream cin("A-small-attempt2.in");
    ofstream cout("out.txt");
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int A, N;
        cin >> A >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int res = N;
        sort(v.begin(), v.end());
        for (int j = 1; j <= N; j++) {
            if (A <= 1)
                break;
            int curA = A;
            int del = N - j;
            int cur = 0;
            for (int i = 0; i < j; i++) {
                while (curA <= v[i]) {
                    cur++;
                    curA += curA-1;
                }
                curA += v[i];
            }
            res = min(res, cur + del);
        }
        cout << "Case #" << t << ": ";
        cout << res;
        cout << endl;
    }
}

