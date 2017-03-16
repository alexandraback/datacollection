#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int i=2;
const int j=3;
const int k=4;

// multiplication table
signed char mt[5][5] = {{0, 0, 0, 0 ,0}, 
                        {0, 1, 2, 3 ,4}, 
                        {0, 2,-1, 4,-3},
                        {0, 3,-4,-1, 2},
                        {0, 4, 3,-2,-1}};

signed char M[10024][10024], Ldeg[4];

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
    string s;
    cin >> L >> X >> s;
    bool ans = false;

    if (L*X > 2) {
      for (int a=0; a<L; a++) { 
        M[a][a] = s[a]-'i'+2;
        for (int b=a+1; b<L; b++)
          M[a][b] = mult(M[a][b-1], s[b]-'i'+2);
      }

      Ldeg[0] = 1;
      for (int d=1; d<4; d++)
        Ldeg[d] = mult(Ldeg[d-1], M[0][L-1]);
      int dc = 4;
      if (Ldeg[1] == 1) dc=1;
      else if (Ldeg[3] == Ldeg[1]) dc=2;
      
      for (int a=0; a<L && !ans; a++)
        for (int dx=0; dx<dc; dx++) if (mult(Ldeg[dx], M[0][a]) == i)
          for (int b=0; b<L && !ans; b++)
            for (int dz=0; dz<dc; dz++) if (mult(M[b][L-1], Ldeg[dz]) == k) {

              if (a < b && M[a+1][b-1] == j) {
                long long n = X-1-dx-dz;
                if (n >= 0 && n%dc == 0) 
                  ans = true;
              } 

              for (int dy=0; dy<dc; dy++)
                if (a == L-1 && mult(Ldeg[dy], M[0][b-1]) == j ||
                    b == 0 && mult(M[a+1][L-1], Ldeg[dy]) == j ||
                    a != L-1 && b > 0 && mult(mult(M[a+1][L-1], Ldeg[dy]), M[0][b-1]) == j) {
                 long long n = X-dx-dz-dy-2;
                 if (n >= 0 && n%dc == 0) 
                   ans = true;
                }

            }
    }

    cout << "Case #" << t << ": " << (ans ? "YES" : "NO") << endl;
 }
}
