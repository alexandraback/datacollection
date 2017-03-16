#include <iostream>

using namespace std;

int main() {
    int N, T;
    int heights[2500];
    int maxHeight, height;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> N;
        maxHeight = 0;

        for (int j = 0; j < 2500; ++j) {
            heights[j] = 0;
        }

        for (int j = 0; j < 2 * N - 1; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> height;
                heights[height - 1]++;
                if (height > maxHeight) {
                    maxHeight = height;
                }
            }
        }
        cout << "Case #" << i+1 << ":";
        for (int j = 0; j < maxHeight; ++j) {
            if (heights[j] % 2) {
                cout << ' ' << j+1;
            }
        }
        cout << endl;
    }
}
