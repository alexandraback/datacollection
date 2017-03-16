#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "Case #" << (i + 1) << ": INSOMNIA" << endl;
            continue;
        }

        unordered_set<int> st;
        int j = 1;
        while (st.size() < 10) {
            int temp = n * j;
            while (temp) {
                st.insert(temp % 10);
                temp /= 10;
            }
            j++;
        }
        cout << "Case #" << (i + 1) << ": " << (j - 1) * n << endl;
    }    
    return 0;
}
