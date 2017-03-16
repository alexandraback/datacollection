#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

inline int Round(const double value) {
    return int(value + 0.5);
}

inline int GetScore(const vector<int> &A, const vector<int> &B) {
    int score = 0;
    vector<bool> used = vector<bool>(int(B.size()), false);
    for (int i = 0; i < int(A.size()); ++i) {
        int j = -1;
        for (int k = 0; k < int(B.size()) && j == -1; ++k)
            if (!used[k] && B[k] > A[i])
                j = k;
        if (j == -1) {
            ++score;
            for (int k = 0; k < int(B.size()) && j == -1; ++k)
                if (!used[k])
                    j = k;
        }
        used[j] = true;
    }
    return score;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int testCount;
    in >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        vector<int> A, B;
        int N;
        in >> N;
        A = B = vector<int>(N);
        for (int i = 0; i < N; ++i) {
            double value;
            in >> value;
            A[i] = Round(1000000.0 * value);
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i) {
            double value;
            in >> value;
            B[i] = Round(1000000.0 * value);
        }
        sort(B.begin(), B.end());
        int deceitfulWar = 0, war = 0;
        //deceitWar
        for (int i = 0; i <= N; ++i) {
            int current = 0;
            for (int j = 0; i + j < N; ++j)
                if (B[j] < A[i + j])
                    ++current;
            deceitfulWar = max(deceitfulWar, current);
        }
        //war
        reverse(A.begin(), A.end());
        war = GetScore(A, B);
        do {
            war = max(war, GetScore(A, B));
        } while (next_permutation(A.begin(), A.end()));
        out << "Case #" << t << ": " << deceitfulWar << " " << war << "\n";
    }
    in.close();
    out.close();
    return 0;
}
