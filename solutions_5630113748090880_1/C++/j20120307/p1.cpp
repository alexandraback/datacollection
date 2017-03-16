#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i <<":";
        int N;
        cin >> N;
        vector<int> line;
        unordered_map<int, int> matrix;
        for (int j = 0; j < 2 * N - 1; j++) {
            for (int k = 0; k < N; k++) {
                int e;
                cin >> e;
                matrix[e]++;
            }
        }
        for (auto element = matrix.begin(); element != matrix.end(); element++)
            if (element->second % 2)
                line.push_back(element->first);
        sort(line.begin(), line.end());
        for_each(line.begin(), line.end(),[](int i){cout << " " << i;});
        cout << endl;
    }
    return 0;
}