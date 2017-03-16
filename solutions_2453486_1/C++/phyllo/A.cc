#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

bool check(char ply, const vector<char>& ls){
  //cout << ply << ":";
  //rep(i,ls.size()) cout << ls[i]; cout << endl;
  
  rep(i,ls.size()){
    if(ls[i] != 'T' && ls[i] != ply) return false;
  }
  return true;
}


string solve(const vector<string>& field){
  bool winX = false, winO = false;
  bool emp = false;
  rep(i,4){
    vector<char> tate, yoko;
    rep(j,4){
      if(field[i][j] == '.') emp = true;
      tate.push_back(field[j][i]);
      yoko.push_back(field[i][j]);
    }
    if(check('X', tate)) winX = true;
    if(check('X', yoko)) winX = true;
    if(check('O', tate)) winO = true;
    if(check('O', yoko)) winO = true;
  }

  {
    vector<char> naname1, naname2;
    rep(i,4){
      naname1.push_back(field[i][i]);
      naname2.push_back(field[i][3-i]);
    }
    if(check('X', naname1)) winX = true;
    if(check('X', naname2)) winX = true;
    if(check('O', naname1)) winO = true;
    if(check('O', naname2)) winO = true;
  }

  if(winX) return "X won";
  if(winO) return "O won";
  if(emp) return "Game has not completed";
  return "Draw";
}

int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    vector<string> field;
    string tmp;
    rep(i,4){
      cin >> tmp;
      field.push_back(tmp);
    }
    
    cout << "Case #" << t+1 << ": " << solve(field) << endl;
  }
  
  return 0;
}
