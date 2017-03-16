
#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector< vector<int> > N;
vector< vector<int> > C;
vector<int> T;


bool loop(int chest, int key, vector<int> &V) {
  V[chest] = 1;
  for(int i = 0; i < C[chest].size(); i++) if(C[chest][i] == key) return true;
  for(int i = 0; i < N[chest].size(); i++) 
    if(V[N[chest][i]] == 0) 
      if(loop(N[chest][i], key, V))
          return true;
  return false;
}


void init_N() {
  N.clear();
  N.resize(C.size());
  for(int i = 0; i < C.size(); i++) 
    for(int j = 0; j < C[i].size(); j++)
       for(int k = 0; k < C.size(); k++) 
          if(i != k)
            if(C[i][j] == T[k]) N[i].push_back(k);
}

bool possible(vector<int> K, vector<int> V) {


  cerr << "Possible" << endl;
  for(int i = 0; i < V.size(); i++) if(V[i] == 0) cerr << i << " ";
  cerr << endl;
  for(int i = 0; i < K.size(); i++) cerr << K[i] << " ";
  cerr << endl;



  bool end = true;
  for(int i = 0; i < V.size(); i++) if(V[i] == 0) {end = false; break;}
  if(end) return true;
  if(K.size() == 0) return false;

  map<int, int> nbk;
  map<int, int> nbt;
  for(int i = 0; i < K.size(); i++) nbk[K[i]]++;
  for(int i = 0; i < T.size(); i++) if(V[i] == 0) nbt[T[i]]++;

  for(int i = 0; i < K.size(); i++) if(nbk[K[i]] >= nbt[K[i]]) {
    int key = K[i];
    for(int j = 0; j < T.size(); j++) if(V[j] == 0 && T[j] == key) {
      for(int l = 0; l < C[j].size(); l++) K.push_back(C[j][l]);
      V[j] = 1;
    }
    for(int j = 0; j < K.size(); j++) if(K[j] == key) {K[j] = K.back(); K.pop_back(); j--;}
    return possible(K, V);
  }

  for(int i = 0; i < T.size(); i++) 
    if(V[i] == 0 && nbk[T[i]] > 0) {
      vector<int> V2(V);
      if(loop(i, T[i], V2)) {
        V[i] = 1;
        for(int j = 0; j < K.size(); j++) if(K[j] == T[i]) {K[j] = K.back(); K.pop_back(); break;}
        for(int l = 0; l < C[i].size(); l++) K.push_back(C[i][l]);
        return possible(K, V);
      }
    }

  return false;
}

bool build_sol(vector<int> K, vector<int> &sol, vector<int> V) {
  if(sol.size() == C.size()) return true;
  map<int, int> nbk;
  for(int i = 0; i < K.size(); i++) nbk[K[i]]++;

  for(int i = 0; i < C.size(); i++) if(V[i] == 0 && nbk[T[i]] > 0) {
    vector<int> K2(K);
    vector<int> V2(V);
    for(int j = 0; j < K2.size(); j++) if(K2[j] == T[i]) {K2[j] = K2.back(); K2.pop_back(); break;}
    for(int l = 0; l < C[i].size(); l++) K2.push_back(C[i][l]);
    V2[i] = 1;
    if(possible(K2, V2)) {
      sol.push_back(i);
      return build_sol(K2, sol, V2);
    }
  }
  return false;
}

int main() {
  int test;
  cin >> test;
  for(int t = 1; t <= test; t++) {
    int K, _N;
    cin >> K >> _N;
    C.clear(); T.clear();
    C.resize(_N); T.resize(_N);
    vector<int> Key(K);
    for(int i = 0; i < K; i++) cin >> Key[i];
    for(int i = 0; i < _N; i++) {
      cin >> T[i];
      int nbk;
      cin >> nbk;
      C[i].resize(nbk);
      for(int j = 0; j < nbk; j++) cin >> C[i][j];
    }
    cout << "Case #" << t << ":";
    init_N();
/*
    for(int i = 0; i < N.size(); i++) {
      for(int j = 0; j < N[i].size(); j++) cout << N[i][j] << " ";
      cout << endl;
    }
*/
    vector<int> V(C.size(), 0);
    vector<int> sol;
    if(build_sol(Key, sol, V)) { 
      for(int i = 0; i < sol.size(); i++) cout << " " << (sol[i] + 1);
    }
    else cout << " IMPOSSIBLE";
    cout << endl;


  }
}
