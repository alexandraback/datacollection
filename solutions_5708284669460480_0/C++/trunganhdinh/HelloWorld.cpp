#include<bits/stdc++.h>

#define MIN(a, b) (((a) < (b))?(a):(b))
#define MAX(a, b) (((a) > (b))?(a):(b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "HelloWorld.out";

const int MAX_K = 7 + 2;
const int MAX_L = 7 + 2;
const int MAX_S = 7 + 2;

vector<int> result;
int maxApp = -10;
char c[MAX_K];

void tried(int K, int L, string l, int S, int idS, string cur){
  //cout << idS << ": \"" << cur << "\"" << endl;
  if (idS == S + 1){
    int count = 0;
    for (int idS = 0; idS < S; ++ idS){
      bool found = true;
      for (int idL = 0; idL < L; ++ idL){
        if (cur[idS + idL] != l[idL]){
          found = false;
          break;
        }
      }
      if (found){
        ++ count;
      }
    }
    //cout << "\"" << cur << "\"" << count << endl;
    if (count > maxApp){
      maxApp = count;
    }
    result.push_back(count);
    return;
  }
  for (int idK = 0; idK < K; ++ idK){
    cur[idS - 1] = c[idK];
    tried(K, L, l, S, idS + 1, cur);
  }
}


int main(void){
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  for (int idTest = 0; idTest < numTest; ++ idTest){
    result.clear();
    maxApp = -10;
    int K, L, S;
    cin >> K >> L >> S;
    for (int idK = 0; idK < K; ++ idK){
      cin >> c[idK];
      //cerr << "\'" << c[idK] << "\'";
    }
    string l;
    cin >> l;
    //cerr << "\"" << l << "\"" << endl;
    string cur;
    for (int idS = 0; idS < S; ++ idS){
      cur.push_back('1');
    }

    tried(K, L, l, S, 1, cur);

    vector<int>::iterator it;
    long long int sum = 0;
    for (it = result.begin(); it != result.end(); ++ it){
      sum += maxApp - *it;
    }
    double finalResult = (double) sum / (int) result.size();


    cout << "Case #" << idTest + 1 << ": " << " " << setprecision(9) << finalResult << endl;
  }

  return 0;
}
