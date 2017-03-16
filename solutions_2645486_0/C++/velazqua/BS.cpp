#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int ll;
typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    int E, R, N;
    cin >> E >> R >> N;
    vector<int> V(N, 0);
    REP(i, N)
      cin >> V[i];
    map<int, int> M;
    M[E] = 0;
    REP(i, N) {
      //cout << "index: " << i << endl;
      map<int, int> temp(M);
      for(map<int, int>::iterator it = M.begin();
          it != M.end();
          it++) {
        //cout << "it->first: " << it->first << ". it->second: " << it->second << endl;
        FOR(e, 0, it->first+1) {
          // if i pick e items
          int available = it->first-e+R;
          if (available > E)
            available = E;
          int num = e*V[i]+it->second;
          //cout << "a: " << available << ". num: " << num << ". e: " << e << endl;
          //cout << "M[a]: " << temp[available] << endl;
          if (num > temp[available])
            temp[available] = num;
          //cout << "M[a] (after): " << temp[available] << endl;
        }
      }
      for(map<int,int>::iterator it = temp.begin();
          it != temp.end();
          it++)
      {
        if (it->second > M[it->first])
          M[it->first] = it->second;
      }
    }
    int maxx = 0;
    for(map<int, int>::iterator it = M.begin();
        it != M.end();
        it++) {
      maxx = max(maxx, it->second);
    }
    cout << maxx << endl;
  }
}
