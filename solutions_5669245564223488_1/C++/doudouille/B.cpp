
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


bool valid(string S) {
  char prev = ' ';
  char T[256] = {0};
  for(int j = 0; j < S.length(); j++)
    if(S[j] != prev) {
      if(T[S[j]]) return false;
      T[prev] = 1;
      prev = S[j];
    }
  return true;
}


bool merge( vector<string> & C) {

  for(int i = 0; i < C.size(); i++) 
    for(int j = 0; j < C.size(); j++) 
      if(i != j) 
        if(C[i][1] == C[j][0]) {
          C[i][1] = C[j][1];
          C.erase(C.begin() + j);
          return true;
      }
  return false;
}


long long solve(vector<string> C) {

  for(int i = 0; i < C.size(); i++) if(C[i].length() == 1) C[i] += C[i];
  

  for(int i = 0; i < C.size(); i++) if(!valid(C[i])) return 0;

  for(int i = 0; i < C.size(); i++) if(C[i].length() >= 3)
    for(int j = 1; j < C[i].length() - 1; j++) if(C[i][j] != C[i][0] && C[i][j] != C[i][C[i].length()-1])
      for(int k = 0; k < C.size(); k++) if(k != i)
        for(int l = 0; l < C[k].length(); l++)
          if(C[i][j] == C[k][l]) return 0;



  for(int i = 0; i < C.size(); i++) {
    C[i][1] = C[i][C[i].length()-1];
    C[i].resize(2);
  }

  sort(C.begin(), C.end());


  long long nb = 1LL;

  for(int i = 0; i < C.size(); i++) {
    if(C[i][0] == C[i][1]) {
      long long nbd = 1;
      for(int j = 1; i + j < C.size(); j++) if(C[i+j] == C[i]) nbd++; else break;
      for(long long j = 1; j <= nbd; j++) nb  = (nb*j) % 1000000007LL;
      C.erase(C.begin() + i, C.begin() + i + nbd - 1);
    }
  }

  long long nb_end= 0;
  for(int i = 0; i < C.size(); i++) if(C[i][0] == C[i][1]) {
    nb_end++;
    for(int j = 0; j < C.size(); j++) if(i!=j && (C[i][0] == C[j][0] || C[i][0] == C[j][1])) {
      nb_end--;
      break;
    }
    C.erase(C.begin()+i);
    i--;
  }

  for(int i = 0; i < C.size(); i++) for(int j = 0; j < C.size(); j++) if(i != j && C[i][0] == C[j][0]) return 0;
  for(int i = 0; i < C.size(); i++) for(int j = 0; j < C.size(); j++) if(i != j && C[i][1] == C[j][1]) return 0;



  while(merge(C)) {
    for(int i = 0; i < C.size(); i++) if(C[i][0] == C[i][1]) return 0;
  }

  for(long long i = 1; i <= C.size() + nb_end; i++) nb  = (nb*i) % 1000000007LL;

  return nb;
}


int main() {
  int T;	
  cin >> T;

  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];



cerr << t << endl ;

    cout << "Case #" << t << ": " << solve(C) << endl;



  }


}
