#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

#define Size(x) (int(x.size()))

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int scanerr;

int getNum() {
#ifdef LINEBYLINE
  string s = getLine();
  return atoi(s.c_str());
#else
  int i;
  scanerr = scanf("%d", &i);
  return i;
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

int bff[2000];
     
int cknown[2000];

vector<int> cycend;

vector<pair<int, int> > pairs;

int ccode=0;

int N;

int bestTail(int i, int j) {
  int bt = 0;
  for(int k=0; k<N; k++) {
    ccode++;
    int tlen = 0;
    int at = k;
    while(cknown[at] != ccode) {
      cknown[at] = ccode;
      at = bff[at];
      tlen++;
      }
    tlen -= 2;
    if(at == i && tlen > bt) bt = tlen;
    }
  // printf("tail (%d) = %d\n", i, bt);
  return bt;
  }

void solveCase() {
  int res = 0;

  N = getNum();
  
  for(int i=0; i<N; i++) bff[i] = getNum() - 1;

  for(int i=0; i<N; i++) cknown[i] = 0;
  cycend.clear(); pairs.clear();
  
  for(int i=0; i<N; i++) if(!cknown[i]) {
    ccode++;
    int j = i;
    while(!cknown[j]) {
      cknown[j] = ccode;
      j = bff[j];
      }
    if(cknown[j] == ccode) cycend.push_back(j);
    }
  
  pair<int, int> bestcycle;
  
  for(int at: cycend) {
    int j = at, len = 0;
    do {
      j = bff[j]; len++;
    } while(j != at);
    auto p = make_pair(len, at);
    if(p > bestcycle) bestcycle = p;
    }
  
  int solution;
  
  for(int i=0; i<N; i++) {
    int j = bff[i];
    if(bff[j] == i && j > i) {
      solution += bestTail(i,j);
      solution += bestTail(j,i);
      solution += 2;
      }
    }
  
  int best = max(solution, bestcycle.first);
  
  // printf("ssol = %d, bestcycle = %d\n", solution, bestcycle.first);
  
  printf("Case #%d: %d\n", cnum, best);
  }

#define P 1000000007

int main() {

  if(!MANYTESTS) Tests = 1;
  else Tests = getNum();
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
