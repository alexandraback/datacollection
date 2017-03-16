#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
  vector<int> slist(2500);
  vector<int> res;
  int cases; cin >> cases;
  for(int i = 1; i< cases + 1; i++){
    res.clear();
    int ssize; cin >> ssize;
    cin.ignore();
    for(int j = 0; j<2500; j++){
      slist[j] = 0;
    }
    int numin = 2*ssize -1;
    string line;
    while(numin--){
      getline(cin, line);
      stringstream ss(line);
      int temp;
      while(ss >> temp){
        temp--;
        slist[temp]++;
      }
    }
    for(int j = 0; j<2500; j++){
      if(slist[j]%2==1){
        res.push_back(j);
      }
    }
    if(res.size() != ssize){
      cout << "prob" << endl;
    }
    sort(res.begin(), res.end());
    cout << "Case #" << i << ":";
    for(int j = 0; j<res.size(); j++){
      cout << " " << ++res[j];
    }
    cout << endl;
  }
  return 0;
}
