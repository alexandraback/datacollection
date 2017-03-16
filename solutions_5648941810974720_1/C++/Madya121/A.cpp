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

bool cari(char x) {
  for (int i = 0; i < s.size(); i++)
    if (s[i] == x) 
      return true;
  return false;
}

void apus(char x) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == x) {
      s[i] = ' ';
      return;
    }
  }
  return;
}

// MAIN CODE
int main () {
  input("A-large (2).in");
  output("out.txt");
  int t, kasus = 0;
	cin >> t;
	while (t--) {
	  jawaban.clear();
	  cin >> s;
	  
	  while (cari('Z')) {
	    jawaban += "0";
	    
	    apus('Z');
	    apus('E');
	    apus('R');
	    apus('O');
    }
    
    while (cari('W')) {
	    jawaban += "2";
	    
	    apus('T');
	    apus('W');
	    apus('O');
    }
    
    while (cari('X')) {
	    jawaban += "6";
	    
	    apus('S');
	    apus('I');
	    apus('X');
    }
    
    while (cari('G')) {
	    jawaban += "8";
	    
	    apus('E');
	    apus('I');
	    apus('G');
	    apus('H');
	    apus('T');
    }
	  
	  while (cari('T')) {
	    jawaban += "3";
	    
	    apus('T');
	    apus('H');
	    apus('R');
	    apus('E');
	    apus('E');
    }
    
    while (cari('R')) {
	    jawaban += "4";
	    
	    apus('F');
	    apus('O');
	    apus('U');
	    apus('R');
    }
    
    while (cari('O')) {
	    jawaban += "1";
	    
	    apus('O');
	    apus('N');
	    apus('E');
    }
    
    while (cari('F')) {
	    jawaban += "5";
	    
	    apus('F');
	    apus('I');
	    apus('V');
	    apus('E');
    }
    
    while (cari('S')) {
	    jawaban += "7";
	    
	    apus('S');
	    apus('E');
	    apus('V');
	    apus('E');
	    apus('N');
    }
    
    while (cari('N')) {
	    jawaban += "9";
	    
	    apus('N');
	    apus('I');
	    apus('N');
	    apus('E');
    }
	  
	  sort(jawaban.begin(), jawaban.end());
	  cout << "Case #" << ++kasus << ": " << jawaban << endl;
  }
  return 0;
}

