#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

char in[N+2];

enum class H : int8_t {one = 0, i = 1, j = 2, k = 3, minusOne = 4, minusI = 5, minusJ = 6, minusK = 7};

const vector<H> Habs = {H::one, H::i, H::j, H::k, H::one, H::i, H::j, H::k};
H abs(H z){return Habs[(int8_t)z];}

const vector<H> Hneg = {H::minusOne, H::minusI, H::minusJ, H::minusK, H::one, H::i, H::j, H::k};
H operator-(H z){return Hneg[(int8_t)z];}

const vector<vector<H> > Hmul = {
  {H::one, H::i,   H::j,    H::k},
  {H::i,  -H::one, H::k,   -H::j},
  {H::j,  -H::k,  -H::one,  H::i},
  {H::k,   H::j,  -H::i,   -H::one}
};
H operator*(H z1, H z2){
  H z = Hmul[(int8_t) abs(z1)][(int8_t)abs(z2)];
  return (z1 != abs(z1)) ^ (z2 != abs(z2)) ? -z : z;
}

map<char, H> HtoH = {{'i', H::i}, {'j', H::j}, {'k', H::k}};
H toH(char c){assert(HtoH.count(c)); return HtoH[c];}

int main(){
  assert(H::j * H::i == -H::k);
  assert(H::j * H::i == -H::k);
  assert((H::i * H::j) * H::k == H::i * (H::j * H::k));
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    int L, X;
    scanf("%d%d%s", &L, &X, in);
    H acc = H::one;
    bool iAppeared = false;
    bool iNijAppeared = false;
    for(int i = 0; i < min(X, X%4 + 8); i++){
      for(char *c = in; c != in + L; c++){
        acc = acc * toH(*c);
        if(acc == H::i) iAppeared = true;
        if(iAppeared && acc == H::i * H::j) iNijAppeared = true;
      }
    }
    bool result = (iNijAppeared && acc == H::i * H::j * H::k);
    printf("Case #%d: %s\n", t, result ? "YES" : "NO");
  }
}
