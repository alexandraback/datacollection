#include <iostream>
#include <vector>

using namespace std;

const int MAX_HEIGHT = 2505;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ":";
        vector<int> heights(MAX_HEIGHT + 1, 0);
        int N;
        cin >> N;
        for (int i = 0; i < (2 * N - 1) * N; ++i) {
            int h;
            cin >> h;
            ++heights[h];
        }
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] % 2 == 1) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
    return 0;
}