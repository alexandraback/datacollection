#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int i=2;
const int j=3;
const int k=4;

signed char mt[5][5] = {{0, 0, 0, 0 ,0}, 
                        {0, 1, 2, 3 ,4}, 
                        {0, 2,-1, 4,-3},
                        {0, 3,-4,-1, 2},
                        {0, 4, 3,-2,-1}};

signed char M[10024][10024];

inline signed char mult(signed char a, signed char b)
{
  signed char res = mt[abs(a)][abs(b)];
  return a*b<0 ? -res : res;
}

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    long long L, X;
    cin >> L >> X;
    string s;
    cin >> s;

    bool ans = false;

    if (L*X > 2) {

      if (L*X <= 10000) {
        string x(s);
        for (int n=1; n<X; n++)
          s += x;
        L = L*X;
        X = 1;
      }

      for (int a=0; a<L; a++) { 
        M[a][a] = s[a]-'i'+2;
        //for (int b=a+1; b<a+L; b++)
        // M[a][b%L] = mult(M[a][b-1], s[b%L]-'i'+2);
        for (int b=a+1; b<L; b++)
          M[a][b] = mult(M[a][b-1], s[b]-'i'+2);
      }

      if (X == 1) {
        for (int a=0; a<L-2 && !ans; a++)
          if (M[0][a] == i)
            for (int b=a+1; b<L-1; b++)
              if (M[a+1][b] == j && M[b+1][L-1] == k) {
                ans = true;
                break;
              }
      }
    }

    cout << "Case #" << t << ": " << (ans ? "YES" : "NO") << endl;
 }
}
