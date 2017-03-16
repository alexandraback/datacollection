#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int T;

int main() {
    //freopen("x.in", "r", stdin);

  freopen("B-small-attempt2.in", "r", stdin);
  freopen("B-small-attempt2.out", "w", stdout);
  //freopen("B-example.in", "r", stdin);
  //freopen("B-example.out", "w", stdout);

  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);

  cin >> T;

  F1(t,T) {
    //cerr << tt << endl;
    int B, M;
    cin >> B >> M;

    bool possible = true;
    int b[50][50];
    F0(i, 50) {
      F0(j, 50) {
        b[i][j] = 0;
        if (j > i) {
          b[i][j] = 1;
        }
      }
    }

    int rest = M;
    int bits2[100];
    F0(i, 100) {
        bits2[i] = 0;
    }
    F0(i, 100) {
      if (M % 2 == 1) {
        bits2[i] = 1;
        // cout  << " bit " <<i  << endl;
        if (i >= B-1) {
          possible = false;
          cout << "Case #" << t << ": IMPOSSIBLE" << endl;
          break;
        }
      }
      M = M / 2;
    }
    if(!possible) continue;

    int lastbit = 0;
    F0(i, B+1) {
      int newlastbit = bits2[i];
      bits2[i] = lastbit;
      lastbit = newlastbit;
    }
    /*F0(i, B) {
      cout << bits2[i] << " ";
    }
    cout << endl;*/
    if (bits2[B-1] == 1) {
      F0(i, B-1) {
        if (bits2[i] == 1) {
          possible = false;
          cout << "Case #" << t << ": IMPOSSIBLE" << endl;
          break;
        }
      }
      if (possible) {
          F1(i, B-1) {
            bits2[i-1] = 1;
          }
          bits2[B-1] = 0;
      }
      /*F0(i, B) {
        cout << bits2[i] << " ";
      }
      cout << endl;*/
    }
    if(!possible) continue;

    F0(i, B) {
      //cout << i << " " << bits2[i] << (B-i) << endl;
      b[0][B-1-i] = bits2[i];
    }
    if (b[0][0] == 1) {
      cout << "Case #" << t << ": IMPOSSIBLE" << endl;
      continue;
    }
    b[0][0] = 0;

    cout << "Case #" << t << ": POSSIBLE" << endl;
    F0(i, B) {
      //cout << bits2[i] << " ";
      F0(j, B) {
        cout << b[i][j];
      }
      cout  << endl;
    }

  }
  return 0;
}
