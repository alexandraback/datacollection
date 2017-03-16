#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>
#include <set>

using namespace std;

typedef pair<string, string> Topic;
typedef pair<int, int> Edge;

struct Case {
  int N;
  vector<Topic> Topics;

  int nextLeft = 0, nextRight = 1050;
  map<string, int> left, right;

  int registerWord(string word, map<string, int> &dict, int &next) {
    if (dict.count(word))
      return dict[word];
    return dict[word] = next++;
  }

  vector<set<int> > Edges;

  vector<char> visited = vector<char>(2500, 0);

  bool breakCycles(int x, int from) {
    visited[x] = true;
    for (int v : Edges[x]) {
      if (v == from) continue;
      if (visited[v]) {
        // found a cycle
        return true;
      }
      if (breakCycles(v, x)) {
        return true;
      }
    }
    visited[x] = false;
    return false;
  }

  int maxFake() {
    int maxfaked = -1;
    for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
      if (bitset<20>(bitmask).count() < maxfaked) {
        continue;
      }
      set<int> leftset, rightset;
      int nfaked = 0;
      for (int j = 0; j < N; j++) {
        if (bitmask & (1 << j)) {
          leftset.insert(left[Topics[j].first]);
          rightset.insert(right[Topics[j].second]);
        } else nfaked++;
      }
      if (leftset.size() == nextLeft && rightset.size() == (nextRight-1050) && nfaked > maxfaked) {
        maxfaked = nfaked;
      }
    }
    return maxfaked;
  }

  int solve() {
    // Edges.resize(2*N+100);
    for (int i = 0; i < N; i++) {
      int x = registerWord(Topics[i].first, left, nextLeft);
      int y = registerWord(Topics[i].second, right, nextRight);
      // Edges[x].insert(y);
      // Edges[y].insert(x);
    }
    // for (int i = 0; i < nextLeft; i++) {
    //   breakCycles(i, -1);
    // }
    return maxFake();
  }
};

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    Case c;
    cin >> c.N;
    c.Topics.resize(c.N);
    for (int j = 0; j < c.N; j++) {
      cin >> c.Topics[j].first >> c.Topics[j].second;
    }
    cout << "Case #" << i << ": " << c.solve() << endl;
  }
  return 0;
}