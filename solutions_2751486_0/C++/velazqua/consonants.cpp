#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int ll;
typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

bool is_consonant (char c) {
  if (c == 'a' || c == 'e' || c == 'i' ||
      c == 'o' || c == 'u')
    return false;
  return true;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    string word;
    int n;
    cin >> word >> n;
    int size = word.size();
    int curr = 0;
    ulld ans = 0;
    int prev = 0;
    REP(i, size) {
      if (is_consonant(word[i])) {
        ++curr;
        if (curr == n) {
          prev = i-n+1+1;
          ans += prev;
          curr--;
        }
        else {
          ans += prev;
        }
      }
      else {
        curr = 0;
        ans += prev;
      }
    }
    cout << ans << endl;
  }
}
