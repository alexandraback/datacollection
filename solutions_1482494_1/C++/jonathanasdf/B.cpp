#include <iostream>
#include <algorithm>

using namespace std;

int a[2001], b[2001], c[2001], idx[2001];
bool asdf(const int& aa, const int& bb) {
    return b[aa] > b[bb];
}
int main() {
    int T; cin >> T;
    for (int zz = 1; zz <= T; zz++) {
        int N; cin >> N;
        for (int i=0; i <N; i++) cin >> a[i] >> b[i], c[i] = 0, idx[i] = i;
        sort(idx, idx+N, asdf);
        
        int count = 0, moves = 0;
        while (count != 2*N) {
            bool moved = false;
            bool can2 = true;
            while(can2) {
                can2 = false;
                for (int i=0; i < N; i++) {
                    if (b[i] <= count && c[i] < 2) {
                        count += 2-c[i];
                        c[i] = 2;
                        moves++;
                        can2 = true;
                        moved = true;
                    }
                }
            }
            for (int i=0; i < N; i++) {
                if (a[idx[i]] <= count && c[idx[i]] < 1) {
                    count += 1-c[idx[i]];
                    c[idx[i]] = 1;
                    moves++;
                    moved = true;
                    break;
                }
            }
            if (!moved) break;
        }
        cout << "Case #" << zz << ": ";
        if (count != 2*N) cout << "Too Bad" << endl;
        else cout << moves << endl;
    }
    return 0;
}