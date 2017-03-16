// INCLUDE LIST
#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// DEFINE LIST
#define REP(_I, _J, _K) for(_I = (_J) ; _I < (_K) ; _I++)
#define input(_A)       freopen(_A, "r", stdin);
#define output(_A)      freopen(_A, "w", stdout);
#define INPUT           input("in.txt");
#define OUTPUT          output("out.txt");
#define CASE_LEFT(_A)   fprintf(stderr, "Cases left: %d\n", _A);
#define hold            {fflush(stdin); getchar();}
#define reset(_A, _B)   memset((_A), (_B), sizeof (_A));
#define debug           printf("<<TEST>>\n");
#define eps             1e-11
#define f_cmp(_A, _B)   (fabs((_A) - (_B)) < eps)
#define phi             acos(-1)
#define pb              push_back
#define value(_A)       cout << "Variabel -> " << #_A << " -> " << _A << endl;
#define st              first
#define nd              second

// TYPEDEF LIST
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       LL;

// VAR LIST
int MAX =               1000000;
int MIN =               -1000000;
int INF =               1000000000;
int x4[4] =             {0, 1, 0, -1};
int y4[4] =             {1, 0, -1, 0};
int x8[8] =             {0, 1, 1,  1,  0, -1, -1, -1};
int y8[8] =             {1, 1, 0, -1, -1, -1,  0,  1};
int i, j, k;

string s, jawaban;

void compute(string ans, string now) {
  if (now.size() > s.size()) {
    return;
  }
  
  if (now.size() == s.size()) {
    sort(now.begin(), now.end());
    if (now == s) {
      jawaban = ans;
    }
    return;
  }
  
  compute(ans + "0", now + "ZERO");
  compute(ans + "1", now + "ONE");
  compute(ans + "2", now + "TWO");
  compute(ans + "3", now + "THREE");
  compute(ans + "4", now + "FOUR");
  compute(ans + "5", now + "FIVE");
  compute(ans + "6", now + "SIX");
  compute(ans + "7", now + "SEVEN");
  compute(ans + "8", now + "EIGHT");
  compute(ans + "9", now + "NINE");
  
  return;
}

// MAIN CODE
int main () {
  input("A-small-attempt0.in");
  output("out.txt");
  int t, kasus = 0;
	cin >> t;
	while (t--) {
	  cin >> s;
	  sort(s.begin(), s.end());
	  compute("", "");
	  sort(jawaban.begin(), jawaban.end());
	  cout << "Case #" << ++kasus << ": " << jawaban << endl;
  }
  return 0;
}

