#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        vector<int> denom;
        int C, D, V;

        cin >> C >> D >> V;
        for (int i = 0; i < D; i++) {
            int d;
            cin >> d;
            denom.push_back(d);
        }
        sort(denom.begin(), denom.end());

        int to_add = 0;
        int current_index = 0;
        int current_sum = 0;

        while(current_sum < V) {
            if(current_index < denom.size() && current_sum >= denom[current_index] - 1) {
                current_sum += (denom[current_index] * C);
                current_index++;
                continue;
            }

            to_add++;
            current_sum += (current_sum + 1) * C;
        }


        cout << "Case #" << t << ": " << to_add << endl;
    }

    return 0;
}
