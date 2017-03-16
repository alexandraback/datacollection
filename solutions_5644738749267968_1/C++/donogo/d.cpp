#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int deceitful(set <double> N, set <double> K) {
  int score;
  if (N.size() == 0) {
    return 0;
  }

  if (*N.begin() < *K.begin()) { // Naomi has a hopeless stone 
    // cancel the hopeless stone with Ken's strongest stone
    N.erase(*N.begin());
    K.erase(*K.rbegin());
    score = 0 + deceitful(N, K);
  } else {
    // Naomi's weakest stone is stronger than the weakest stone
    // of Ken. She pretend as if she drop huge stone.
    // Ken will be convinced with a lose by his weakest stone.
    N.erase(*N.begin());
    K.erase(*K.begin());
    score = 1 + deceitful(N, K);
  }
  return score;
}

int war(set <double> N, set <double> K) {
  int score;
  if (N.size() == 0) {
    return 0;
  }

  if (*N.rbegin() > *K.rbegin()) { // Naomi has the strongest
    // stone, cancel it with Ken's weakest
    N.erase(*N.rbegin());
    K.erase(*K.begin());
    score = 1 + war(N, K);
  } else {
    // Naomi's strongest stone is weaker than the strongest stone
    // of Ken.
    // Naomi drops her weakest.
    // Ken capture it with cheapest winning stone
    double naostone;
    set <double>::iterator it;
    
    naostone = *N.begin();
    N.erase(naostone);
    it = K.lower_bound(naostone);
    K.erase(*it);

    score = war(N, K);
  }
  return score;
}


int main(void) {
  int T, t;
  int i, n;
  double w;
  int pdeceitful, pwar;
  cin >> T;

  for (t = 1; t <= T; t++) {
    int n;
    cin >> n;
    set <double> Nao, Ken;

    for (i = 0; i < n; i++) {
      cin >> w;
      Nao.insert(w);
    }
    for (i = 0; i < n; i++) {
      cin >> w;
      Ken.insert(w);
    }
    pdeceitful = deceitful(Nao, Ken);
    pwar = war(Nao, Ken);

    cout << "Case #" << t << ": " << pdeceitful << " " << pwar << endl;
  }


  return 0;
}

