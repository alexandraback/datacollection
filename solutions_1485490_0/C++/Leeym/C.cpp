// Yen-Ming Lee <leeym@leeym.com>
// http://code.google.com/codejam/contest/dashboard?c=1781488#s=p2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <deque>
#include <map>
using namespace std;
typedef unsigned long long int ullint;
int verbose = 0, debug = 0;
struct product {
  ullint num;
  ullint type;
  product(ullint n, ullint t): num(n), type(t) {}
};

ullint plan(deque<product>box, deque<product>toy, int I = 0)
{
  if (box.empty() || toy.empty())
    return 0;
  ullint r = 0;
  if (verbose) {
    for (int i = 0; i < I; i++)
      fprintf(stderr, "\t");
    fprintf(stderr, "box.front().num:%llu box.front().type:%llu toy.front().num:%llu toy.front().type:%llu\n", box.front().num, box.front().type, toy.front().num, toy.front().type);
  }
  // types match, put toy into box
  if (box.front().type == toy.front().type) {
    ullint m = min(box.front().num, toy.front().num);
    if (verbose) {
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "types match, send %llu toy of type %llu in box\n", m, toy.front().type);
    }
    r += m;
    box.front().num -= m;
    if (box.front().num == 0) {
      box.pop_front();
    }
    toy.front().num -= m;
    if (toy.front().num == 0) {
      toy.pop_front();
    }
  }
  if (verbose) {
    for (int i = 0; i < I; i++)
      fprintf(stderr, "\t");
    fprintf(stderr, "box.front().num:%llu box.front().type:%llu toy.front().num:%llu toy.front().type:%llu\n", box.front().num, box.front().type, toy.front().num, toy.front().type);
  }
  if (verbose) {
    for (int i = 0; i < I; i++)
      fprintf(stderr, "\t");
    fprintf(stderr, "r:%llu\n", r);
  }
  if (box.empty() || toy.empty())
    return r;
  if (box.front().type == toy.front().type) {
    return r + plan(box, toy);
  } else {
    // save box, throw it, plan accordingly
    if (verbose) {
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "throw box\n");
    }
    product bb = box.front();
    box.pop_front();
    ullint rb = plan(box, toy, I + 1);
    if (verbose) {
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "rb:%llu\n", rb);
    }


    // put box back, throw toy, and plan again
    if (verbose) {
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "throw toy\n");
    }
    box.push_front(bb);
    toy.pop_front();
    ullint rt = plan(box, toy, I + 1);
    if (verbose) {
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "rt:%llu\n", rt);
      for (int i = 0; i < I; i++)
        fprintf(stderr, "\t");
      fprintf(stderr, "r:%llu rb:%llu rt:%llu\n", r, rb, rt);
    }

    return r + max(rb, rt);
  }
}
int main(int argc, char *argv[])
{
  int ch;
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
    fprintf(stderr, "Case #%d/%d\n", t, T);
    deque< product >box;
    deque< product >toy;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      ullint a, A;
      cin >> a >> A;
      box.push_back(product(a, A));
    }
    for (int i = 0; i < M; i++) {
      ullint b, B;
      cin >> b >> B;
      toy.push_back(product(b, B));
    }
    ullint r = plan(box, toy);
    printf("Case #%d: %llu\n", t, r);
  }
}
