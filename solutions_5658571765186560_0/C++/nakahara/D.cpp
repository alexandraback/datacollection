#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

// Shortcuts for common data type
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;

int main(){
  ifstream in("inputD");
  cin.rdbuf(in.rdbuf());
  ofstream out("outputD");
  cout.rdbuf(out.rdbuf());
  
  int cases;
  cin >> cases;
  
  for(int i = 1 ; i<=cases; i++){
    if(i != 1)
      cout << endl;
    cout << "Case #" << i << ": ";

    int n, w,h;
    cin >> n >> w >> h;

    // make w>=h 
    if(w < h){
      int temp = h;
      h = w;
      w = temp;
    }
    
    // doesn't fit if the area is not divisible
    if(w*h % n != 0){
      cout << "RICHARD";
      continue;
    }

    // n<=2 always possible
    // n>=7 impossible as there is an isolated space
    if(n <= 2){
      cout << "GABRIEL";
      continue;
    }else if(n >= 7){
      cout << "RICHARD";
      continue;
    }
    
    // For 3<=n<=6 one of the side == 1 impossible
    if(h ==1){
      cout << "RICHARD";
      continue;
    }

    // Otherwise n==3 possible by making 2x3 block
    if(n==3){
      cout << "GABRIEL";
      continue;
    }
    // For 4<=n<=6 side length 2 not possible
    if(h==2){
      cout << "RICHARD";
      continue;
    }

    // Otherwise n==4 possible by making 3x4 block
    if(n==4){
      cout << "GABRIEL";
      continue;
    }

    // n=5 and 5x3 not possible since the stair shaped
    if(n==5 && w==5 & h==3){
      cout << "RICHARD";
      continue;
    }
    // Otherwise n=5 possible by makeing either 5x3 or 10x3 or 4x5
    if(n==5){
      cout << "GABRIEL";
      continue;
    }

    //  *   makes anything with height 3 not possible
    //****
    //   *
    if(h==3){
      cout << "RICHARD";
      continue;
    }

    // Otherwise make 6x4 block
    cout << "GABRIEL";
  }
  return 0;
}

