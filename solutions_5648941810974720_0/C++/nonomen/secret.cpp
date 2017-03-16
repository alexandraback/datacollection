#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int x = 0;x<t;x++){
  vector<int> o(10,0);
  vector<int> a(300,0);
  string s;
  cin >> s;
  for(auto i : s)
    a[i]++;
  while(a['Z'] > 0){
    a['Z']--;
    a['E']--;
    a['R']--;
    a['O']--;
    o[0]++;
  }
  while(a['X'] > 0){
    a['S']--;
    a['I']--;
    a['X']--;
    o[6]++;
  }
  while(a['W'] > 0){
    a['T']--;
    a['W']--;
    a['O']--;
    o[2]++;
  }
  while(a['G'] > 0){
    a['E']--;
    a['I']--;
    a['G']--;
    a['H']--;
    a['T']--;
    o[8]++;
  }
  while(a['U'] > 0){
    a['F']--;
    a['O']--;
    a['U']--;
    a['R']--;
    o[4]++;
  }
  while(a['S'] > 0){
    a['S']--;
    a['E']--;
    a['V']--;
    a['E']--;
    a['N']--;
    o[7]++;
  }
  while(a['R'] > 0){
    a['T']--;
    a['H']--;
    a['R']--;
    a['E']--;
    a['E']--;
    o[3]++;
  }
  while(a['S'] > 0){
    a['S']--;
    a['E']--;
    a['V']--;
    a['E']--;
    a['N']--;
    o[7]++;
  }
  while(a['V'] > 0){
    a['F']--;
    a['I']--;
    a['V']--;
    a['E']--;
    o[5]++;
  }
  while(a['I'] > 0){
    a['N']--;
    a['I']--;
    a['N']--;
    a['E']--;
    o[9]++;
  }
  while(a['O'] > 0){
    a['O']--;
    a['N']--;
    a['E']--;
    o[1]++;
  }
  cout << "Case #" << x+1 << ": ";
  for(int i = 0;i<10;i++)
    for(int j = 0;j<o[i];j++)
      cout << i;
  cout << "\n";
}
return 0;
}
