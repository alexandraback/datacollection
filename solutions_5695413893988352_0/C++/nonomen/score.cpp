#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
string s;
string bs;
long long ba;
long long bb;

void back(int i){
  if(i < 0){
    int va = 0,vb=0;
    int t = 1;
    for(int j = s.size()/2-1;j>=0;j--,t*=10)
      va += (s[j] - '0')*t;
    t = 1;
    for(int j = s.size()-1;j>=s.size()/2;j--,t*=10)
      vb += (s[j] - '0')*t;
    if(abs(va-vb) < abs(ba - bb)){
      ba = va;
      bb = vb;
      bs = s;
    }
    else if(abs(va-vb) == abs(ba - bb) && va < ba){
      ba = va;
      bb = vb;
      bs = s;
    }
    else if(abs(va-vb) == abs(ba - bb) && va == ba && vb < bb){
      ba = va;
      bb = vb;
      bs = s;
    }
    return;
  }
  else{
  if(s[i] == '?'){
    for(int j = 9;j>=0;j--){
      s[i] = '0' + j;
      back(i-1);
      s[i] = '?';
    }
  }
  else
    back(i-1);
  }
  return;
}



int main(){
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    string x,y;
    cin >> x >> y;
    s = x+y;
    ba = 2e5;
    bb = 0;
    back(s.size()-1);
    cout << "Case #" << i+1 << ": "<< bs.substr(0,s.size()/2) << " " << bs.substr(s.size()/2) << "\n";
  }
  return 0;
}
