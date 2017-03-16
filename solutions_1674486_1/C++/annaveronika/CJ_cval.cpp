#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("A-large.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

struct Node {
  Node() : seen( false ) {}

  vector<int> edges;
  bool seen;
};

struct Graph {
  int nodesCount;
  vector<Node> nodes;
};

Graph* input() {
  Graph* g = new Graph;
  cin >> g->nodesCount;
  g->nodes.resize(g->nodesCount);

  for(int i = 0 ; i < g->nodesCount; i++ ) {
    int parentCount;
    cin >> parentCount;
    g->nodes[i].edges.resize(parentCount);

    for( int p = 0; p < parentCount; p++ ) {
      int nodeNumber;
      cin >> nodeNumber;
      g->nodes[i].edges[p] = nodeNumber - 1;
    }
  }
  return g;
}

void Input( vector<Graph*>& v ) {
  int count;
  cin >> count;
  v.resize(count);

  for(int i = 0 ; i < count; i++ ) {
    v[i] = input();;
  }
}

bool dfs(Graph& g, int nodeIndex) {
  if(g.nodes[nodeIndex].seen)
    return true;
  g.nodes[nodeIndex].seen = true;

  for(int i = 0; i < g.nodes[nodeIndex].edges.size(); i++) {
    int next = g.nodes[nodeIndex].edges[i];
    if( dfs(g, next) )
      return true;
  }

  return false;
}

void dfsClean(Graph& g, int nodeIndex) {
  g.nodes[nodeIndex].seen = false;
  for(int i = 0; i < g.nodes[nodeIndex].edges.size(); i++) {
    int next = g.nodes[nodeIndex].edges[i];
    dfsClean(g, next);
  }
}

string Analyse( Graph& g ) {
  vector<bool> isLeaf(g.nodes.size(), true);
  for( int i = 0; i < g.nodes.size(); i++ ) {
    for( int j = 0; j < g.nodes[i].edges.size(); j++ ) {
      isLeaf[g.nodes[i].edges[j]] = false;
    }
  }

  for( int i = 0; i < isLeaf.size(); i++ ) {
    if( isLeaf[i] ) {
      bool found = dfs(g, i);
      if( found ) {
        return "Yes";
      }
      dfsClean(g, i);
    }
  }

  return "No";
}

int main()
{
  initialize();

   vector<Graph*> input;
   Input( input );

   for( int i = 0; i < input.size(); i++ ) {
    cout << "Case #" << i + 1 << ": " << Analyse( *input[i] ) << endl;
   }

   for( int i = 0; i < input.size(); i++ ) {
    delete input[i];
   }
    
   return 0;
}
