#include <iostream>
#include <vector>

using namespace std;

int minExp(int r, int c, int w){
  if(r != 1){
    return (r-1)*c/w + minExp(1, c, w);
  }
  if(w == c){
    return w;
  } else if(2*w > c){
    return w + 1;
  }
  return minExp(r, c-w, w) + 1;
}

int main(){
  int t;
  cin >> t;
  int r , c, w;
  for(int i = 0; i < t; ++i){
    cin >> r >> c >> w;
    cout << "Case #" << (i+1) << ": " << minExp(r, c, w) << endl;
  }
}
