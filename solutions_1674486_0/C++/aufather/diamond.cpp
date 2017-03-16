
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <vector>
#include <list>
#include <unordered_set>
#include <algorithm>

using namespace std;

FILE *ifile, *ofile;

long T;                          // num test cases
long N;

int read_input(const char *fbase="Sample")
{
  char fname[2048];

  // open input file with extension .in
  strncpy(fname, fbase, sizeof(fname) - 5);
  int fbase_idx = strlen(fname);
  strcpy(&fname[fbase_idx], ".in");
  ifile = fopen(fname, "r");
  assert(ifile);

  // open output file with extension .out
  strcpy(&fname[fbase_idx], ".out");
  ofile = fopen(fname, "w");
  assert(ofile);

  // scan the number of test cases
  fscanf(ifile, "%ld", &T);
  return 0;
} /* read_input */

struct TestCase                 // struct to hold one test case
{
  long tc_id;
} TC;

enum Status
{
  FAILURE = -1,
  SUCCESS = 0
};

struct Vertex
{
  bool expBit;
  long name;
  list<long> nbrs; // list of parent classes
  list<long> rbrs; // list of classes that inherit from this one
  Vertex();
};

Vertex::Vertex()
{
  expBit = false;
}

class Graph
{
 private:
  map<long, Vertex> vrtcs;
  bool expBit;

 public:
  Graph();
  long dfsCounter;
  void toggleExpBit();
  void setExplored(Vertex *v);
  bool isExplored(Vertex *v);
  Status addEdge(long tail, long head);
  Status removeEdge(long tail, long head);
  Status addVertex(long name);
  Vertex *getFirstVertex();
  Vertex *getVertex(long name);
  void clear();
};

Graph::Graph()
{
  expBit = false;
}

void Graph::toggleExpBit()
{
  for (map<long, Vertex>::iterator i = vrtcs.begin(); i != vrtcs.end(); ++i) {
    i->second.expBit = false;
  } /* 'i' for loop */
}

void Graph::setExplored(Vertex *v)
{
  v->expBit = true;
}

bool Graph::isExplored(Vertex *v)
{
  return v->expBit;
}

Status Graph::addVertex(long name)
{
  map<long, Vertex>::iterator it = vrtcs.find(name);
  if (it == vrtcs.end()) {
    Vertex vrtx;
    vrtx.name = name;
    vrtcs.insert(make_pair(name, vrtx));
  }
  return SUCCESS;
}

Vertex *Graph::getFirstVertex()
{
  return &vrtcs.begin()->second;
}

Vertex *Graph::getVertex(long name)
{
  map<long, Vertex>::iterator it = vrtcs.find(name);
  if (it == vrtcs.end()) return NULL;
  return &it->second;
}

Status Graph::addEdge(long tail, long head)
{
  Vertex *t, *h;
  t = getVertex(tail);
  if (!t) {
    addVertex(tail);
    t = getVertex(tail);
  }
  assert(tail != head);

  h = getVertex(head);
  if (!h) {
    addVertex(head);
    h = getVertex(head);
  }

  t->nbrs.push_back(head);
  h->rbrs.push_back(tail);

  return SUCCESS;
}

void Graph::clear()
{
  for (map<long, Vertex>::iterator v = vrtcs.begin(); v != vrtcs.end(); ++v) {
    v->second.nbrs.clear();
    v->second.rbrs.clear();
  } /* 'v' for loop */
  vrtcs.clear();

}

int comp(const void *v1, const void *v2)
{
  long *l1 = (long *)v1;
  long *l2 = (long *)v2;
  return *l1 - * l2;
}

//  qsort(board, 512, sizeof(board[0]), comp);

list<long> roots;
Graph g;

int read_test_case(long tc_id)
{
  TC.tc_id = tc_id;
  fscanf(ifile, "%ld", &N);
  g.clear();
  roots.clear();
  long num_classes;
  long cls;
  for (long i = 1; i <= N; ++i) {
    fscanf(ifile, "%ld", &num_classes);
    g.addVertex(i);
    //    printf("%ld", num_classes);
    if (!num_classes) {
      roots.push_back(i);
    }
    for (long j = 0; j < num_classes; ++j) {
      fscanf(ifile, " %ld", &cls);
      //      printf(" %ld", cls);
      g.addEdge(i, cls);
    } /* 'j' for loop */
    fscanf(ifile, "\n");
    //    printf("\n");
  } /* 'i' for loop */

  return 0;
} /* read_test_case */

bool Dfs(long root)
{
  Vertex *v = g.getVertex(root);
  if (v->expBit) return true;
  v->expBit = true;
  for (list<long>::iterator i = v->rbrs.begin(); i != v->rbrs.end(); ++i) {
    if (Dfs(*i)) return true;
  } /* 'i' for loop */
  return false;
}

char *solve(long tc_id)
{
  long strid = 0;
  static char result_str[65535];

  assert(!feof(ifile));
  tc_id++; // increment tc_id so that Case # will start from 1
  read_test_case(tc_id);

  strid += sprintf(&result_str[strid], "Case #%ld: ", tc_id);

  /* SOLVE HERE */
  for (list<long>::iterator lit = roots.begin(); lit != roots.end(); ++lit) {
    g.toggleExpBit();
    if (Dfs(*lit)) {
      strid += sprintf(&result_str[strid], "Yes\n");
      return result_str;
    }
  } /* 'i' for loop */

  strid += sprintf(&result_str[strid], "No\n");

  return result_str;
} /* solve */

int main(int argc, char *argv[])
{
  char *str;
  read_input(argc > 1 ? argv[1] : "Sample");
  for (long i = 0; i < T; ++i) {
    str = solve(i);
    fprintf(ofile, "%s", str);
    fprintf(stderr, "%s", str);
  }
  return 0;
}
