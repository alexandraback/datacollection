#include <cstdio>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int
main(int argc, char **argv)
{
        cout.precision(10);

        int T;

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                string line;
                getline(cin, line);
                stringstream ss(line);

                int N;
                vector<int> scores;

                ss >> N;
                int X = 0;
                for (int j = 0; j < N; j++) {
                        int score;
                        ss >> score;
                        scores.push_back(score);
                        X += score;
                }

                cout << "Case #" << i+1 << ":";

                for (int j = 0; j < N; j++) {
                        int s = scores[j];
                        vector<int> rest = scores;
                        rest.erase(rest.begin()+j);
                        sort(rest.begin(), rest.end());
                        int subtotal = 0;
                        double min = 1.0;
                        for (int k = 1; k <= N-1; k++) {
                                subtotal += rest[k-1];
                                double p = (subtotal+X-k*s)/(k+1.0)/X;
                                int final = s+p*X;
                                if (final < rest[k-1])
                                        continue;
                                if (p < 0.0 || p > 1.0)
                                        continue;
                                min = min < p ? min : p;
                        }
                        printf(" %f", min*100.0);
                }

                cout << endl;

        }

        return 0;
}
