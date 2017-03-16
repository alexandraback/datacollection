/* Opgave: C */
// 7+8+7=22 includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;
int N, M;
int codes[50];
std::vector<int> nb[50];
bool visited[50];
std::vector<int> stack;
std::vector<int> route;

bool canPop(int end) {
  queue<int> q;
  for(int i = 0; i  < end; ++i)
    q.push(stack[i]);
  vector<bool> done(N);
  while(!q.empty()) {
    int p = q.front();
    q.pop();
    done[p]  = true;
    for(int i = end; i < stack.size(); ++i)
      if(p == stack[i])
	continue;
    for(int j = 0; j < nb[p].size(); ++j)
      if(!done[nb[p][j]] && !visited[nb[p][j]]) {
	done[nb[p][j]] = true;
	q.push(nb[p][j]);
      }
  }
  int cnt = 0;
  for(int i = 0; i < N; ++i)
    if(visited[i] || done[i])
      ++cnt;
  return cnt == N;
}

int cheapestCostInFrontier() {
  int v = 100000;
  for(int i = stack.size() - 1; i >= 0; --i) {
    if(!canPop(i + 1))
      break;
    //std::cout << "stack idx: " << i << "\n";
    for(int j = 0; j < nb[stack[i]].size(); ++j) 
      if(!visited[nb[stack[i]].at(j)])
	v = min(v, codes[nb[stack[i]].at(j)]);
  }
  return v;
}
void selectCheapestStart() {
  int a = 0;
  for(int i = 1; i < N; ++i)
    if(codes[i] < codes[a])
      a = i;
  stack.push_back(a);
  route.push_back(a);
  visited[a] = true;
}

int currCase;
void testcase() {
  cin >> N >> M;
  stack.clear();
  route.clear();
  for(int i = 0; i < N; ++i) {
    nb[i].clear();
    cin >> codes[i];
    visited[i] = false;
  }
  for(int i = 0; i < M; ++i) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    nb[a].push_back(b);
    nb[b].push_back(a);
  }
  selectCheapestStart();
  int it = 0;
  while(route.size() != N) {
    /*std::cout << "Start step: ";
    for(int i = 0; i < stack.size(); ++i)
      cout << " " << stack[i]+1;
    cout << "\n";
    std::cout << "canPop: ";
    for(int i = 0; i <= stack.size(); ++i)
    ;*/
    if(++it > 3 * N)
      std::abort();
    if(stack.size() > N)
      std::abort();
    int n = -1;
    for(int j = 0; j < nb[stack.back()].size(); ++j)
      if(!visited[nb[stack.back()][j]] && (n == -1 || codes[n] > codes[nb[stack.back()][j]]))
	n = nb[stack.back()][j];
    //std::cout << "cheapest neighbour:  " << (n +1) << "\n";
    int cheap = cheapestCostInFrontier();
    if(n == -1 || (codes[n] > cheap && canPop(stack.size() - 1))) {
      if(stack.empty())
	std::abort();
      //std::cout << "pop " << (stack.back() + 1) << "\n";
      stack.pop_back();
      continue;
    }
    //std::cout << "push " << (n+1) << "\n";
    route.push_back(n);
    stack.push_back(n);
    visited[n] = true;

  }
  bool check = false;
  for(int i = 0; i < N; ++i) {
    if(i && codes[route[i-1]] > codes[route[i]])
      check = true;
    cout << codes[route[i]];
  }
  cout << "\n";
  //if(check)
  //  std::cerr << "check case " << currCase << "\n";
}

int main () {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    currCase = i;
    testcase();
  }
	return 0;
}
/* Opgave: C */
