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
vector< pair<int,int> >flight;
int main() {
  int T;
  cin>>T;
  for(int cid=1; cid <= T; cid++) {
    int N, M;
    cin>>N>>M;

    // init
    flight.clear();

    for(int i=0; i < N; i++) {
      cin>>zipCode[i];
    }
    for(int i=0; i < M; i++) {
      int from, to;
      cin>>from>>to;
      from--; to--;
      flight.pb( make_pair(from, to) );
    }

    vector<int> permu;
    for(int i=0; i < N; i++) {
      permu.pb(i);
    }
    sort(all(permu));
    vector<string> res(N, "99999");

    do {
      // check if it is worth checking out
      // cout<<"Look at ";
      // for(int i=0; i < N; i++)
      //   cout<<permu[i]<<" ";
      // cout<<endl;
      bool isGood = true;
      for(int i=0; isGood && i < N; i++) {
        // isGood &= zipCode[permu[i]] <= res[i];
        // if(!isGood) {
        //   cout<<"Failed at i = "<<i<<" because "<<zipCode[permu[i]]<<" > "<<res[i]<<endl;
        // }
        if(zipCode[permu[i]] < res[i]) break;
        if(zipCode[permu[i]] > res[i]) {
          isGood = false;
        }
      }

      if(!isGood) continue;

      // cout<<"=================="<<endl;
      // cout<<"checking ";
      // for(int i=0; i < N; i++)
      //   cout<<permu[i]<<" ";
      // cout<<endl;

      bool isPossible = true;

      int curPos = permu[0];
      vector<bool> flightUsed(M, false);
      stack< pair<int,int> >returnFlights;

      for(int i=1; isPossible && i < N; i++) {
        int dst = permu[i];
        // cout<<"Looking for "<<curPos<<" to "<<dst<<endl;
        // check if there is flight we can use
        bool foundFlight = false;
        bool canSearch = true;
        while(canSearch && !foundFlight) {

          for(int j=0; !foundFlight && j < M; j++) {
            if(flightUsed[j]) continue;
            // cout<<"Lookin at "<<flight[j].first<<" to "<<flight[j].second<<endl;
            if((flight[j].first == curPos && flight[j].second == dst)
            || (flight[j].first == dst && flight[j].second == curPos)) {
              // use this flight
              foundFlight = true;
              // cout<<"Flight found"<<endl;
              flightUsed[j] = true;
              returnFlights.push( make_pair(curPos, dst) );
              curPos = dst;
            }
          }

          if(!foundFlight) {
            if(!returnFlights.empty()) {
              pair<int, int> returnF = returnFlights.top();
              returnFlights.pop();
              if(curPos != returnF.second) {
                cout<<"WTF!!!!!!"<<endl;
              }
              curPos = returnF.first;

            } else {
              canSearch = false;
            }

          }
        }
        isPossible &= foundFlight;
      }

      if(isPossible) {
        // cout<<"And Possible"<<endl;
        for(int i=0; i < N; i++) {
          res[i] = zipCode[permu[i]];
        }
      }

    }while( next_permutation(all(permu)) );

    //convert res to resStr

    cout<<"Case #"<<cid<<": ";
    for(int i=0; i < N; i++) {
      cout<<res[i];
    }
    cout<<endl;
  }

  return 0;
}
