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
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

ll nwd (ll a, ll b) {
   if (b==0) return a;
   return nwd(b, a%b);
}

struct Frac {
   int p,q;
   void normalize () {
      int g = nwd(p,q);
      p /= g;
      q /= g;
   }
   Frac (int _p = 0, int _q = 1) : p(_p), q(_q) { normalize(); }
   inline bool operator < (const Frac &f) const {
      return (ll)p * f.q < (ll)q * f.p;
   }
   inline bool operator == (const Frac &f) const {
      return (ll)p * f.q == (ll)q * f.p;
   }
   double dbl () const {
      return (double)p/q;
   }
};
ostream& operator << (ostream &s, const Frac &f) {
   return s << f.p << "/" << f.q;
}

inline bool has (int mask, int pr) {
   return (pr & mask) == pr;
}

struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   int n;
   int s[10], p[10], startlane[10];
   bool respossible;
   Frac res;
   
   void readInput() { // should read input; will run sequentially
      cin >> n;
      char c;
      FOR(i,n) {
         cin >> c >> s[i] >> p[i];
         startlane[i] = (c == 'R');
      }
      //cerr << endl << endl;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      vector<pair<Frac, pair<bool, pii> > > events;
      FOR(i,n) FOR(j,i) {
         if (s[i] == s[j]) {
            //DBG(mp(i,j))
            //DBG(p[j])
            //DBG(p[i])
            if (p[j] < p[i]+5 && p[i] < p[j]+5) {
               //DBG(mp(i,j))
               events.pb(mp(Frac(), mp(0, mp(i,j))));
               //events.pb
            }
            continue;
         }
         int faster = s[i] > s[j] ? i : j, slower = i+j-faster;
         if (p[faster] >= p[slower]+5) continue;
         Frac from;
         if ((p[slower] - p[faster] - 5) > 0) {
            from = Frac((p[slower] - p[faster] - 5),(s[faster] - s[slower]));
         }
         Frac to(p[slower] + 5 - p[faster], s[faster] - s[slower]);
         events.pb(mp(from, mp(0, mp(slower,faster))));
         events.pb(mp(to, mp(1, mp(slower,faster))));
      }
      sort(ALL(events));
      //DBG(events)
      
      bool possibleState[1<<6], newPossibleState[1<<6];
      FOR(mask,1<<6) possibleState[mask] = 0;
      int startingMask = 0;
      FOR(i,n) startingMask |= startlane[i] * (1 << i);
      possibleState[startingMask] = 1;
      //DBG(startingMask)
      
      vi forbiddenPairs;
      for (int i = 0; i < SZ(events); ) {
         int start = i;
         while (i < SZ(events) && events[i].fi == events[start].fi) ++i;
         // [start, i)
         //DBG(start)DBG(i)
         REP(j,start,i-1) {
            //DBG(j)
            //DBG(events[j])
            int pairMask = (1 << events[j].se.se.fi) | (1 << events[j].se.se.se);
            if (events[j].se.fi) {
               // erase
               if (find(ALL(forbiddenPairs),pairMask) == forbiddenPairs.end()) {
                  DBG(pairMask)
                  //exit(1);
               }
               forbiddenPairs.erase(find(ALL(forbiddenPairs),pairMask));
            } else {
               forbiddenPairs.pb(pairMask);
            }
         }
         //DBG(forbiddenPairs)
         FOR(mask,1<<n) {
            newPossibleState[mask] = 0;
            int antiMask = (1<<n) - 1 - mask;
            bool wrong = 0;
            FOREACH(pr,forbiddenPairs) if (has(mask,*pr) || has(antiMask,*pr)) { wrong = 1; break; }
            if (wrong) continue;
            
            FOR(prevMask,1<<n) if (possibleState[prevMask]) {
               int xorMask = mask ^ prevMask;
               bool wrong = 0;
               FOREACH(pr,forbiddenPairs) if (has(xorMask,*pr)) { wrong = 1; break; }
               if (wrong) continue;
               newPossibleState[mask] = 1;
            }
         }
         bool something = 0;
         FOR(mask,1<<n) {
            possibleState[mask] = newPossibleState[mask];
            if (possibleState[mask]) something = 1;
         }
         if (!something) {
            //cerr << "Giving up...";
            res = events[start].fi;
            respossible = 0;
            return;
         }
      }
      
      respossible = 1;
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      if (respossible) cout << "Possible";
      else cout << fixed << setprecision(9) << res.dbl();
   }
};

Instance *instances;
sem_t coreSemaphore;
pthread_mutex_t cerr_lock = PTHREAD_MUTEX_INITIALIZER;

void* runner (void* input) {
   int testno = *reinterpret_cast<int*>(input);
   sem_wait(&coreSemaphore);
   instances[testno].compute();
   pthread_mutex_lock(&cerr_lock);
   cerr << "test " << testno+1 << " is finished" << endl;
   pthread_mutex_unlock(&cerr_lock);
   pthread_mutex_unlock(&instances[testno].finished);
   sem_post(&coreSemaphore);
   return 0;
}

int main () {
   string pierwszalinia;
   getline(cin,pierwszalinia);
   int tests = atoi(pierwszalinia.c_str());
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
         cerr << "test " << i+1 << " is finished" << endl;
         delete instances;
      }
   }
}
