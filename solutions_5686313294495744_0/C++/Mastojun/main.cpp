#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#include <string>
#include <set>
#include <map>
using namespace std;

int num;
int result;
vector<string> lefts;
vector<string> rights;

bool isOk(vector<bool> isFake) {
  for (int i = 0; i < lefts.size(); i++) {
    if (!isFake[i]) continue;
    bool fl = false;
    bool fr = false;
    for (int j = 0; j < rights.size(); j++) {
      if (isFake[j]) continue;
      if (i == j) continue;
      fl |= lefts[i] == lefts[j];
      fr |= rights[i] == rights[j];
    }
    if (!fl || !fr) 
      return false;
  }

  for (int i = 0; i < lefts.size(); i++) {
    if (isFake[i]) continue;
    bool fl = false;
    bool fr = false;
    for (int j = 0; j < rights.size(); j++) {
      if (isFake[j]) continue;
      if (i == j) continue;
      fl |= lefts[i] == lefts[j];
      fr |= rights[i] == rights[j];
    }
    if (fl && fr) 
      return false;
  }

  return true;
}

int getFake(vector<bool>& isFake) {
  int result = 0;
  for (auto is : isFake) {
    result += is ? 1 : 0;
  }
  return result;
}

void go(vector<bool>& isFake, int idx) {
  if (idx == num) {
    if (isOk(isFake)) {
      result = max(result, getFake(isFake));
    }
    return;
  }

  isFake[idx] = true;
  go(isFake, idx + 1);
  isFake[idx] = false;
  go(isFake, idx + 1);
}

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
  
    cin >> num;

    
    lefts.clear();
    rights.clear();
    
    for (int i = 0; i < num; i++) {
      string L, R;
      cin >> L >> R;
      lefts.push_back(L);
      rights.push_back(R);
    }

    result = 0;
    vector<bool> isFake(num, true);
    go(isFake, 0);

    cout << "Case #" << kase << ": " << result << endl;

    fprintf(stderr, "%d\n", kase);
  }

  return 0;
}
