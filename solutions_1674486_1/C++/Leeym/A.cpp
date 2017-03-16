// Yen-Ming Lee <leeym@leeym.com>
// http://code.google.com/codejam/contest/dashboard?c=1781488#s=p0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct Node {
  int value;
  vector<Node *>parent;
  Node(int v): value(v) {}
};
void dfs(Node *t, set<Node *> &visited, bool &found)
{
  if (visited.find(t) != visited.end()) {
    found = true;
    return;
  }
  visited.insert(t);
  for (vector<Node *>::iterator it = t->parent.begin(); it != t->parent.end(); it++) {
    dfs(*it, visited, found);
  }
}
int main(int argc, char *argv[])
{
  int verbose, debug, ch;
  while ((ch = getopt(argc, argv, "vd")) != -1) {
    switch (ch) {
    case 'v':
      verbose = 1;
      break;
    case 'd':
      debug = 1;
      break;
    }
  }
  argc -= optind;
  argv += optind;

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    map<int, Node *>M;
    fprintf(stderr, "Case #%d/%d\n", t, T);
    int N;
    cin >> N;
    if (verbose)
      fprintf(stderr, "there are %d nodes\n", N);
    for (int n = 1; n <= N; n++) {
      int I;
      cin >> I;
      Node *curr = NULL;
      if (M.find(n) != M.end())
        curr = M.find(n)->second;
      else {
        curr = new Node(n);
        M[n] = curr;
      }
      for (int i = 1; i <= I; i++) {
        int p;
        cin >> p;
        if (verbose)
          fprintf(stderr, "\t%d inherits from %d\n", n, p);
        Node *parent;
        if (M.find(p) != M.end())
          parent = M.find(p)->second;
        else {
          parent = new Node(p);
          M[p] = parent;
        }
        curr->parent.push_back(parent);
      }
    }
    bool found = false;
    for (int n = 1; n <= N; n++) {
      Node *head = M.find(n)->second;
      set<Node *>visited;
      dfs(head, visited, found);
      if (found)
        break;
    }
    printf("Case #%d: %s\n", t, found ? "Yes" : "No");
  }
}
