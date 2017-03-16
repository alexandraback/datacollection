#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main(){
  ifstream inFile("A-large.in");
  ofstream ansFile("A-large.ans");
  int T;
  inFile >> T;

  for(int x = 1; x <= T; x++){
    int smax;
    inFile >> smax;
    string s;
    inFile >> s;

    int cnt = 0, ans = 0;
    for(int i = 0; i < s.size(); i++){
      int ci = s[i] - '0';
      if(i <= cnt){
        cnt += ci;
      }else{
        ans += i- cnt;
        cnt = i + ci;
      }
    }
    ansFile << "Case #" << x << ": " << ans << endl;
  }
}

