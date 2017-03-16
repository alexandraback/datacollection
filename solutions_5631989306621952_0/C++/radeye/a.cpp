#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
      string s ;
      cin >> s ;
      int n = s.size() ;
      char *used = new char[n] ;
      for (int i=0; i<n; i++)
	used[i] = 0 ;
      string s2 ;
      int op = n-1 ;
      while (1) {
	int p = op ;
	for (int i=op; i>=0; i--)
	  if (!used[i] && s[i] > s[p])
	    p = i ;
	if (p <= 0)
	  break ;
	s2.push_back(s[p]) ;
	used[p] = 1 ;
	op = p - 1 ;
      }
      for (int i=0; i<n; i++)
	if (!used[i])
	  s2.push_back(s[i]) ;
      cout << "Case #" << kase << ": " << s2 << endl ;
      delete[] used ;
   }
}
