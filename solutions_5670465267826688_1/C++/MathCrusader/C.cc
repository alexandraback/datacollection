#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const string val = "1ijk";
const int mult[4][4] =
{
  { 1, 2, 3, 4},
  { 2,-1, 4,-3},
  { 3,-4,-1, 2},
  { 4, 3,-2,-1}
};

int sign(int x){ return x < 0 ? -1 : 1; }

bool small(const string& s,long long X){
  string t;
  for(int i=0;i<X;i++)
    t += s;
  
  int curr = 1, ind = 0;
  
  for(;ind<t.length();ind++){
    curr = sign(curr) * mult[abs(curr)-1][val.find(t[ind])];
    if(curr == 2){
      ind++;
      break;
    }
  }
  if(ind >= t.length()) return false;
  
  curr = 1;
  for(;ind<t.length();ind++){
    curr = sign(curr) * mult[abs(curr)-1][val.find(t[ind])];
    if(curr == 3){
      ind++;
      break;
    }
  }
  if(ind >= t.length()) return false;
  
  curr = 1;
  for(;ind<t.length();ind++)
    curr = sign(curr) * mult[abs(curr)-1][val.find(t[ind])];
  
  return curr == 4;
}

bool do_case(){
  long long L,X;
  cin >> L >> X;
  string s;
  cin >> s;
  
  if(X < 20) return small(s,X);
  
  return small(s,12+X%4);
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--)
    cout << "Case #" << C++ << ": " << (do_case() ? "YES" : "NO") << endl;
  return 0;
}
