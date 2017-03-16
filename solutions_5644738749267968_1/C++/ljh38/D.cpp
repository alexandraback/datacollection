#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int deceitful(vector<double> naomi, vector<double> ken) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());

    int points = 0;
    int N = naomi.size();
    for (int n = 0; n != N; ++n) {
        // find her lowest-valued thing that can beat his lowest one
        int choice = -1;
        for (int m = 0; m != naomi.size(); ++m) {
            if (naomi[m] > ken.front()) {
                choice = m;
                break;
            }
        }
        if (choice != -1) {
            naomi.erase(naomi.begin() + choice);
            ken.erase(ken.begin());
            ++points;
        } else {
            // can't win a point, throw away lowest thing
            naomi.erase(naomi.begin());
            ken.erase(ken.begin());
        }
    }
    return points;
}

int standard(vector<double> naomi, vector<double> ken) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    
    int N = naomi.size();
    int points = 0;
    for (int n = 0; n != N; ++n) {

        vector<int> response(naomi.size(), -1);
        vector<int> count(ken.size(), 0);
        for (int i = 0; i != naomi.size(); ++i) {
            for (int k = 0; k != ken.size(); ++k) {
                if (ken[k] > naomi[i]) {
                    response[i] = k;
                    count[k]++;
                    break;
                }
            }
        }

        int K = -1;
        for (int k = 0; k != ken.size(); ++k) {
            if (K == -1 || count[k] > count[K]) {
                K = k;
            }
        }

        int N = naomi.size() - 1;
        if (count[K] > 1) {
            for (int i = 0; i != naomi.size(); ++i) {
                if (response[i] == K) {
                    N = i;
                    break;
                }
            }
        }

        bool score = true;
        for (int k = 0; k != ken.size(); ++k) {
            if (ken[k] > naomi[N]) {
                ken.erase(ken.begin() + k);
                score = false;
                break;
            }
        }
        if (score) {
            ++points;
            ken.erase(ken.begin());
        }
        naomi.erase(naomi.begin() + N);
    }
    return points;
}

int main() {
    // ifstream in("sample.in");
    istream& in = cin;

    int C;
    in >> C;
    for (int c = 0; c != C; ++c) {
        int N;
        in >> N;
        vector<double> naomi(N);
        for (int n = 0; n != N; ++n) {
            in >> naomi[n];
        }
        vector<double> ken(N);
        for (int n = 0; n != N; ++n) {
            in >> ken[n];
        }
        cout << "Case #" << (c+1) << ": " << deceitful(naomi, ken) << " " << standard(naomi, ken) << endl;
    }

    return 0;
}
