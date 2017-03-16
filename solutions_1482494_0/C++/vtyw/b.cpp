#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//vector<bool> inUse;
bool inUse[10000];
int kSelected[10000];
//vector<int> kSelected;

int T, N;
int a[10000], b[10000];

int n;



int mintries; // best.
bool possible; // wehterh completed once
// LEVEL PROGRESS STUFF
int stars; // stars colelcted
int tries; // levels completed so far

// LEVEL PROGRESS STUFF END

bool is2(int sel) {
  return sel >= N;
}

bool toohard(int sel) {
  return a[sel] > stars;
}




// the win calculation.
void process() {
  if (!possible) {
    mintries = tries;
  }
  else if (tries < mintries)
    mintries = tries;
  possible = true;
  //printf("Min: %d\n", mintries);
  static int count = 0;
  count++;
  //if (count % 10000 == 0)
  //printf("Count: %d\n", count);
}


void pInit() {
  for (int i = 0; i < n; i++) {
    inUse[i] = false;
    kSelected[i] = -99;
  }
}

bool finished(int pos) {
  if (pos == n)
    return true;

  for (int i = 0; i < n; i++) {
    if (!inUse[i])
      return false;
  }
  return true;
}

void gen(int pos) {
  if (pos == 0) { // new order attempt
    stars = 0;
    tries = 0;
  }
  if (finished(pos)) {
    // we've completed everything.

    process();
  }
  else {
    // time to consider what to start the branch at
    // eliminate inferior options e.g. choose 2-star win over 1-star.
    // in fact scout for the best first, all others are equivalent?

    // If best is a1 with 1(0, 2) and same is a2 with 2(0, 3) then which is better?
    // b1 can be done in one go with 2 stars, b2 requires 3 stars. b1 would be used up first, right?
    
    // assume so. This means we go for the easiest ax but when they're all the same have to choose the 
    // ax corresponding to hardest bx so that have chance of claiming the easiest b group in one go.
    /*
    int easy_a = 10000; // easiest a
    int easy_b = 10000;
    int hard_b = 0; // hardest b corresponding to easiest a.

    // loop through B's first.
    for (int i = N; i < n; i++) {
      if (!inUse[i]) { // availablew hcoice
        int req = a[i];
        if (req < easy_b)
          easy_b = req;
      }
    }

    // loop through A's now, find easiest a.
    for (int i = 0; i < N; i++) {
      if (!inUse[i]) {
        int req = a[i];
        if (req < easy_a) {
          easy_a = req;
          // if i can already do it, 
          if (easy_a <= stars) {
            break;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (!inUse[i]) { // availablew hcoice
        int selected = i;
        if (is2(selected)) { // its a b
          int req = a[selected];
          if (req < easy_b) {
            easy_b = req;
          }

          int axreq = a[selected - N];
          if (axreq == 
          if (req > hard_b)
            hard_b = req;

          if (
        }
      }
    }
    */

    for (int i = 0; i < n; i++) {
      if (inUse[i])
        continue;

      // determine if level can be achieved.
      if (toohard(i))
        continue;

      // Optimisation: dont do if
      if (possible && tries >= mintries)
        break;

      // most possible is 2 per tries
      if (possible && n - stars > 2 * (N - tries))
        break;

      // ok do it.

      // if we completed B, then mark the A as occupied. Remember to remove this occupied IF we did that.
      bool doublewin = false;
      kSelected[pos] = i;
      inUse[i] = true;
      if (is2(i) && !inUse[i - N]) {
        inUse[i - N] = true;
        doublewin = true; // completed both A and B.
      }

      int otries = tries;
      int ostars = stars;

      // OK I've selected this path.
      // now calculate stuff.
      tries++;
      if (doublewin) // went from 0 to 2 stars.
        stars += 2;
      else // 1 to 2 stars or 0 to 1.
        stars += 1;

      gen(pos + 1);
      inUse[i] = false;
      if (is2(i) && doublewin) {
        inUse[i - N] = false;
      }

      // remove the stuf I calculated.
      tries = otries;
      stars = ostars;

    }
  }
}



int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N;
    n = 2 * N;
    for (int j = 0; j < N; j++) {
      cin >> a[j] >> b[j];
      a[N + j] = b[j];
    }

    mintries = 2000000000;
    possible = false;
    pInit();
    gen(0);

    if (possible) {


      printf("Case #%d: %d\n", i, mintries);
    }
    else {
      printf("Case #%d: Too Bad\n", i);
    }
  }


}