#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

typedef long long ll;

#define LS <
#define Size(x) (int(x.size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)

string llts(ll x) {char buf[30]; sprintf(buf, "%lld", x); return buf;}

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

int rect[60][60];

bool haverow[60], havecol[60], havewhat[200];

vector<vector<int> > v;  
int N;

void placerow(int y, int z) {
  for(int x=0; x<N; x++) rect[y][x] = v[z][x];
  haverow[y] = true; havewhat[z] = true;
  }

void placecol(int y, int z) {
  for(int x=0; x<N; x++) rect[x][y] = v[z][x];
  havecol[y] = true; havewhat[z] = true;
  }

void solveCase() {
  int res = 0;

  N = getNum();
  
  v.clear();
  
  for(int y=0; y<N; y++) for(int x=0; x<N; x++)
    rect[y][x] = 0,
    haverow[y] = havecol[x] = false;
  
  for(int y=0; y<2*N-1; y++) havewhat[y] = false;
  
  for(int y=0; y<2*N-1; y++) {
    vector<int> lin;
    for(int x=0; x<N; x++) lin.push_back(getNum());
    v.push_back(lin);
    }
  
  int tlow = 3000, thi = 0;
  for(int y=0; y<2*N-1; y++) for(int x=0; x<N; x++) {
    if(v[y][x] < tlow) tlow = v[y][x];
    else if(v[y][x] > thi) thi = v[y][x];
    }
  
  int qlow=0, qhi=0;
  for(int y=0; y<2*N-1; y++) for(int x=0; x<N; x++) {
    if(v[y][x] == tlow) qlow++;
    if(v[y][x] == thi) qhi++;
    }
  
  if(qlow == 2) {
    for(int y=0; y<2*N-1; y++) for(int x=0; x<N; x++)
      if(v[y][x] == tlow) {
        if(!haverow[0]) placerow(0, y); else placecol(0, y);
        }
    }
  else {
    for(int y=0; y<2*N-1; y++) for(int x=0; x<N; x++)
      if(v[y][x] == thi) {
        if(!haverow[N-1]) placerow(N-1, y); else placecol(N-1, y);
        }
    }
  
  bool fillednow = true;
  
  while(true) {
    if(cnum == 299) {
      FOR(y,0,N) {
        FOR(x,0,N) printf("%4d", rect[y][x]);
        printf(" : %d\n", haverow[y]);
        }
      FOR(x,0,N) printf("#%3d", havecol[x]);
      printf("\n");
      }
    
    bool filledlast = fillednow;
    fillednow = false;
    
    bool stillmissing = false;
    for(int z=0; z<2*N-1; z++) if(!havewhat[z]) {
      int rowid=-1, colid=-1;

      for(int y=0; y<N; y++) if(!haverow[y]) {
        bool goodrow = true;
        for(int x=0; x<N; x++)
          if(rect[y][x] && rect[y][x] != v[z][x])
            goodrow = false;
        if(goodrow) rowid = y;
        }

      for(int y=0; y<N; y++) if(!havecol[y]) {
        bool goodrow = true;
        for(int x=0; x<N; x++)
          if(rect[x][y] && rect[x][y] != v[z][x])
            goodrow = false;
        if(goodrow) colid = y;
        }
      
      // printf("#%d: %d,%d\n", z, rowid, colid);
    
      bool othermissing = false;
/*    int startcount = 0, endcount = 0;
      FOR(z2,0,2*N-1) if(v[z2][0] == v[z][0] && !havewhat[z2]) startcount++;
      FOR(z2,0,2*N-1) if(v[z2][N-1] == v[z][N-1] && !havewhat[z2]) endcount++;
      int atstart = 0, atend = 0;
      FOR(y,0,N) if(rect[y][0] == v[z][0]) atstart++;
      FOR(y,0,N) if(rect[0][y] == v[z][0]) atstart++;
      FOR(y,0,N) if(rect[y][N-1] == v[z][N-1]) atend++;
      FOR(y,0,N) if(rect[N-1][y] == v[z][N-1]) atend++;
      othermissing = (startcount < atstart) && (endcount < atend); */
      
      if(rowid >= 0 && colid >= 0 && (fillednow || filledlast) && !othermissing)
        stillmissing = true;
      else if(rowid >= 0) 
        placerow(rowid, z), fillednow = true;
      else if(colid >= 0)
        placecol(colid, z), fillednow = true;
      else fprintf(stderr, "ERROR\n");
      }
    if(!stillmissing) break;
    }
  
  string str;

  for(int y=0; y<N; y++) if(!haverow[y])
    for(int x=0; x<N; x++) str += " " + llts(rect[y][x]);  
  
  for(int y=0; y<N; y++) if(!havecol[y])
    for(int x=0; x<N; x++) str += " " + llts(rect[x][y]); // ll
  
  printf("Case #%d:%s\n", cnum, str.c_str());
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
