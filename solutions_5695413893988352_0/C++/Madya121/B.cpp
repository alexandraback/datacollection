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

int end, tot;

string toStr(int A) {
  string ret = "";
  while (A > 0) {
    ret.push_back((A % 10) + '0');
    A /= 10;
  }
  
  while (ret.size() < tot) ret.push_back('0');
  
  reverse(ret.begin(), ret.end());
  
  return ret;
}

// MAIN CODE
int main () {
  input("B-small-attempt0.in");
  output("out.txt");
  string s1, s2;
  int t, kasus = 0;
	cin >> t;
	while (t--) {
	  cin >> s1 >> s2;
	  
	  int ans = 1000000000;
	  int ansA = 1000000000, ansB = 1000000000;
	  string jA = "", jB = "";
	  
	  if (s1.size() == 1) end = 10, tot = 1;
	  if (s1.size() == 2) end = 100, tot = 2;
	  if (s1.size() == 3) end = 1000, tot = 3;
	  
	  for (int i = 0; i < end; i++) {
	    string A = toStr(i);
	    bool aha = true;
	    for (int k = 0; k < s1.size(); k++) {
	      if (s1[k] != '?' && s1[k] != A[k]) {
	         aha = false;
	         break;
        }
      }
      if (!aha) continue;
	    
	    
	    for (int j = 0; j < end; j++) {
	      string B = toStr(j);
	      
	      bool bisa = true;
	      for (int k = 0; k < s1.size(); k++) {
	        if (s2[k] != '?' && s2[k] != B[k]) {
	          bisa = false;
	          break;
	        }
        }
        
        if (bisa) {
          if (abs(i - j) < ans) {
            ans = abs(i - j);
            ansA = i;
            ansB = j;
            jA = A;
            jB = B;
          } else if (abs(i - j) == ans) {
            if (i < ansA) {
              ansA = i;
              ansB = j;
              jA = A;
              jB = B;
            } else if (ansA == i) {
              if (j < ansB) {
                ansA = i;
                ansB = j;
                jA = A;
                jB = B;
              }
            }
          }
        }
      }
    }
    
    cout << "Case #" << ++kasus << ": " << jA << " " << jB << endl;
  }
  return 0;
}

