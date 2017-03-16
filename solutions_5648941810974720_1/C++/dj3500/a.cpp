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
const string d[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const vector<pair<char,int> > pairs = {{'W',2}, {'Z',0}, {'G',8}, {'H',3}, {'R',4}, {'O',1},
{'F',5},{'X',6},{'V',7},{'I',9}};
struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   string in, out;
   
   void readInput() { // should read input; will run sequentially
      cin >> in;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      map<char,int> m;
      for (char c : in) m[c]++;
      for (auto it : pairs) {
         char letter = it.fi;
         int digit = it.se;
         int num = m[letter];
         FOR(u,num) out += '0' + digit;
         for (char c : d[digit]) m[c] -= num;
      }
      
      bool all0 = 1;
      for (auto it : m) if (it.se != 0) all0 = 0;
      assert(all0);
      
      sort(ALL(out));
   }
   
   void writeOutput () { // should write stored output, without newline; will run sequentially
      cout << out;
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

