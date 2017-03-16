#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int i, N, t, T;
vector <double> naomi, ken;

void read(vector <double> &v) {
  v.resize(N);
  for (int i=0; i<N; i++) cin >> v[i];
  sort(v.begin(), v.end());
}

int main(){ 
  cin >> T;
  while (++t<=T) {
    cin >> N;
    read(naomi);
    read(ken);
    int w=N, dw=N, kb=0, ke=N-1;
    
    for (i=0; i<N; i++)
      if (naomi[N-1-i] < ken[ke]) ke--, w--;
      else kb++;

    kb=0; ke=N-1;
    for (i=0; i<N; i++)
      if (naomi[i] < ken[kb]) ke--, dw--;
      else kb++;
    
    printf("Case #%d: %d %d\n", t, dw, w);
  }
}
