#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main (){
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t){
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    vector<vector<int> > jp(J+1, vector<int> (P+1,0));
    vector<vector<int> > js(J+1, vector<int> (S+1,0));
    vector<vector<int> > ps(P+1, vector<int> (S+1,0));
    vector<vector<int> > comb;
    int n = 0;
    for (int j = 1 ; j <= J; ++j){
      for (int p = 1 ; p <= P; ++p){
        for (int s = 1 ; s <= S; ++s){
          if (jp[j][p] < K && js[j][s]< K && ps[p][s] <K){
            vector<int> c (3);
            c[0] = j;
            c[1] = p;
            c[2] = s;
            comb.push_back(c);
            jp[j][p] ++;
            js[j][s]++;
            ps[p][s]++;
            n++;
          }
        }
      }
    }
   

    cout << "Case #" << t << ": " << n << endl;
    for (int i = 0 ; i < comb.size(); ++i){
          cout << comb[i][0] <<' '<< comb[i][1] <<' ' << comb[i][2] << endl;
    }
  }


}
