#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define SZ(c) int((c).size())
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long LL;

int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Removes duplicates in the given vector.
// Note that the ORDER of elements is NO LONGER preserved.
template<typename T>
void makeUnique(vector<T>& V) {
  sort(V.begin(), V.end());
  V.resize( distance(V.begin(), unique(V.begin(), V.end())));
}

// Readline using scanf : scanf("%[^\n]\n", input);
string zipCode[100];
vector<int> neighbors[100];

int main() {
  int T;
  cin>>T;
  for(int cid=1; cid <= T; cid++) {
    int N, M;
    cin>>N>>M;

    // init
    // flight.clear();
    for(int i=0; i < N; i++) {
      neighbors[i].clear();
    }

    for(int i=0; i < N; i++) {
      cin>>zipCode[i];
    }
    for(int i=0; i < M; i++) {
      int from, to;
      cin>>from>>to;
      from--; to--;
      neighbors[from].pb(to);
      neighbors[to].pb(from);
    }

    /*
      Fix the start position.
      After we fix the start position, we use backtracking to find the
      smallest route.
      50 starting positions. At most 1225 flight.
      50 * 1225 is small enough.
    */
    vector<string> res(N, "99999");
    for(int root=0; root < N; root++) {
      // cout<<"=============="<<endl;
      // cout<<"root : "<<root<<endl;
      vector<bool> isVisited(N, false);
      isVisited[root] = true;
      vector<string> curRes;
      stack<int> prevCities;
      curRes.pb(zipCode[root]);
      int cur = root;
      bool foundNext = true;
      while(foundNext) {
        // cout<<"cur : "<<cur<<endl;
        // find next unvisited place
        string best = "99999";
        int nextCity = -1;
        foundNext = false;
        for(int i=0; i < neighbors[cur].size(); i++) {
          int possibleCity = neighbors[cur][i];
          if(isVisited[possibleCity]) continue;
          if(zipCode[possibleCity] < best) {
            best = zipCode[possibleCity];
            nextCity = possibleCity;
          }
        }

        if(nextCity == -1) {
          if(!prevCities.empty()) {
            cur = prevCities.top(); prevCities.pop();
            foundNext = true;
          }

        } else {
          isVisited[nextCity] = true;
          foundNext = true;
          curRes.pb( zipCode[nextCity] );
          prevCities.push(cur);
          cur = nextCity;
        }
      }

      if(curRes.size() == N) {
        bool isBetter = true;
        for(int i=0; isBetter && i < N; i++) {
          if(curRes[i] < res[i]) break;
          if(curRes[i] > res[i]) {
            isBetter = false;
          }
        }
        if(isBetter) {
          res = curRes;
        }
      }
    }

    cout<<"Case #"<<cid<<": ";
    for(int i=0; i < N; i++) {
      cout<<res[i];
    }
    cout<<endl;
  }
  return 0;
}
