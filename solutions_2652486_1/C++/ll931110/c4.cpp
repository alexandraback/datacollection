#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxk 20000
#define maxn 12
using namespace std;

vector<int> element[maxk];
map<long long,int> mp[maxk];
int T,r,n,m,K;
long long arr[maxn];
int counter = 0;
double LOG[1 << maxn];
double chance[maxk];

inline void call(int idx,int pos,long long prod) {
  if (pos >= n) {
    mp[idx][prod]++;
    return;
  }
  call(idx,pos + 1,prod);
  call(idx,pos + 1,prod * element[idx][pos]);
}

inline void makeSubset(int counter) {
  call(counter,0,1);
}

inline void attempt(int pos,int lower) {
  if (pos >= n) {
    element[counter].resize(n);
    for (int i = 0; i < n; i++) element[counter][i] = arr[i];
    makeSubset(counter);
    counter++;
//    fprintf(stderr,"%d\n", counter);
    return;
  }
  for (int i = lower; i <= m; i++) {
    arr[pos] = i;
    attempt(pos + 1,i);
  }
}

inline bool fullCheck(int it) {
  chance[it] = 0;
  for (int i = 0; i < K; i++)
    if (!mp[it].count(arr[i])) return false;
  return true;
}

void solveCase(int it) {
  fprintf(stderr,"%d\n", it);
  for (int i = 0; i < K; i++) scanf("%lld", &arr[i]);
  vector<int> enlist;
  enlist.clear();
  for (int i = 0; i < counter; i++)
    if (fullCheck(i)) enlist.push_back(i);

  int pos = enlist[rand() % enlist.size()];
  for (int i = 0; i < element[pos].size(); i++)
    printf("%d", element[pos][i]);
  printf("\n");
}

int main() {
  scanf("%d", &T);
  scanf("%d %d %d %d", &r, &n, &m, &K);  
  for (int i = 1; i < (1 << n); i++) LOG[i] = log(i) * 1000;
  attempt(0,2);
//  cout << counter << endl;  return 0;
  printf("Case #1:\n");
  for (int i = 0; i < r; i++) solveCase(i);
}
