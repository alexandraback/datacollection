#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);
    if(R > C) swap(R, C);
    bool richardWins;
    if((R * C) % X) richardWins = true;
    else if(X >= 7) richardWins = true;
    else if(X == 6) richardWins = R <= 3;
    else if(X == 5) richardWins = R <= 2 || (R == 3 && C == 5);
    else if(X == 4) richardWins = R <= 2;
    else if(X == 3) richardWins = R <= 1;
    else richardWins = false;
    printf("Case #%d: %s\n", t, richardWins ? "RICHARD" : "GABRIEL");
  }
}
