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
#include <fstream>
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

vector<string> dict[15];
void readdict () {
   ifstream in("garbled_email_dictionary.txt");
   string x;
   while (in >> x) {
      dict[SZ(x)].pb(x);
   }
   FOR(u,15) sort(ALL(dict[u]));
   int ma = 0;
   FOR(u,15) REMAX(ma,SZ(dict[u]));
   DBG(ma);
}
/*
vector<pair<string,pii> > dict;
void readdict () {
   ifstream in("garbled_email_dictionary.txt");
   string x;
   ll cnt = 0;
   while (in >> x) {
      //dict.pb(mp(x,mp(-1,-1))); // real
      ++cnt;
      for (int i = 0; i < SZ(x); ++i) {
         REP(z,'a','y') ++cnt;
         //string y = x;
         //y[i] = 
      }
      
      for (int i = 0; i < SZ(x); ++i) {
         for (int j = i+5; j < SZ(x); ++j) {
            REP(z,'a','y') REP(y,'a','y') ++cnt;
         }
      }
   }
   DBG(cnt);
}
*/

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
#define PARALLEL 1
#define CORES 3
struct Instance {
   pthread_mutex_t finished;
   Instance() : finished(PTHREAD_MUTEX_INITIALIZER) { pthread_mutex_lock(&finished); }
   
   // define variables here
   string s;
   int res;
   int dp[4096][5];
   
   void readInput() { // should read input; will run sequentially
      cin >> s;
   }
   
   void compute() { // should produce output and store it, not use IO; will run in parallel
      FOR(k,5) dp[0][k] = 0;
      int n = SZ(s);
      REP(i,1,n) {
         FOR(k,5) dp[i][k] = INF;
         for (int d = 1; d <= 10 && d <= i; ++d) {
            // i-d+1 .. i, dlugosc d
            
            for (vector<string>::const_iterator x = dict[d].begin(); x != dict[d].end(); ++x) {
               int diffs = 0, mindiff = -1, maxdiff;
               for (int j = i-d+1; j <= i && diffs <= 2; ++j) {
                  if ((*x)[j-i+d-1] != s[j-1]) {
                     if (mindiff == -1) mindiff = j;
                     maxdiff = j;
                     ++diffs;
                  }
               }
               if (diffs <= 2) {
                  if (diffs == 0) {
                     //for (int needK = 0, giveK = min(4,d); giveK <= 4; ++needK, ++giveK) {
                     //   
                     //}
                     FOR(giveK,5) REMIN(dp[i][giveK], dp[i-d][max(0,giveK-d)]);
                  } else if (diffs == 1 || (diffs == 2 && maxdiff - mindiff >= 5)) {
                     int needK = max(0, 4 - mindiff + i-d+1);
                     int giveK = min(4, i - maxdiff);
                     REMIN(dp[i][giveK], dp[i-d][needK] + diffs);
                  }
               }
            }
         }
         REPD(k,3,0) REMIN(dp[i][k], dp[i][k+1]);
      }
      res = dp[n][0];
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
   readdict();
   
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
