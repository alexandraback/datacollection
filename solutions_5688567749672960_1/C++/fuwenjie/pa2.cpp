#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

ll rev(ll i) {
  ll j = 0;
  while (i > 0) {
    j = j * 10 + i % 10;
    i /= 10;
  }
  return j;
}

vector<ll> a(15);

ll solve(ll n) {
  ll n2 = n;
  if (n <= 10) return n;
  ll n1 = n, k1 = 1;
  int dig = 0;
  while (n1 > 0) {
    n1 /= 10;
    k1 *= 10;
    dig++;
  }
  k1 /= 10;

  ll i = 0, k = 1, tail = 0;
  while (n >= k) {
    i++;
    tail += (n % 10) * k;
    k *= 10;
    n /= 10;
  }
  if (tail == 0) {
    return solve(n2-1) + 1;
  }
  ll rev_head = rev(n);
  if (rev_head == 1) {
    //cerr << "head=1" << endl;
    return a[dig-1] + n2 - k1;
  }
  //cerr << "rev_head=" << rev_head << endl;
  return a[dig-1] + rev_head + 1 + tail - 1;
}

int main()
{
  a[0] = 1;
  a[1] = 10;
  ll klow = 10, khigh = 10;
  for (int i = 2; i <= 14; i++) {
    a[i] = a[i-1] + khigh - 1 + 1 + klow - 1;
    if (klow == khigh) {
      klow *= 10;
    } else {
      khigh *= 10;
    }
    cout << i << ' ' << a[i] << endl;
  }

  int tcase = 0;
  ifstream fin("z.in");
  ofstream fout("z.out");
  fin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    ll n;
    fin >> n;
    fout << "Case #" << tind << ": " << solve(n) << endl;
  }

  return 0;
}
