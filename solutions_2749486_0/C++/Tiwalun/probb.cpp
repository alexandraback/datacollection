#include<cstdio>
#include<iostream>

using namespace std;

void solve(int x, int y) {
  //move in correct x pos
  int cx,cy;
  int move = 1;
  cx = cy = 0;

  while (cx != x) {
    //cout << "At x " << cx << endl;
    if (move % 2 == 0) {
      cx -= move;
      cout << "W";
    } else {
      cx += move;
      cout << "E";
    }

    move++;
  }

  int dir;
  if (y > cy) dir = (move % 2);
  else {
    if (move % 2 == 0) {
      dir = 1;
    } else {
      dir = 0;
    }
  }

  while (cy != y) {
    //cout << "At y " << cy << endl;
    if (move % 2 == dir) {
      cy -= move;
      cout << "S";
    } else {
      cy += move;
      cout << "N";
    }

    move++;
  }
}

int main() {
  int probs;
  scanf("%i", &probs);
  
  for (int p = 1; p <= probs; p++) {
    int x,y;
    cin >> x >> y;
    printf("Case #%i: ",  p);
    solve(x,y);
    printf("\n");
  }
  return 0;
}
