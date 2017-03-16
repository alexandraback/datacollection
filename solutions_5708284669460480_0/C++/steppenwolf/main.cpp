#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define N 105
double P[N][N][N];

#define LIM 300
double letterP[LIM];

string calcLetterProb(string alphabet)
{
    string dist;
    memset(letterP, 0, sizeof(letterP));
    for (int i = 0; i < alphabet.size(); ++i) {
        if (!letterP[alphabet[i]]) {
            dist += alphabet[i];
        }
        letterP[alphabet[i]]++;
    }

    for (int i = 0; i < LIM; ++i) {
        letterP[i] /= alphabet.size();
    }

    return dist;
}

int prefixPos[N];
int calcPrefixPos(string word)
{
    memset(prefixPos, 0, sizeof(prefixPos));

    for (int i = 0; i < word.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (word.substr(0, j) == word.substr(i - j + 1, j)) {
                prefixPos[i] = j;
                break;
            }
        }
    }
}

bool canType(string target)
{
    for (int i = 0; i < target.size(); ++i) {
        if (!letterP[target[i]]) return false;
    }

    return true;
}

int main()
{
    int T;
    cin >> T;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);

    for (int testcase = 1; testcase <= T; ++testcase) {
        int K, L, S;
        cin >> K >> L >> S;

        string alphabet, target;
        cin >> alphabet >> target;

        calcPrefixPos(target);
        string dist = calcLetterProb(alphabet);

        memset(P, 0, sizeof(P));
        P[0][0][0] = 1;

        int maxNeeded = 0;
        if (canType(target)) {
            maxNeeded = 1 + (S - L) / (L - prefixPos[L - 1]);
        }

        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < L; ++j) {
                for (int k = 0; k <= maxNeeded; ++k) {
                    if (P[i][j][k]) {
                        for (int h = 0; h < dist.size(); ++h) {
                            int x = j + 1, w = k;
                            double prob = letterP[dist[h]];

                            if (dist[h] == target[j]) {
                                if (x == L) {
                                    x = prefixPos[L - 1];
                                    w++;
                                }
                                P[i + 1][x][w] += P[i][j][k] * prob;
                            }
                            else if (dist[h] == target[prefixPos[j]]) {
                                P[i + 1][prefixPos[j]][w] += P[i][j][k] * prob;
                            }
                            else {
                                P[i + 1][0][w] += P[i][j][k] * prob;
                            }
                        }

                        continue;

                        //Continue word
                        double continueP = letterP[target[j]];
                        int x = j + 1, w = k;

                        if (x == L) {
                            // Complete word
                            w++;
                            x = prefixPos[L - 1];
                        }

                        P[i + 1][x][w] += P[i][j][k] * continueP;

                        double prefP = 0;
                        int prefPos = prefixPos[j];
                        if (j && target[prefPos] != target[j]) {
                            //Go to prefix
                            prefP = letterP[target[prefPos]];
                            P[i + 1][prefPos + 1][k] += P[i][j][k] * prefP;
                        }

                        P[i + 1][0][k] += P[i][j][k] * (1 - continueP - prefP); //Probability of going to start
                    }
                }
            }
        }

        double res = 0;
        for (int i = 0; i < L; ++i) {
            for (int k = 0; k <= maxNeeded; ++k) {
                res += (maxNeeded - k) * P[S][i][k];
            }
        }

        cout << "Case #" << testcase << ": " << res << endl;
    }

    return 0;
}
