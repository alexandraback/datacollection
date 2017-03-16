#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int R, N, M, K;

vector<vector<int> > sets;

void gen(int i, vector<int>& v) {
  if (i == N) {
    sets.push_back(v);
    return;
  }

  for (int digit = 2; digit <= M; digit++) {
    v[i] = digit;
    gen(i+1, v);
  }
}

int calc(vector<int>& original, vector<int>& products) {
  map<int,int> prods;

  for (int m = 0; m < (1 << original.size()); m++) {
    int product = 1;

    for (int i = 0; i < original.size(); i++) {
      if (m & (1 << i)) {
        product *= original[i];
      }
    }

    prods[product] += 1;
  }

  int score = 0;

  for (int x : products) {
    if (prods[x] == 0)
      return -1;
    score += prods[x];
  }

  return score;
}

void solve() {
  sets.clear();
  vector<int> temp(N);
  gen(0, temp);

  vector<int> nums(K), best_set;
  for (int i = 0; i < K; i++) {
    int a;
    scanf("%d ", &a);
    nums[i] = a;
  }

  int best = 0;
  for (auto& s : sets) {
    int score = calc(s, nums);
    if (score > best) {
      best = score;
      best_set = s;
    }
  }

  for (int i : best_set)
    printf("%d", i);
  printf("\n");
}

int main() {
  int n;
  scanf("%d\n", &n);


  printf("Case #1:\n");
  scanf("%d %d %d %d ", &R, &N, &M, &K);
  for (int i = 0; i <R ; i++)
    solve();

  return 0;
}
