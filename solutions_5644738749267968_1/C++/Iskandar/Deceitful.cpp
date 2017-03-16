#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int T, N;
    vector<double> naomi;
    vector<double> ken;
    double curr;

    cin >> T;

    for (int i = 1; i <= T; i++) {
        int deceit = 0, normal = 0;
        naomi.clear();
        ken.clear();

        cin >> N;

        for (int j = 0; j < N;j ++) {
            cin >> curr;
            naomi.push_back(curr);
        }

        for (int j = 0; j < N; j++) {
            cin >> curr;
            ken.push_back(curr);
        }

        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());

        /** Normal */
        int pointer = N-1;

        for (int j = N-1; j >= 0; j--) {
            if (naomi[j] > ken[pointer]) {
                normal++;
            } else {
                pointer--;
            }
        }

        /** Deceitful */
        int left_pointer = 0;
        for (int j = 0; j < N; j++) {
            if (naomi[j] < ken[left_pointer]) {} else {
                left_pointer++;
                deceit++;
            }
        }

        cout << "Case #" << i << ": ";

        cout << deceit << " " << normal << endl;
    }

    return 0;
}
/** Created by freedomofkeima */
