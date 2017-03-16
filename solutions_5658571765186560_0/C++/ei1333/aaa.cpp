#include<bits/stdc++.h>
using namespace std;

bool table[4][4][4] = {
  {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
  },
  {
    {0,1,0,1},
    {1,1,1,1},
    {0,1,0,1},
    {1,1,1,1},
  },
  {
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,1,0},
  },
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,1}
  }
};

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";

    int X, R, C;
    cin >> X >> R >> C;
    --X, --R, --C;
    puts(!table[X][R][C] ? "RICHARD" : "GABRIEL");
  }
}

