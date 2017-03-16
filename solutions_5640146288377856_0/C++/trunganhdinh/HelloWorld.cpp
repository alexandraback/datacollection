#include<bits/stdc++.h>

#define MIN(a, b) (((a) < (b))?(a):(b))
#define MAX(a, b) (((a) > (b))?(a):(b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "HelloWorld.out";


int main(void){
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  for (int idTest = 0; idTest < numTest; ++ idTest){
    int R, C, W;
    cin >> R >> C >> W;
    //cerr << R << " " << C  << " " << W << endl;
    int result = R * (C / W);
    if (C % W == 0){
       result += W - 1;
    } else {
       result += W;
    }
    cout << "Case #" << idTest + 1 << ": " << result << endl;
  }

  return 0;
}
