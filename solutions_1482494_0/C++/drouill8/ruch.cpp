#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct level {
  int b;
  int l1;
  int l2;
};

bool operator < (const level& a, const level& b) {
  return a.l2 > b.l2;
}

int tCase() {
  int n;
  cin >> n;
  list<level> lvls;
  vector<level> tv(n);
  for (int i = 0; i < n; ++i) {
    tv[i].b = 0;
    cin >> tv[i].l1 >> tv[i].l2; 
  }
  sort(tv.begin(),tv.end());
  for (int i = 0; i < n; ++i)
    lvls.push_back(tv[i]);
  int cnt = 0;
  int stars = 0;
  while (lvls.size() != 0) {
    list<level>::iterator it;
    list<level>::iterator ie = lvls.end();
    // beat none, get 2
    for (it = lvls.begin(); it != ie; ++it)
      if (it->b == 0 && it->l2 <= stars) {
        stars += 2;
        lvls.erase(it);
        goto loopend;
      }
    // beat 1, get 1
    for (it = lvls.begin(); it != ie; ++it)
      if (it->b == 1 && it->l2 <= stars) {
        stars += 1;
        lvls.erase(it);
        goto loopend;
      }
    // beat none, get 1
    for (it = lvls.begin(); it != ie; ++it)
      if (it->b == 0 && it->l1 <= stars) {
        stars += 1;
        it->b = 1;
        goto loopend;
      }
    //can't do anything
    return -1;
loopend:
    ++cnt;
  }
  return cnt;
}

int main() {
  int tCases;
  cin >> tCases;
  for (int i = 1; i <= tCases; ++i) {
    int res = tCase();
    if (res == -1)
      printf("Case #%d: Too Bad\n",i);
    else
      printf("Case #%d: %d\n",i,res);
  }
}
