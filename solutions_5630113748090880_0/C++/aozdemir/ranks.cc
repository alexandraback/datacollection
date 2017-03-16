#include <iostream>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        map<int,int> m;
        cin >> N;
        for (int l = 0; l < 2*N - 1; ++l){
            for (int i = 0; i < N; ++i) {
                int j;
                cin >> j;
                ++m[j];
            }
        }
        cout << "Case #" << t << ":";
        for (auto it : m)
            if (it.second % 2 == 1) cout << ' ' << it.first;
        cout << endl;
    }
}
