//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string arr[4];
bool win(char ch){
  
  for(int i = 0 ; i < 4 ; i++)
    if(count(arr[i].begin(), arr[i].end(), ch) == 4)
      return true;
  
  for(int i = 0 ; i < 4 ; i++)
    if(arr[0][i] == ch && arr[1][i] == ch && arr[2][i] == ch && arr[3][i] == ch)
      return true;
  
  int i = 0;
  for(; i < 4 ; i++)
    if(arr[i][i] != ch)break;
  if(i == 4)
    return true;
  i = 0;
  for(; i < 4 ; i++)
    if(arr[i][4-i-1] != ch)break;
  return i == 4;
}

int main() {
  
  freopen("/Users/hamza/Downloads/A-large.in", "rt", stdin);
  freopen("/Users/hamza/A-large.out", "wt", stdout);
  int tt; cin >> tt;
  for(int t = 1 ; t <= tt; t++){
    int dotcnt = 0;
    int tr = -1, tc = -1;
    for(int i = 0 ; i < 4 ; i++){
      cin >> arr[i];
      dotcnt += count(arr[i].begin(), arr[i].end(), '.');
      int j = find(arr[i].begin(), arr[i].end(), 'T')-arr[i].begin();
      if(j != 4){
        tr = i;
        tc = j;
      }
    }
    
    cout << "Case #" << t << ": ";
    if(tr != -1)
      arr[tr][tc] = 'X';
    if(win('X'))
      cout << "X won";
    else{
      if(tr != -1)
        arr[tr][tc] = 'O';
      if(win('O'))
        cout << "O won";
      else {
        cout << (dotcnt? "Game has not completed" : "Draw");
      }
    }
    cout << endl;
  }
  
  return 0;
}
