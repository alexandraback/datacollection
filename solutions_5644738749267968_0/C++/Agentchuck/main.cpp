#include <string.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())

#define for0n(i,n) for(i=0;i<n;i++)
#define for1n(i,n) for(i=1;i<=n;i++)
#define forn(i,j,n) for(i=j;i<n;i++)
#define ZERO(arr) for(int CNT=0;CNT<sizeof(arr);CNT++){arr[CNT]=0;}

const int MAX = 1000000;
const int inf = 2100000000;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int moveDir[4][2] = { {0, -1} , {1, 0} , {0, 1} , {-1, 0} }; // N, E, S, W
char dirName[4] = { 'N', 'E', 'S', 'W' };

//ofstream debug("debug.txt", fstream::trunc);

//
// Add variables here.
//
int nCases;
int c, i, j, k, l;
int ans;

uint32_t my32;
uint64_t modArr[3][3];

list<double> naomi;
list<double> ken;

int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

  inFile >> nCases;
  cerr << nCases << " cases." << endl;
  for0n(c,nCases) {
    int N;
    inFile >> N;
    naomi.clear();
    ken.clear();
    double inD;
    for0n(i, N) {
      //inFile >> naomi[i];
      inFile >> inD;
      naomi.push_back(inD);
    }
    for0n(i, N) {
      //inFile >> ken[i];
      inFile >> inD;
      ken.push_back(inD);
    }
    //std::sort(naomi.begin(), naomi.end());
    //std::sort(ken.begin(), ken.end());
    naomi.sort();
    ken.sort();
#if 0
    for0n(i, N) {
      cerr << naomi[i] << " ";
    }
#endif
    // Copy the sorted vectors for the honest run.
    list<double> h_naomi(naomi);
    list<double> h_ken(ken);

    cout << "Case #" << c + 1 << ": " ;

    // Deceit algorithm is:
    // if n_low is lower than k_low then sacrifice to destroy k_high. 
    //   (lie. say weight is just lower than his highest.)
    // - pop front n, pop back k, score unchanged
    // otherwise spend n_low to destroy k_low. (he'll always spend the lowest to lose.)
    // - pop front n, pop front k, score++
    ans = 0;
    for0n(i, N) {
      if (naomi.front() < ken.front()) {
        cerr << "Sac: " << naomi.front() << " to " << ken.back() << endl;
        naomi.pop_front();
        ken.pop_back();
      } else {
        cerr << "Beat: " << naomi.front() << " to " << ken.front() << endl;
        naomi.pop_front();
        ken.pop_front();
        ans++;
      }
    }
    cout << ans << " ";

    cerr << "-- honest --" << endl;
    // Honest algorithm is:
    // n plays highest block. If k can beat it, he will with the lowest block that can do it.
    // otherwise he will play his lowest block.
    ans = 0;
    for0n(i, N) {
      double nPlay = h_naomi.back();
      if (nPlay > h_ken.back()) {
        // Ken can't beat it; he'll play the lowest.
        cerr << "Beat: " << h_naomi.back() << " to " << h_ken.front() << endl;
        h_naomi.pop_back();
        h_ken.pop_front();
        ans++;
      } else {
        list<double>::iterator kenPlayIt = lower_bound(h_ken.begin(), h_ken.end(), nPlay);
        cerr << "Lose: " << h_naomi.back() << " to " << *kenPlayIt << endl;
        h_naomi.pop_back();
        h_ken.erase(kenPlayIt);
      }
    }
    cout << ans << endl;
  }

  outFile.close();
  return 0;
}
