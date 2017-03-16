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

#include <pthread.h>
#include <semaphore.h>
#define PARALLEL 0
#define CORES 4
struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   string s1, s2;
   pair<string,string> res;
   
   void readInput() { // should read input; will run sequentially
      cin >> s1 >> s2;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      int n = SZ(s1);
      pair<pair<bool,ll>,pair<string,string> > opt[5];
      FOR(a,5) opt[a].fi.fi = 0;
      opt[2].fi = {1,0}; // possible
      
      FOR(i,n) {
         // i digits are done
         //DBG(i);
         pair<pair<bool,ll>,pair<string,string> > nuopt[5];
         FOR(a,5) nuopt[a].fi.fi = 0;
         FOR(d1,10) if (s1[i] == '?' || s1[i] == d1+'0') FOR(d2,10) if (s2[i] == '?' || s2[i] == d2+'0') {
            //DBG(d1)DBG(d2)
            FOR(a,5) if (opt[a].fi.fi) {
               ll nures = opt[a].fi.se * 10 + d1 - d2;
               pair<string,string> nustr = {opt[a].se.fi + char('0' + d1), opt[a].se.se + char('0' + d2)};
               int newA;
               if (nures == 0) {
                  newA = 2;
               } else if (nures == 1) {
                  newA = 3;
               } else if (nures > 1) {
                  newA = 4;
               } else if (nures == -1) {
                  newA = 1;
               } else { assert(nures < -1);
                  newA = 0;
               }
               if (!nuopt[newA].fi.fi || abs(nuopt[newA].fi.se) > abs(nures) || (nuopt[newA].fi.se == nures && nuopt[newA].se > nustr)) {
                  nuopt[newA] = {{1,nures}, nustr};
                  //printf("updating nuopt[%d] with {{1,%lld}, {%s,%s}}\n", newA, nures, nustr.fi.c_str(), nustr.se.c_str());
               }
            }
         }
         FOR(a,5) opt[a] = nuopt[a];
      }
      
      pair<ll,pair<string,string> > best;
      best.fi = INF * 1LL * INF;
      FOR(a,5) if (opt[a].fi.fi) {
         REMIN(best, mp(abs(opt[a].fi.se), opt[a].se));
      }
      res = best.se;
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      cout << res.fi << ' ' << res.se;
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

