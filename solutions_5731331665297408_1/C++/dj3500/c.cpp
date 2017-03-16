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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);


// zastąpić tym maina
// wypełnić readInput(), compute() i writeOutput(); zmienne definiować wewnątrz klasy Instance
// PARALLEL - czy ma odpalić testy równolegle, CORES - liczba rdzeni
// uwaga - wersja równoległa może potrzebować dużo pamięci! (T razy więcej)
//         mozna sobie z tym poradzić tworząc duże tablice dynamicznie dopiero w compute()
//         (bo naraz wykonywane są co najwyżej CORES=3 kopie compute())
//         (pamiętać o delete [] na koniec compute)
// linkować z pthreads

#include <pthread.h>
#include <semaphore.h>
#define PARALLEL 0
#define CORES 3

vi bfs1 (int n, int source, vi *adj) {
   vi odl(n+1,-1);
   deque<int> q;
   q.pb(source);
   odl[source] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,adj[v]) if (odl[*it] == -1) {
         odl[*it] = odl[v] + 1;
         q.pb(*it);
      }
   }
   return odl;
}

struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   int n;
   vector<vector<bool> > adj;
   string zip[55], res;
   bool seen[55];
   
   void readInput() { // should read input; will run sequentially
      cin >> n;
      int m;
      cin >> m;
      FOR(i,n) cin >> zip[i];
      adj.assign(n, vector<bool>(n, 0));
      FOR(i,n) seen[i] = 0;
      while (m--) {
         int a,b;
         cin >> a >> b;
         a--; b--;
         adj[a][b] = adj[b][a] = 1;
      }
   }
   
   bool allIsReachable (int v, const vector<vector<bool> > &g) {
      vi Adj[55];
      FOR(i,n) FOR(j,n) if (g[i][j]) Adj[i].pb(j);
      vi r = bfs1(n, v, Adj);
      FOR(i,n) if (!seen[i] && -1 == r[i]) return 0;
      return 1;
   }

   vi stack;
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      pair<string,int> mini("99999", INF);
      FOR(i,n) REMIN(mini, mp(zip[i], i));
      int start = mini.se;
      stack.pb(start);
      res += zip[start];
      seen[start] = 1;
      DBG(start)
      FOR(i,n) adj[i][start] = 0;
      FOR(step,n-1) {
         pair<string,int> best("99999", INF);
         REPD(k,SZ(stack)-1,0) {
            FOR(w,n) if (!seen[w] && adj[stack[k]][w]) {
               // wracam do stack[k] i ide do w
               vector<vector<bool> > g = adj;
               FOR(i,n) FOR(j,n) if (adj[i][j]) {
                  g[i][j] = 0;
                  if (!seen[j]) g[i][j] = 1;
               }
               g[w][stack[k]] = 1;
               REP(l,0,k-1) g[stack[l+1]][stack[l]] = 1;
               if (allIsReachable(w,g)) {
                  REMIN(best, mp(zip[w], w));
               }
            }
         }
         
         int w = best.se;
         if (w == INF) {
            cerr << "fail!";
            exit(1);
         }
         //DBG(w)
         REPD(k,SZ(stack)-1,0) if (adj[stack[k]][w]) {
            // wracam do stack[k] i ide do w
            while (k+1 < SZ(stack)) stack.pop_back();
            stack.pb(w);
            res += zip[w];
            seen[w] = 1;
            break;
         }
      }
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      cout << res;
   }
};

Instance *instances;
sem_t coreSemaphore;
pthread_mutex_t cerr_lock = PTHREAD_MUTEX_INITIALIZER;
int tests, finishedTests = 0;

void* runner (void* input) {
   int testno = *reinterpret_cast<int*>(input);
   sem_wait(&coreSemaphore);
   instances[testno].compute();
   pthread_mutex_lock(&cerr_lock);
   cerr << "test " << testno+1 << " is finished (" << ++finishedTests << "/" << tests << ")" << endl;
   pthread_mutex_unlock(&cerr_lock);
   pthread_mutex_unlock(&instances[testno].finished);
   sem_post(&coreSemaphore);
   return 0;
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
      sem_init(&coreSemaphore, 0, CORES);
      pthread_t irrelevant;
      FOR(i,tests) pthread_create(&irrelevant, NULL, runner, new int(i));
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
