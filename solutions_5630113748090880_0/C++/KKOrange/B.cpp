#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
vector<int> v;
int c[2505];
int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        v.clear();
        for(int i = 1; i <= 2500; i++) {
            c[i] = 0;
        }
        for(int i = 0; i < N*2-1; i++) {
            for(int j = 0; j < N; j++) {
                int x;
                cin >> x;
                c[x]++;
            }
        }
        for(int j = 1; j <= 2500; j++) {
            if(c[j]%2 == 1) {
                v.push_back(j);
            }
        }   
        sort(v.begin(), v.end());
        cout << "Case #" << t << ":";
        assert(v.size() == N);
        for(int i = 0; i < N; i++) {
            cout << " " << v[i];
        }
        cout << "\n";
    }
    return 0;
}
