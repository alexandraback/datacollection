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
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define NEED 4009
#define ld long double
ld nt[NEED+1][NEED+1];

void initnewton () {
   nt[0][0] = 1;
	FORI(n,NEED) nt[n][0] = nt[n-1][0] / 2;
	FORI(k,NEED) nt[0][k] = 0;
	FORI(n,NEED) FORI(k,NEED) nt[n][k] = (nt[n-1][k-1] + nt[n-1][k]) / 2;
}


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
struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   int x,y,n;
   double res;
   
   void readInput() { // should read input; will run sequentially
      cin >> n >> x >> y;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      int d = (abs(x) + abs(y))/2;
      
      int realD = 0, ile = 1;
      while (ile < n) {
         realD++;
         ile += 4*realD + 1;
      }
      
      if (realD < d) {
         res = 0;
         return;
      }

      if (realD > d) {
         res = 1;
         return;
      }
      
      if (n == ile) {
         res = 1;
         return;
      }
      
      if (y == 2*d) { // ?
         res = 0;
         return;
      }
      
      int w = n - ile + 4*d + 1;
      // w in [1, 4d]
      if (w == 4*d) {
         res = 1;
         return;
      }
      // w in [1,4d-1]
      res = 0;
      for (int a = 0, b = w; b >= 0; a++, b--) {
         int ra = a, rb = b;
         if (ra > 2*d) {
            ra = 2*d;
            rb = w - 2*d;
         } else if (rb > 2*d) {
            rb = 2*d;
            ra = w - 2*d;
         }
         if (ra >= y+1) res += nt[w][a];
      }
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      cout << setprecision(9) << fixed << res;
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
   initnewton();
   
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
