// Copyright
// @author: Ruben S. Andrist
// @date: 2015-05-10
// @email: andrist@gmail.com

#include <cassert>
#include <cstdio>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  bool first = true;
  for (auto &x : v) {
    if (first) first=false;
    else out << ", ";
    cout << x;
  }
  return out << "]";
}

int main() {
  int T=0;
  assert(scanf("%d", &T)==1);
  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);

    int K, L, S;
    assert(scanf(" %d %d %d", &K, &L, &S)==3);

    // Read the keyboard and target strings.
    string keys = "";
    string target = "";
    char tmp[101];
    assert(scanf(" %s", tmp)); keys = tmp;
    assert(keys.size() == K);
    assert(scanf(" %s", tmp)); target = tmp;
    assert(target.size() == L);

    // Figure out the probability of each key
    vector<double> prob('Z'+1, 0);
    for (char a='A'; a<='Z'; a++) {
      for (int i=0; i<int(keys.size()); i++) {
        if (keys[i]==a) {
          prob[a]+=1;
        }
      }
      prob[a] /= K;
    }

    // Figure out how much the target can overlap
    vector<int> shifts;
    for (int s=1; s<=L; s++) {
      bool possible = true;
      for (int i=0; i+s < L; i++) {
        if (target[i] != target[i+s]) {
          possible = false;
          break;
        }
      }
      if (possible) {
        shifts.push_back(s);
      }
    }

    // how to go back if letter j does not match
    vector<map<char, int>> backs(L);
    for (int j=0; j<L; j++) { // from j
      for (int i=0; i<j; i++) { // to i
        // verify match
        bool possible = true;
        for (int k=1; k<=i; k++) {
          if (target[i-k] != target[j-k]) {
            possible = false;
            break;
          }
        }
        if (possible) {
          backs[j][target[i]] = i;
          // printf("can go back from %d to %d\n", j, i);
        }
      }
    }

    // early recognition of things that are impossible
    bool impossible = false;
    for (int j=0; j<L; j++) {
      if (prob[target[j]]==0.0) {
        impossible = true;
        break;
      }
    }
    if (impossible) {
      printf("%.7lf\n", 0.0);
      continue;
    }

    // What is the maximum number of occurrences?
    int best = (S-L+shifts[0])/shifts[0];
    if (best==0) {
      printf("%.7lf\n", 0.0);
      continue;
    }

    // How many do we actually expect?
    // cout << endl;
    int maxlen = 2*best*L+1;
    vector<vector<double>> p(S+1, vector<double>(maxlen));
    p[0][0] = 1.0;
    for (int i=0; i<S; i++) {
      for (int j=0; j<maxlen; j++) {
        // go forward from i,j
        if (p[i][j]==0.0) continue;
        for (char a='A'; a<='Z'; a++) {
          if (target[j%L]==a) {
            if (j+1==L) {
              p[i+1][j+1+L-shifts[0]] += p[i][j] * prob[a];
            } else {
              if (j+1 < maxlen) {
                p[i+1][j+1] += p[i][j] * prob[a];
              }
            }
          } else if (false && backs[j%L].find(a)!=backs[j%L].end()) {
            p[i+1][j-j%L+backs[j%L][a]+1] += p[i][j] * prob[a];
          } else {
            p[i+1][j-j%L] += p[i][j] * prob[a];
          }
        }
      }
    }

    // count expected.
    double expected = 0.0;
    for (int j=0; j<maxlen; j++) {
      expected += int(j/L) * p[S][j];
    }

    // Write expected number of bananas to keep
    printf("%.7lf\n", best - expected);
  }

  return 0;
}

// vim: set ff=unix ai tw=80 ts=2 sts=2 sw=2 et:
