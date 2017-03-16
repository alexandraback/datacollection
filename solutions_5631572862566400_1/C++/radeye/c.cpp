#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
char be[1024][1024] ;
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
      int n ;
      cin >> n ;
      vector<int> a ;
      int v ;
      for (int i=0; i<n; i++) {
	cin >> v ;
	a.push_back(v-1) ;
      }
      int r = 0 ;
      memset(be, 0, sizeof(be)) ;
      vector<int> bestselfloops(n) ;
      int nselfloops = 0 ;
      for (int i=0; i<n; i++)
	if (a[a[i]] == i)
	  bestselfloops[min(i, a[i])] = 2 ;
      for (int i=0; i<n; i++) {
	vector<char> used(n) ;
	if (!used[i]) {
	  int c = 0 ;
	  int oj = i ;
	  int je = i ;
	  int j = i ;
	  for (; !used[j]; j = a[j]) {
	    c++ ;
	    used[j] = 1 ;
	    oj = je ;
	    je = j ;
	    if (oj != je && c > be[oj][je]) {
	      be[oj][je] = c ;
	    }
	  }
	  if (j == i && c > r)
	    r = c ;
	  if (a[j] == je && a[je] == j && c > bestselfloops[min(je,j)]) {
	    bestselfloops[min(je,j)] = c ;
	  }
	}
      }
      for (int ep=0; ep<n; ep++) {
	int hp = be[a[ep]][ep] ;
	if (a[a[ep]] == ep && hp > 1) {
	  int op = 0 ;
	  for (int i=0; i<n; i++)
	    if (i != a[ep] && be[i][ep] > op)
	      op = be[i][ep] ;
	  int bb = hp + op - 1 ;
	  if (nselfloops > 2)
	    bb += nselfloops - 2 ;
	  if (op > 1 && bb > bestselfloops[min(ep, a[ep])])
	    bestselfloops[min(ep, a[ep])] = bb ;
	}
      }
      int t = 0 ;
      for (int i=0; i<n; i++)
	t += bestselfloops[i] ;
      if (t > r)
	r = t ;
      /*
      sort(bestselfloops.begin(), bestselfloops.end()) ;
      int two = bestselfloops[bestselfloops.size()-1] +
	bestselfloops[bestselfloops.size()-2] ;
      if (nselfloops > 4)
	two += nselfloops - 4 ;
      if (two > r) {
	r = two ;
      }
      if (nselfloops > r)
	r = nselfloops ;
      */
      cout << "Case #" << kase << ": " << r << endl ;
   }
}
