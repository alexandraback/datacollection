#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstring>
#include <cstddef>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

using namespace std;

int main(){
  FILE *fin = freopen("C.in", "r", stdin);
  assert(fin != NULL);
  FILE *fout = freopen("C.ans", "w", stdout);

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for(int t = 1; t <= T; t++){
    int N;
    cin >> N;

    int D[N], H[N], M[N];
    for(int i = 0; i < N; i++){
      cin >> D[i] >> H[i] >> M[i];
    }

    int ans = 0;
    if(N == 1){
      ans = 0;
    }else{
      long long d1 = D[0], d2 = D[1];
      long long m1 = M[0], m2 = M[1];
      if(m1 > m2){
        swap(d1, d2);
        swap(m1, m2);
      }

      if((360 - d1) * m1 < (360 - d2) * m2){
        if((720 - d1) * m1 <= (360 - d2) * m2){
          ans = 1;
        }else{
          ans = 0;
        }
      }else{
        ans = 0;
      }

    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}

