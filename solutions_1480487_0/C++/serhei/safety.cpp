/* Google Code Jam Round 1B - Safety in Numbers */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
        int T; cin >> T;
        for (int cT = 1; cT <= T; cT++) {
                int N; cin >> N;

                vector<int> scores(N); int X = 0;
                for (int i = 0; i < N; i++) { cin >> scores[i]; X += scores[i]; }

                /* find equilibrium Q s.t. there is some assignment of y_i where
                   for all i : */
                double Q = (2.0 * X) / N;

                /* fix erroneous case when some J_i >= Q */
                double newN = N; double newX = X;
                for (int i = 0; i < N; i++) {
                        if (scores[i] >= Q) {
                                newX -= scores[i]; newN--;
                        }
                }
                double newQ = (X + newX) / newN;
                
                for (int i = 0; i < N; i++) {
                        if (scores[i] >= newQ && scores[i] < Q) cerr << "MULTIPLE ALERT!!!" << endl;
                }

                /* find best for each contestant, namely:
                   find y_i such that exists j : J_i + X * y_i >= J_j + X * y_j
                   no matter how we assign the y_j

                   this is equivalent to solving J_i + X * y_i = Q for y_i */
                vector<double> best(N, 0);
                for (int i = 0; i < N; i++) {
                        if (scores[i] >= Q) best[i] = 0.0;
                        else best[i] = (newQ - scores[i]) / X;
                        // if (best[i] < 0) best[i] = 0.0;
                }

                cout << "Case #" << cT << ": ";
                for (int i = 0; i < N; i++) {
                        printf("%.6f", best[i] * 100.0);
                        if (i != N-1) cout << " ";
                }
                cout << endl;
        }
}
