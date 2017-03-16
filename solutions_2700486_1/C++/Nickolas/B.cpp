#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

//----- C from n by k
#define MAXC 30
int C[MAXC][MAXC];

void calc_c() {
  //c from i by j
  memset(C, 0, sizeof(C));
  int i,j;
  for(i=0; i<MAXC; i++) {
    C[i][0]=C[i][i]=1;
    for(j=1; j<i; j++)
      C[i][j]=C[i-1][j-1]+C[i-1][j];
  }
}

double solve(int ind) {
    // input
    int N, X, Y;
    cin >> N >> X >> Y;
    // process
    // layer with distance 2*i from center are filled with 1 prob if there is enough diamonds (i*4 + 1 diamonds for layer)
    // figure out last filled layer
    int lastfilled = -1;
    int diamonds = N;   // layer 0 always gets filled with 1 diamond
    while (diamonds >= (lastfilled + 1) * 4 + 1) {
        ++lastfilled;
        diamonds -= lastfilled * 4 + 1;
    }
    // check whether X, Y is within filled layer - if yes, prob is 1
    if (abs(X) + Y <= 2 * lastfilled) {
        return 1.0;
    }
    // if X, Y is further than next layer, prob is 0
    if (abs(X) + Y > 2 * (lastfilled + 1) || abs(X) + Y == 2 * (lastfilled + 1) && diamonds == 0) {
        return 0.0;
    }
    // now, we're left with lastfilled full layers + diamonds to fill part of next layer
    // part goes left, part goes right, order doesn't matter
    int curlevel = lastfilled + 1;
    vector<vector<double> > altprob(diamonds + 1, vector<double>(diamonds + 1, 0));//[total][left]
    altprob[0][0] = 1;
    for (int i = 1; i <= diamonds; ++i) {
        // drop diamond i
        for (int j = 0; j <= i - 1; ++j) {
            // if we had j on the left, what it could have become? j or j + 1
            if (altprob[i - 1][j] < 1E-14) {
                continue;
            }
            if (max<int>(j, i - j) <= curlevel * 2 && max<int>(j + 1, i - j - 1) <= curlevel * 2) {
                // both branches are possible
                altprob[i][j] += altprob[i - 1][j] * 0.5;
                altprob[i][j + 1] += altprob[i - 1][j] * 0.5;
                continue;
            }
            if (max<int>(j, i - j) <= curlevel * 2) {
                // only j is possible
                altprob[i][j] += altprob[i - 1][j];
            } else {
                altprob[i][j + 1] += altprob[i - 1][j];
            }
        }
    }
    double res1 = 0;
    for (int left = 0; left <= diamonds; ++left) {
        double prob = altprob[diamonds][left];
        // if this config covers X, Y, add this prob to res
        int nd = (X < 0 ? left : diamonds - left);
        if (nd > Y) {
            res1 += prob;
        }
    }
    return res1;
}

int main() {
    int T;
    cin >> T;
    calc_c();
    for (int i = 1; i <= T; ++i) {
        // output
        printf("Case #%d: %.8f\n", i, solve(i));
    }
}