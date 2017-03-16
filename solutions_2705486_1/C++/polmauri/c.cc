#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef set<int> SET;
typedef SET::iterator Sit;
typedef map<char, int> MAP;
typedef MAP::iterator Mit;
typedef stringstream SS;

struct Node {
  int w;
  MAP next;
  Node() : w(0) {}
};
typedef vector<Node> Vnode;

struct Edge {
  int word_len;
  int mismatches;
  int last_mismatch;
};
typedef vector<Edge> Vedge;

const double EPS = 1e-9;
const int INF = 1000000000;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

Vnode tree;
Vedge edges;
string S;

void insert(const string& s) {
  int n = s.size();
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (tree[t].next.count(s[i])) t = tree[t].next[s[i]];
    else {
      tree.push_back(Node());
      tree[t].next[s[i]] = tree.size() - 1;
      t = tree.size() - 1;
    }
  }
  tree[t].w = 1;
}

void print(int t, string s = "") {
  if (tree[t].w) cout << s << endl;
  for (Mit it = tree[t].next.begin(); it != tree[t].next.end(); ++it)
    print(it->second, s + it->first);
}

void load_dictionary() {
  tree = Vnode(1);
  ifstream f("garbled_email_dictionary.txt");
  string s;
  while (f >> s) insert(s);
}

void compute_edges(int node, int start_pos, int word_len, int last_mismatch, int mismatches) {
  if (tree[node].w) {
    Edge e;
    e.word_len = word_len;
    e.last_mismatch = last_mismatch;
    e.mismatches = mismatches;
    edges.push_back(e);
  }
  
  if (start_pos + word_len >= int(S.size())) return;
  
  for (Mit it = tree[node].next.begin(); it != tree[node].next.end(); ++it) {
    bool mis = S[start_pos + word_len] != it->first;
    if (not mis or last_mismatch == 0) {
      compute_edges(it->second,
                    start_pos,
                    word_len + 1,
                    (mis ? 4 : max(0, last_mismatch - 1)),
                    mismatches + (mis ? 1 : 0));
    }
  }
}

int main() {
  load_dictionary();
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> S;
    int n = S.size();
    
    Mi dist(n + 1, Vi(5, INF));
    dist[0][0] = 0;
    
    priority_queue<PP> pq;
    pq.push(PP(0, P(0, 0)));
    
    int res = -1;
    
    while (not pq.empty()) {
      int dis = -pq.top().first;
      int pos = pq.top().second.first;
      int last = pq.top().second.second;
      pq.pop();
      
      if (dis > dist[pos][last]) continue;
      if (pos == n) {
        res = dis;
        break;
      }
      
//       cerr << "A" << endl;
      
      edges.clear();
      compute_edges(0, pos, 0, last, 0);
      
//       cerr << "B" << endl;
      
      for (int i = 0; i < int(edges.size()); ++i) {
        int next_dis = dis + edges[i].mismatches;
        int next_pos = pos + edges[i].word_len;
        int next_last = edges[i].last_mismatch;
//         cerr << "A1" << endl;
        if (next_dis < dist[next_pos][next_last]) {
          dist[next_pos][next_last] = next_dis;
          pq.push(PP(-next_dis, P(next_pos, next_last)));
        }
//         cerr << "A2" << endl;
      }
    }
    
    cout << "Case #" << cas << ": " << res << endl;
  }
}
