// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

// wersja template'a, w ktorej jest naraz odpalonych
// co najwyzej CORES watkow
// (czasami na loanerach normalna wersja nie dziala dobrze
// bo jest w stanie odpalic np. tylko 5 watkow)





// zast¹piæ tym maina
// wype³niæ readInput(), compute() i writeOutput(); zmienne definiowaæ wewn¹trz klasy Instance
// PARALLEL - czy ma odpaliæ testy równolegle, CORES - liczba rdzeni
// uwaga - wersja równoleg³a mo¿e potrzebowaæ du¿o pamiêci! (T razy wiêcej)
//         mozna sobie z tym poradziæ tworz¹c du¿e tablice dynamicznie dopiero w compute()
//         (bo naraz wykonywane s¹ co najwy¿ej CORES=3 kopie compute())
//         (pamiêtaæ o delete [] na koniec compute)
// linkowaæ z pthreads

#define MAXV 100005
int n,m;
vi adj[MAXV];
int para[MAXV];
bool vis[MAXV];

bool augment (int v) {         // 1 <= v <= n (lub v = -1)
   if (v == -1) return 1;
   if (vis[v]++) return 0;
   FOREACH(x,adj[v]) {
      if (augment(para[*x])) {
          para[*x] = v;
          para[v] = *x;
          return 1;
      }
   }
   return 0;
}

// maximum bipartite matching w czasie O(V * E)
// wierzchołki z pierwszej części mają mieć nry 1..n, z drugiej - n+1..n+m
// przed wywołaniem należy ustawić zmienne: n,m,adj (adj wystarczy mieć wypełnione dla wierzchołków 1..n)
// oraz stałą MAXV = maksymalne n+m

int matching () {
   FORI(i,n+m) para[i] = -1;
   int w = 0;
   FORI(i,n) {
      FORI(j,n) vis[j] = 0;
      w += augment(i);
   }
   return w;
}

#include <pthread.h>
#include <semaphore.h>
#define PARALLEL 0
#define CORES 4
struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   int res;
   
   void readInput() { // should read input; will run sequentially
      int E;
      cin >> E;
      map<string,int> ida, idb;
      int lastida = 0, lastidb = 0;
      vector<pii> edges;
      FOR(u,E) {
         string a, b;
         cin >> a >> b;
         if (!ida.count(a)) {
            ida[a] = ++lastida;
         }
         if (!idb.count(b)) {
            idb[b] = ++lastidb;
         }
         edges.pb({ida[a], idb[b]});
      }
      n = lastida;
      m = lastidb;
      FORI(i,n) adj[i].clear();
      for (auto it : edges) adj[it.fi].pb(it.se + n);
      res = E + matching() - n - m;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      cout << res;
   }
};

Instance *instances;
pthread_mutex_t cerr_lock = PTHREAD_MUTEX_INITIALIZER,
                nextToStartLock = PTHREAD_MUTEX_INITIALIZER;
int tests, finishedTests = 0, nextToStart = 0;
void* runner (void* input) {
   (void)(input); // get rid of warning
   while (1) {
      pthread_mutex_lock(&nextToStartLock);
      int testno = nextToStart++;
      pthread_mutex_unlock(&nextToStartLock);
      if (testno >= tests) return 0;

      //pthread_mutex_lock(&cerr_lock);
      //cerr << "test " << testno+1 << " is starting" << endl;
      //pthread_mutex_unlock(&cerr_lock);
      instances[testno].compute();
      pthread_mutex_lock(&cerr_lock);
      cerr << "test " << testno+1 << " is finished (" << ++finishedTests << "/" << tests << ")" << endl;
      pthread_mutex_unlock(&cerr_lock);
      pthread_mutex_unlock(&instances[testno].finished);
   }
}

int main () {
   string pierwszalinia;
   getline(cin,pierwszalinia);
   tests = atoi(pierwszalinia.c_str());
   if (PARALLEL) {
      instances = new Instance[tests];
      // reading input
      FOR(i,tests) {
         instances[i].readInput();
      }
      
      // running computations in parallel
      pthread_t irrelevant;
      FOR(i,CORES) {
         pthread_create(&irrelevant, NULL, runner, NULL);
      }
      FOR(i,tests) pthread_mutex_lock(&instances[i].finished); // wait until all are finished
      
      // writing output
      FOR(i,tests) {
         printf("Case #%d: ", i+1);
         instances[i].writeOutput();
         printf("\n");
      }
   } else {
      FOR(i,tests) {
         instances = new Instance;
         instances->readInput();
         instances->compute();
         printf("Case #%d: ", i+1);
         instances->writeOutput();
         printf("\n");
         cerr << "test " << i+1 << " is finished (" << ++finishedTests << "/" << tests << ")" << endl;
         delete instances;
      }
   }
}

