#include <iostream>
#include <vector>
using namespace std;

#define LIM 1003
#define MOD
#define INF

typedef long long int ll;
typedef vector<int> vi;

vi adj_list[LIM];
int dists[LIM];
int marked[LIM];
int N;
int bffs[LIM];

int findCycle(int vertex) {
  int next = bffs[vertex];
  int count = 1;
  while(next != vertex) {
    if(count > N) {
      return -1;
    }
    next = bffs[next];
    count++;    
  }
  return count;
}

int makeDistsTree(int vertex) {
  int curr = 0;
  marked[vertex] = 1;
  for(auto it = adj_list[vertex].begin(); it != adj_list[vertex].end(); it++) {
    if(marked[*it] == 1) continue;
    curr = max(curr, makeDistsTree(*it) + 1);
  }
  dists[vertex] = curr;
  return curr;
}

int getChainLength(int vertex) {
  int dost = bffs[vertex];
  int i;
  for(i = 1; i <= N; i++) {
    dists[i] = 0;
    marked[i] = 0;
  }
  makeDistsTree(dost);
  int ret = dists[vertex];
  //cout << "p1=" << ret << endl;
  for(i = 1; i <= N; i++) {
    dists[i] = 0;
    marked[i] = 0;
  }
  makeDistsTree(vertex);
  int temp = dists[dost];
  //cout << "p2=" << temp << endl;
  ret += dists[dost];
  ret += 2;
  return ret;
  
}

void work(int index) {
  cin >> N;
  int i;
  int temp;
  for(i = 1; i <= N; i++) {
    adj_list[i].clear();
  }
  for(i = 1; i <= N; i++) {
    cin >> temp;
    bffs[i] = temp;
    adj_list[temp].push_back(i);
  }

  int longest_cycle = 0;
  int chains = 0;
  int temp_chain;
  for(i = 1; i <= N; i++) {
    temp = findCycle(i);
    if(temp > longest_cycle) longest_cycle = temp;
    if(temp == 2) { // can make a chain here
      temp_chain = getChainLength(i);
      //cout << "getChainLength(" << i << ") = " << temp_chain << endl;
      chains += temp_chain;
    }
    
  }

  chains /= 2;

  int ans = max(chains, longest_cycle);

  cout << "Case #" << index << ": ";
  cout << ans;
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
