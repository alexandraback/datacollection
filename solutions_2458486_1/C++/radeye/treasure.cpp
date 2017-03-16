#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std ;
struct chest {
   int t ;
   char used ;
   vector<int> gk ;
} chests[400] ;
int cnts[256] ;
int crm[256] ;
int conn[256][256] ;
char seen[256] ;
int nv, nuk ;
vector<int> sk ;
int cntt[256] ;
void visit(int at) {
   if (seen[at] == 0 && cntt[at] > 0) {
      seen[at] = 1 ;
      nv += cntt[at] ;
      for (int i=0; i<nuk; i++)
         if (conn[at][i])
            visit(i) ;
   }
}
int N ;
int checkthis() {
   nv = 0 ;
   memset(seen, 0, sizeof(seen)) ;
   for (int i=0; i<sk.size(); i++)
      visit(sk[i]) ;
   return nv ;
}
void one() {
   int K ;
   memset(cnts, 0, sizeof(cnts)) ;
   memset(crm, -1, sizeof(crm)) ;
   memset(cntt, 0, sizeof(cntt)) ;
   scanf("%d %d", &K, &N) ;
   sk.clear() ;
   for (int i=0; i<K; i++) {
      int v ;
      scanf("%d", &v) ;
      sk.push_back(v) ;
      cnts[v]++ ;
   }
   nuk = 0 ;
   for (int i=0; i<N; i++) {
      int T, Ki ;
      scanf("%d %d", &T, &Ki) ;
      vector<int> gk ;
      cnts[T]-- ;
      if (crm[T] < 0)
         crm[T] = nuk++ ;
      for (int j=0; j<Ki; j++) {
         int v ;
         scanf("%d", &v) ;
         gk.push_back(v) ;
         cnts[v]++ ;
      }
      cntt[crm[T]]++ ;
      chests[i].t = T ;
      chests[i].gk = gk ;
      chests[i].used = 0 ;
   }
   for (int i=0; i<256; i++)
      if (cnts[i] < 0) {
         printf(" IMPOSSIBLE\n") ;
         return ;
      }
   memset(conn, 0, sizeof(conn)) ;
   for (int i=0; i<N; i++) {
      int pred = crm[chests[i].t] ;
      for (int j=0; j<chests[i].gk.size(); j++) {
         int succ = crm[chests[i].gk[j]] ;
         if (succ >= 0)
            conn[pred][succ]++ ;
      }
   }
   vector<int> nsk ;
   for (int i=0; i<sk.size(); i++)
      if (crm[sk[i]] >= 0)
         nsk.push_back(crm[sk[i]]) ;
   swap(sk, nsk) ;
   if (checkthis() != N) {
      printf(" IMPOSSIBLE\n") ;
      return ;
   }
   vector<int> r ;
   for (int i=0; i<N; i++) {
      int good = 0 ;
      for (int j=0; j<N; j++) {
         if (chests[j].used)
            continue ;
         int needt = crm[chests[j].t] ;
         int k = 0 ;
         while (k < sk.size() && sk[k] != needt)
            k++ ;
         if (k >= sk.size())
            continue ;
         vector<int> nsk = sk ;
         int lv = nsk[nsk.size()-1] ;
         nsk[k] = lv ;
         nsk.pop_back() ;
         for (int k=0; k<chests[j].gk.size(); k++) {
            int succ = crm[chests[j].gk[k]] ;
            if (succ >= 0) {
               nsk.push_back(succ) ;
               conn[needt][succ]-- ;
 if (conn[needt][succ] < 0) {
   fprintf(stderr, "Impossible  %d %d %d\n", needt, succ, conn[needt][succ]) ;
 }
            }
         }
         cntt[needt]-- ;
         chests[j].used = 1 ;
         swap(sk, nsk) ;
         good = (checkthis() + r.size() + 1 == N) ;
         if (good) {
            r.push_back(j+1) ;
            break ;
         } else {
            swap(sk, nsk) ;
            chests[j].used = 0 ;
            for (int k=0; k<chests[j].gk.size(); k++) {
               int succ = crm[chests[j].gk[k]] ;
               if (succ >= 0)
                  conn[needt][succ]++ ;
            }
            cntt[needt]++ ;
         }
      }
      if (good == 0) {
         printf(" IMPOSSIBLE\n") ;
         fprintf(stderr, "No good\n") ;
         return ;
      }
   }
   for (int i=0; i<r.size(); i++)
      printf(" %d", r[i]) ;
   printf("\n") ;
}
int main(int argc, char *argv[]) {
   int kases ;
   scanf("%d", &kases) ;
   for (int kase=1; kase<=kases; kase++) {
      printf("Case #%d:", kase) ;
      one() ;
   }
}
