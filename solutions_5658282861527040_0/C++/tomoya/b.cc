#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

string getUniqueCh(string str) {
  string uniqueCh = "";

  for (int i=0; i<(int)str.size(); i++) {
    if(i == 0) { uniqueCh += str[i]; }
    else if (str[i-1] != str[i]) {
      uniqueCh += str[i];
    }
  }
  return uniqueCh;
}

vector<int> getUniqueChNum(string str) {
  vector<int> uniqueChNum(1,1);
  int idx = 0;

  for (int i=1; i<(int)str.size(); i++) {
    if (str[i] == str[i-1]) {
      uniqueChNum[idx]++;
    } else {
      uniqueChNum.push_back(1);
      idx++;
    }
  }
  return uniqueChNum;
}

int main() {
  int totalTc;
  cin >> totalTc;
  for(int tc = 1; tc <= totalTc; tc++) {
    int a,b,k; cin >> a >> b >> k;
    set<pair<int,int> > nums;
    for (int i=0; i<a; i++) {
      for(int j=0; j<b; j++) {
	if((i&j) < k) {
	  nums.insert(make_pair(i,j));
	}
      }
    }
    cout << "Case #" << tc << ": " << nums.size() << endl;;
  }
  return 0;
}
