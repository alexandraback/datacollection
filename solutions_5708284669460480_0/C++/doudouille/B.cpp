#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef stringstream SS;


#define pb(x) push_back(x)
#define ins(x) insert(x)
#define sz size()
#define len length()

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a),_d=((a)<(b))?1:-1; _d*i<=_d*(b); i+=_d)
#define FOREACH(it,s) for (typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
#define SORT(x) (sort((x).begin(),(x).end()))
#define UNIQ(x) ((x).erase(unique((x).begin(),(x).end()),(x).end()))

#define INF 2147450751

bool possible(int S, string word, string keyboard) {
  if(S < word.size()) return false;
  for(int i = 0; i < word.size(); i++) {
    int j = 0;
    for(; j < keyboard.size(); j++)
      if(word[i] == keyboard[j]) break;
    if(j == keyboard.size()) return false;
  }
  return true;
}

int compute_overlap(string word) {
  for(int k = 1; k < word.size(); k++) {
    int l = 0;
    for(; l+k < word.size(); l++) if(word[l] != word[l+k]) break;
    if(l+k == word.size()) return k;
  }
  return word.size();
}






double P[256];
double NB[256];
double newP[256];
double newNB[256];

/*

void compute(int S) {
  memset(P, 0, sizeof(P));
  memset(NB, 0, sizeof(NB));
  P[0] = 1.;

  for(int k = 0; k < S; k++) {
    memset(newP, 0, sizeof(newP));
    memset(newNB, 0, sizeof(newNB));

    for(int i = 0; i < key.size(); i++) 
      for(int p = 0; p < word.size(); p++) {

        char c = key[i];
        int nb_good = TRANS[p][c];
        double proba = proba_key[i];
        double nb = NB[p][i];
        if(p == word.size()-1 && c == word.back()) nb += 1.;
        newNB[nb_good] += nb * proba;
        newP[nb_good] += proba;




    }

    memcpy(P, newP, sizeof(P));
    memcpy(NB, newNB, sizeof(NB));
  }


}

*/


vector<double> proba_key;
vector<char> key;


void compute_P(string keyboard) {
  proba_key.clear();
  key.clear();
  map<char, int> NB;
  for(int i = 0; i < keyboard.size(); i++) NB[keyboard[i]]++;
  for(int i = 0; i < 256; i++) if(NB[i] > 0)  {
    proba_key.push_back(NB[i] / double(keyboard.size()));
    key.push_back(i);
  }
}

int overlap;
int nb_match(string &S, string &word) {
  int nb = 0;
  for(int i = 0; i + word.size() <= S.size(); i++) {
    int j = 0;
    for(; j < word.size(); j++) if(word[j] != S[i+j]) break;
    if(j == word.size()) nb++;
  }
  return nb;
}


double nb_expected(int d, string &S, string &word, double proba) {
  double nb = 0.;
  for(int i = 0; i < key.size(); i++) {
    S[d] = key[i];
    if(d > 0) nb += nb_expected(d-1, S, word, proba*proba_key[i]);
    else {
    //  cerr << S << " " << proba << endl;
      nb += nb_match(S, word) * proba*proba_key[i];
    }
  }
  return nb;
}



int main() {
  cout.precision(16);
  int T, K, L, S;
  cin >> T;
  cout.precision(20);
  for(int i = 1; i <= T; i++) {
    cin >> K >> L >> S;
    string word, keyboard;
    cin >> keyboard >> word;
    compute_P(keyboard);    
    overlap = compute_overlap(word);
    if(possible(S, word, keyboard)) {

      double max = 1 + (S - word.size()) / overlap;
  //    cerr << max << " " << S << " " << overlap << endl;
      string str;
      str.resize(S);
      double expected = nb_expected(S-1, str, word, 1.);
 //     cerr << max << " " << expected << endl;
      cout << "Case #" << i << ": " << (max - expected) << endl;

    }
    else 
      cout << "Case #" << i << ": " << 0 << endl;


  }
}
