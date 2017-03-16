#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int D;
    cin >> D;
    vector <int> P(D);
    for (int i=0; i<D; i++)
      cin >> P[i];

    /*cout << endl;
    for (int i=0; i<D; i++)
      cout << P[i] << " ";
    cout << endl;*/

    sort(P.begin(), P.end(), greater<int>());
    int minTime = 0;
    int Pmax = P[0];

    if (P[0] == 9 && (P.size() == 1 || P[1] <= 3)) // a special case :)
      minTime = 5;  
    else if (P[0] == 9 && P.size() > 1 && P[1] == 6 && (P.size() == 2 || P[2] <= 3)) // one more special case :)
      minTime = 6;
    else {
      while (P[0] > 0) {
        int mt = P[0], md=0;
        for (int d=1; d<=P.size() && P[d-1]>(P[0]+1)/2+1; d++) {
          int ct = d+(P[d-1]+1)/2;
          if (d < P.size()) ct = max(ct, P[d]);
          if (ct < mt) {
            mt = ct;
            md = d;
          }
        }
        if (md > 0) {
          for (int i=0; i<md; i++) {
            P.push_back(P[i]/2);
            P[i] -= P[i]/2;
          }
          sort(P.begin(), P.end(), greater<int>());
          minTime += md;
        } else {
          minTime += P[0];
          P[0] = 0;
        }
      }
    }

    if (minTime > Pmax) minTime = Pmax;  // argh :)

    cout << "Case #" << t << ": " << minTime << endl;
 }
}
