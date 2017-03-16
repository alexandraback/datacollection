#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define FORE(k,a,b) for(typeof(a) k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define SZ size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define dump(x) cerr << #x << ": " << (x) << endl;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-10;

char mirrors[33][33];
char hr[33][33], vr[33][33], hvr[33][33];
char board[2000][2000];
int T, H, W, D;

void leftright(char src[][33], char dst[][33]) {
  REP(h, H) REP(w, W) {
    dst[h][w] = src[h][W-w-1];
  }
}

void updown(char src[][33], char dst[][33]) {
  REP(h, H) REP(w, W) {
    dst[h][w] = src[H-h-1][w];
  }
}

void display(char mat[][33]) {
  REP(h, H) cerr << mat[h] << endl;
  cerr << "=========================" << endl;
}

void display_board(int height, int width) {
  REP(h, height) {
    REP(w, width) cerr << board[h][w];
    cerr << endl;
  }
  cerr << "=========================" << endl;
}

void copy(int i, int j, char src[][33]) {
  int NH = H - 2, NW = W - 2;
  REP(h, NH) {
    REP(w, NW) {
      board[i*NH + h][j*NW + w] = src[h+1][w+1];
    }
  }
}

void set_origin(int i, int j, int *oh, int *ow) {
  int NH = H - 2, NW = W - 2;
  REP(h, NH) {
    REP(w, NW) {
      if(board[i*NH + h][j*NW + w] == 'X') {
        *oh = i*NH + h;
        *ow = j*NW + w;
        return;
      }
    }
  }
  cerr << "could not found origin X!!!" << endl;
}

int gcd(int a, int b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

void reduce(int &h, int &w) {
  int ah = abs(h), aw = abs(w);
  int g = gcd(max(ah, aw), min(ah, aw));
  //dump(h); dump(w); dump(g);
  h /= g; w /= g;
  // if(h >= 0 && w >= 0 || h < 0 && w < 0) { h = ah/g; w = aw/w; }
  // else if(h < 0 && w >= 0) { h = -ah/g; w = aw/w; }
  // else if(h >= 0 && w < 0) { h = -ah/g; w = aw/w; }
}

int main()
{
  cin >> T;
  REP(ncase, T) {
    cin >> H >> W >> D;
    REP(h, H) cin >> mirrors[h];
    leftright(mirrors, hr);
    updown(mirrors, vr);
    leftright(vr, hvr);

    // display(mirrors);
    // display(hr);
    // display(vr);
    // display(hvr);

    // fill the board
    // int r = 2 * ceil(2*D / min(H-2, W-2)) + 1;
    int r = ceil(D / min(H-2, W-2)) + 1;
    dump(r);
    int oh, ow;
    REP(i, 2*r+1) {
      REP(j, 2*r+1) {
        int pi = (i + r) % 2, pj = (j + r) % 2;
        if(pi == 0 && pj == 0)
          copy(i, j, mirrors);
        else if(pi == 0 && pj == 1)
          copy(i, j, hr);
        else if(pi == 1 && pj == 0)
          copy(i, j, vr);
        else 
          copy(i, j, hvr);
        
        if(i == r && j == r) {
          set_origin(i, j, &oh, &ow);
        }
      }
    }

    int bh = (H-2)*(2*r+1), bw = (W-2)*(2*r+1);
    // display_board(bh, bw);
    // dump(oh); dump(ow);
    
    int res = 0;
    set<PII> pairs;
    REP(h, bh) {
      REP(w, bw) {
        if(board[h][w] != 'X') continue;
        int dist2 = (h-oh)*(h-oh) + (w-ow)*(w-ow);
        if(dist2 > D*D || dist2 == 0) continue;

        int dh = h - oh;
        int dw = w - ow;
        reduce(dh, dw);
        pairs.insert(MP(dh, dw));
      }
    }
    
    dump(pairs.size());
    printf("Case #%d: %d\n", ncase+1, pairs.size());
  }
  
  return 0;
}


// 1
// 4 4 6
// ####
// #.X#
// #..#
// ####
