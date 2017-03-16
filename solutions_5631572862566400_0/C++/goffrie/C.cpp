#include <iostream>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void tc() {
    static int cas = 1;
    cout << "Case #" << cas++ << ": ";
    int N;
    cin >> N;
    vector<int> bff(N);
    for (int i = 0; i < N; ++i) cin >> bff[i], --bff[i];
    vector<int> csize(N);
    vector<int> dist(N);
    vector<int> best(N);
    vector<int> fst(N);
    for (int i = 0; i < N; ++i) {
        map<int, int> ix;
        int k = i, l = 0;
        while (1) {
            auto it = ix.insert(make_pair(k, l));
            if (!it.second) {
                dist[i] = it.first->second;
                csize[i] = l - it.first->second;
                fst[i] = k;
                for (int zz = 0; zz < csize[i]; ++zz) {
                    k = bff[k];
                    fst[i] = min(fst[i], k);
                }
                for (int zz = 0, q = i; zz <= dist[i]; ++zz, q = bff[q]) {
                    best[q] = max(best[q], dist[i]);
                }
                break;
            }
            k = bff[k];
            ++l;
        }
    }
    //for (int i = 0; i < N; ++i) {
    //            cerr << dist[i] << ',' << csize[i] << '\t' << fst[i] << ' ' << best[i] << endl;
    //}
    int A = 0, B = 0;
    map<int, multiset<int>> wew;
    for (int i = 0; i < N; ++i) {
        A = max(A, csize[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (csize[i] == 2 && dist[i] <= 0) {
            B += 1 + best[i];
        }
    }
    cout << max(A, B) << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
