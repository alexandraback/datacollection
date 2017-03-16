#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <list>

using namespace std;

int countfriend(vector <int> popu) {
  int s;
  int Smax;
  vector <int> Q;
  int gap, maxgap;

  Smax = popu.size() - 1;
  
  Q.push_back(0);

  for (s = 1; s <= Smax; s++) {
    Q.push_back(popu[s - 1] + Q[s - 1]);
  }
  // Q[0] = 0, Q[1] = P[0], Q[2] = Q[1] + P[1] = P[0] + P[1] ...

  maxgap = -1;

  for (s = 1; s <= Smax; s++) {
    gap = s - Q[s];
    if (gap > maxgap) {
      maxgap = gap;
    }
  }
  if (maxgap <= 0) {
    return 0;
  }
  return maxgap;
  

}



int main(void) {
  int T, t;
  int Smax;
  int s;
  vector < vector <int> > res;
  cin >> T;

  for (t = 1; t <= T; t++) {
    string popstr;
    vector <int> popu;
    int numfriend;
    cin >> Smax;
    cin >> popstr;

    //    cout << Smax << endl;
    //    cout << "*" << popstr << "*" << endl;
    for (s = 0; s <= Smax; s++) {
      popu.push_back(popstr[s] - '0');
    }
    numfriend = countfriend(popu);
    
    cout << "Case #" << t << ": " << numfriend << endl;

  }
  return 0;
}
