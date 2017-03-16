#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
vector<int> a ;
int n ;
int recur(int used, int first, int prev, int pprev, int sofar) {
  int r = 0 ;
  if (a[prev] == pprev || a[prev] == first)
     r = sofar ;
  for (int i=0; i<n; i++)
    if (((used >> i) & 1) == 0) {
      if (pprev < 0 || a[prev] == i || a[prev] == pprev) {
	int t = recur(used | (1 << i), first < 0 ? i : first, i, prev, sofar+1) ;
	if (t > r)
	  r = t ;
      }
    }
  return r ;
}
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
      a.clear() ;
      cin >> n ;
      int v ;
      for (int i=0; i<n; i++) {
	cin >> v ;
	a.push_back(v-1) ;
      }
      int r = 0 ;
      for (int i=0; i<n; i++) {
	int t = recur((1<<i)|(1<<a[i]), i, a[i], i, 2) ;
	if (t > r)
	  r = t ;
      }
      cout << "Case #" << kase << ": " << r << endl ;
   }
}
