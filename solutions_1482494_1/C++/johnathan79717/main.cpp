#include <iostream>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    int a[1005], b[1005];
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        set<pair<int, int> > A, B, C;
        for (int i = 0; i < N; ++i) {
            cin >> a[i] >> b[i];
            A.insert(make_pair(-b[i], i));
            B.insert(make_pair(b[i], i));
        }
        int gold = 0;
        int num = 0;
        bool toobad = false;
        while (!B.empty() || !C.empty()) {
            // cerr << A.size() << endl;
            if (!B.empty() && gold >= B.begin()->first) {
                gold += 2;
                int i = B.begin()->second;
                A.erase(make_pair(-b[i], i));
                B.erase(B.begin());
                ++num;
            } else if (!C.empty() && gold >= C.begin()->first) {
                ++gold;
                C.erase(C.begin());
                ++num;
            } else if (!A.empty()) {
                toobad = true;
                for (set<pair<int, int> >::iterator it = A.begin(); it != A.end(); ++it) {
                    int i = it->second;
                    if (a[i] <= gold) {
                        toobad = false;
                        ++gold;
                        A.erase(it);
                        B.erase(make_pair(b[i], i));
                        C.insert(make_pair(b[i], i));
                        ++num;
                        break;
                    }
                }
                if (toobad) {
                    break;
                }
            } else {
                toobad = true;
                break;
            }
        }
        // cerr << t << endl;
        cout << "Case #" << t << ": ";
        if (toobad) {
            cout << "Too Bad" << endl;
        } else {
            cout << num << endl;
        }
    }
}