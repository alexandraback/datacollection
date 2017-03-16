#include <iostream>
#include <set>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int tsk = 1; tsk <= T; tsk++) {
        long long n;
        cin >> n;
        if (n == 0) {
            cout << "Case #" << tsk << ": INSOMNIA" << endl;
        } else {
            set<int> st;
            long long x = 0;
            while (st.size() < 10) {
                x += n;
                long long xx = x;
                while (xx) {
                    st.insert(xx % 10);
                    xx /= 10;
                }
            }
            cout << "Case #" << tsk << ": " << x << endl;
        }
    }
}

