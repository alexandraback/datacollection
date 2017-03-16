#include <iostream>
#include <vector>

using namespace std;

double min(double* a, int size) {
    double res = a[0];
    for (int i = 0; i < size; ++i) {
        if (a[i] < res) {
            res = a[i];
        }
    }
    return res;
}

void minIndexes(double* a, int size, vector<int>& indexes) {
    double m = min(a, size);
    indexes.clear();
    for (int i = 0; i < size; ++i) {
        if (a[i] - m < 0.000001 && a[i] - m > -0.000001) {
            indexes.push_back(i);
        }
    }
    return;
}

int main(int, char**) {
    int T;
    cin >> T;
    
    for (int i = 1; i < T + 1; ++i) {
        int N;
        cin >> N;
        
        int s[N];
        double w[N];
        int S = 0;
        for (int j = 0; j < N; ++j) {
            cin >> s[j];
            w[j] = (double)s[j];
            S += s[j];
        }

        int W = S;
        vector<int> inds;
        for (int W = S; W > 0; W--) {
            minIndexes(w, N, inds);
            double add = (double)1 / inds.size();
            for (vector<int>::iterator it = inds.begin(); it != inds.end(); ++ it) {
                w[*it] += add;
            }
        }

        cout << "Case #" << i << ": ";
        for (int j = 0; j < N; ++j) { 
            double res = (w[j] - s[j]) * 100.0 / S;
            cout << fixed << res << " ";
        }
        cout << endl;
    }

    return 0;
}
