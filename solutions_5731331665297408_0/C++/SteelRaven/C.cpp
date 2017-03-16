#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef pair < int, stack < int > > State;

vector < string > codes;
vector < vector < int > > gr;

void solve() {
  int n, m;
  cin >> n >> m;
  codes.resize(n);
  gr.resize(0);
  gr.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> codes[i];
  for(int i = 0; i < m; ++i){
    int u, v;
    cin >> u >> v;
    --u; --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  map < State, string > states;
  queue < State > stateQueue;
  queue < string > resultQueue;
  for(int i = 0; i < n; ++i){
    stack < int > tmp;
    tmp.push(i);
    stateQueue.push(make_pair(1 << i, tmp));
    resultQueue.push(codes[i]);
    states[stateQueue.front()] = resultQueue.front();
  }
  while(!stateQueue.empty()){
    State curState = stateQueue.front();
    string curResult = resultQueue.front();
    stateQueue.pop();
    resultQueue.pop();
    if(curState.second.empty()) continue;
    const int curPos = curState.second.top();
    for(size_t i = 0; i < gr[curPos].size(); ++i){
      if((1 << gr[curPos][i]) & curState.first) continue;
      State nextState = curState;
      nextState.first |= 1 << gr[curPos][i];
      nextState.second.push(gr[curPos][i]);
      string nextResult = curResult + codes[gr[curPos][i]];
      auto statePtr = states.find(nextState);
      if(statePtr != states.end() && statePtr->second < nextResult) continue;
      states[nextState] = nextResult;
      stateQueue.push(nextState);
      resultQueue.push(nextResult);
    }
    curState.second.pop();
    auto statePtr = states.find(curState);
    if(statePtr != states.end() && statePtr->second < curResult) continue;
    states[curState] = curResult;
    stateQueue.push(curState);
    resultQueue.push(curResult);
  }
  cout << states[make_pair((1 << n) - 1, stack < int > ())];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; ++test){
    cout << "Case #" << test << ": ";
    solve();
    cout << '\n';
  }
}
