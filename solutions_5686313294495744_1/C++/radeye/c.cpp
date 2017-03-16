#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
const int BIG = 1000000000 ;
const int MAXN = 3000 ;
int prevn[MAXN], minv[MAXN] ;
int mincostflow(int n, int *g[], int *cost[], int *flow[]) {
   int totflow = 0 ;
   while (true) {
      for (int i=0; i<n; i++) {
         prevn[i] = -1 ;
         minv[i] = BIG ;
      }
      minv[0] = 0 ;
      while (1) {
         bool changed = false ;
         for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
               if (flow[i][j] < g[i][j] && minv[j] > minv[i] + cost[i][j]) {
                  changed = true ;
                  minv[j] = minv[i] + cost[i][j] ;
                  prevn[j] = i ;
               }
            }
         if (!changed)
            break ;
      }
      if (minv[n-1] == BIG)
         return totflow ;
      int maxflow = BIG ;
      int j ;
      for (int i=n-1; (j=prevn[i])>=0; i=j)
         maxflow = min(maxflow, g[j][i] - flow[j][i]) ;
      totflow += maxflow ;
      for (int i=n-1; (j=prevn[i])>=0; i=j) {
         flow[j][i] += maxflow ;
         flow[i][j] -= maxflow ;
      }
   }
}
int *g[MAXN] ;
int *cost[MAXN] ;
int *flow[MAXN] ;
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int i=0; i<MAXN; i++) {
     g[i] = (int *)calloc(MAXN, sizeof(int)) ;
     cost[i] = (int *)calloc(MAXN, sizeof(int)) ;
     flow[i] = (int *)calloc(MAXN, sizeof(int)) ;
   }
   for (int kase=1; kase<=K; kase++) {
      ll r = 33 ;
      map<string, int> left, right ;
      vector<int> lfti, rghti ;
      int n ;
      cin >> n ;
      for (int i=0; i<n; i++) {
	string a, b ;
	cin >> a >> b ;
	if (left.find(a) == left.end())
	  left[a] = left.size() ;
	if (right.find(b) == right.end())
	  right[b] = right.size() ;
	lfti.push_back(left[a]) ;
	rghti.push_back(right[b]) ;
      }
      int gn = left.size() + right.size() + 2 ;
      for (int i=0; i<gn; i++) for (int j=0; j<gn; j++) {
	  g[i][j] = 0 ;
	  cost[i][j] = 0 ;
	  flow[i][j] = 0 ;
	}
      int lftsize = left.size() ;
      int rghtsize = right.size() ;
      for (int i=0; i<lftsize; i++)
	g[0][i+1] = 1 ;
      for (int i=0; i<rghtsize; i++)
	g[1+lftsize+i][gn-1] = 1 ;
      for (int i=0; i<lfti.size(); i++) {
	g[1+lfti[i]][1+lftsize+rghti[i]] = 1 ;
      }
      r = mincostflow(gn, g, cost, flow) ;
      r = lftsize + rghtsize - r ;
      r = n - r ;
      cout << "Case #" << kase << ": " << r << endl ;
   }
}
