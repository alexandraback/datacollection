#include<bits/stdc++.h>
using namespace std;
static const signed table[4][4] = {
  {0, 1, 2, 3},
  {1, 0, 3, 2},
  {2, 3, 0, 1},
  {3, 2, 1, 0}
};
static const bool sign[4][4] = {
  {true, true, true, true},
  {true, false, true, false},
  {true, false, false, true},
  {true, true, false, false}
};

char cmb[128];

int main() {
  cmb['1'] = 0, cmb['i'] = 1, cmb['j'] = 2, cmb['k'] = 3;

  int T;
  cin >> T;
  for(int a = 1; a <= T; a++) {
    
    bool Enable = false;

    int L, X;
    cin >> L >> X;
    string str;
    cin >> str;

    string real = "";
    for(int i = 0; i < X; i++) real += str;

    typedef pair< int, int > Pi;
    typedef pair< Pi, Pi > Pii;

    queue< Pii > Que;
    Que.push(make_pair(make_pair(0, true), make_pair(0, 0)));
    bool v[10005][2][3][4] = {{{{}}}};
    v[0][true][0][0] = true;


    while(!Que.empty()) {
      Pii p = Que.front(); Que.pop();
      if(p.first.first == real.size()) continue;

      int next = table[p.second.second][cmb[real[p.first.first]]]; // 次の位置
      bool signe = sign[p.second.second][cmb[real[p.first.first]]];
      if(signe) signe = p.first.second;
      else signe = !p.first.second;

      if(signe && next == p.second.first + 1) { // 次の文字へ行ける

        if(next == 3) {
          if(p.first.first + 1 == real.size()) {
            Enable = true;
            break;
          }
        } else {
          if(!v[p.first.first + 1][signe][next][0]) {
            Que.push(make_pair(make_pair(p.first.first + 1, signe), make_pair(next, 0)));
            v[p.first.first + 1][signe][next][0] = true;
          }
        }
      }
      
      if(!v[p.first.first + 1][signe][p.second.first][next]) {
        v[p.first.first + 1][signe][p.second.first][next] = true;
        Que.push(make_pair(make_pair(p.first.first + 1, signe), make_pair(p.second.first, next)));
      }
      

    }



    cout << "Case #" << a << ": ";
    puts(Enable ? "YES" : "NO");
  }
}
