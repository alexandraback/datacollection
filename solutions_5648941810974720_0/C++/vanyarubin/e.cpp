#define DE_BUILD

#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <assert.h>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>

using namespace std; using namespace boost;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define found(x,e) (x.find(e) != x.end())
#define FOR(i, n) for(int i=0; i<(int)(n); i++)
#define FORD(i, n) for(int i=(n)-1; i>=0; i--)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef DE_BUILD
#  define DE(...) fprintf(stderr, __VA_ARGS__)
#  define DI FOR(indenti,indent) DE("  ")
#else
#  define DE(...) do {} while (0)
#  define DI do {} while (0)
#endif

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;

// Types
typedef map < char, int > MCI;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef map < int, int > MII;
typedef pair < int, int > PII;
typedef set <PII> SPII;
typedef vector < VI > VVI;
typedef vector<SI> G;
typedef map <int, MCI> MMCI;
void DE_VI(VI v) {
#ifdef DE_BUILD
  FORI(it,v) DE(" %d", *it); DE("\n");
#endif
}

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;
const i64 IMAX = LLONG_MAX;
const u64 UMAX = ULLONG_MAX;
//#include "lib.cpp"

int main(int argc, char** argv);

void solve() {
  const size_t BUFF_SIZE = 2001;
  char buff[BUFF_SIZE];
  //!!!!!!!! fgets(buff, BUFF_SIZE, stdin); // last endline after test case num
  scanf("%s", buff);
  DE("%s\n",buff);
  string s(buff);
  MCI letters;
  FOR(i, s.size()) {
    char c = s[i];
    if(!found(letters,c)) letters[c]=0;
    letters[c]++;
  }
  /*
  MIS digits;
  digits[0] = "ZERO"; //z - 1
  digits[2]="TWO"; //w - 2
  digits[4]="FOUR" ; //u - 3
  digits[6]="SIX"  ; // x - 4
  digits[8]="EIGHT"  ; //g - 5
  digits[3]="THREE";  // t - 6
  digits[1]="ONE"; // o -7
  digits[5]="FIVE"  ; // f - 8
  digits[7]="SEVEN"  ; // - s
  digits[9]="NINE"; // - n
  */
  MII num;
  {
  int d = letters['Z'];
  num[0] = d;
  letters['Z'] -= d;
  letters['E'] -= d;
  letters['R'] -= d;
  letters['O'] -= d;
  }

  {
  int d = letters['W'];
  num[2] = d;
  letters['T'] -= d;
  letters['W'] -= d;
  letters['O'] -= d;
  }

  {
  int d = letters['U'];
  num[4] = d;
  letters['F'] -= d;
  letters['O'] -= d;
  letters['U'] -= d;
  letters['R'] -= d;
  }

  {
  int d = letters['X'];
  num[6] = d;
  letters['S'] -= d;
  letters['I'] -= d;
  letters['X'] -= d;
  }

  {
  int d = letters['G'];
  num[8] = d;
  letters['E'] -= d;
  letters['I'] -= d;
  letters['G'] -= d;
  letters['H'] -= d;
  letters['T'] -= d;
  }

  {
  int d = letters['T'];
  num[3] = d;
  letters['T'] -= d;
  letters['H'] -= d;
  letters['R'] -= d;
  letters['E'] -= d;
  letters['E'] -= d;
  }

  {
  int d = letters['O'];
  num[1] = d;
  letters['O'] -= d;
  letters['N'] -= d;
  letters['E'] -= d;
  }

  {
  int d = letters['F'];
  num[5] = d;
  letters['F'] -= d;
  letters['I'] -= d;
  letters['V'] -= d;
  letters['E'] -= d;
  }

  {
  int d = letters['S'];
  num[7] = d;
  letters['S'] -= d;
  letters['E'] -= d;
  letters['V'] -= d;
  letters['E'] -= d;
  letters['N'] -= d;
  }

  {
  int d = letters['I'];
  num[9] = d;
  letters['N'] -= d;
  letters['I'] -= d;
  letters['N'] -= d;
  letters['E'] -= d;
  }

  FOR(i,num.size()) {
    FOR(j,num[i])
      DE("%d",i);
  }
  DE("\n");
  FOR(i,letters.size()) {
    if(letters[i]) DE("%c %d\n", i, letters[i]);
  }
  FOR(i,letters.size()) {
    assert(letters[i] == 0);
  }
  FOR(i,num.size()) {
    FOR(j,num[i])
      printf("%d",i);
  }
  printf("\n");
  return;
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
