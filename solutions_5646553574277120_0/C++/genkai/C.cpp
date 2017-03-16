#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int idxCase;
long long int n;
int C,D,V;
int dimo[100];
int coin[1000];


bool filter(int,int);

int main () {

    freopen ("q1.in", "r", stdin); 
    freopen ("q1.out", "w", stdout);


  int idxCase;
  cin >> idxCase;
  for (int it = 1; it <= idxCase; it++) {
    cin >> C >> D >> V;
    for(int i=0; i < D; i++){
      cin >> dimo[i];
    }
    for(int i=0; i<1000;i++){
      coin[i] = 0;
    }

    filter(0,0);

    int answer = 0;
      for(int i=0; i<=V; i++){
        if(coin[i] == 0){
        //  cout<<"add "<<i<<endl;
          answer ++;
          coin[i] = 1;
          dimo[D] = i;
          D++;
          filter(0,0);
        }
      }

    //fill in answer
    cout<<"Case #"<<it <<": "<<answer <<endl;
    fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, idxCase, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * idxCase) / CLOCKS_PER_SEC);
  }
  return 0;
}

bool filter(int level,int sum){
  if(level == D){
    coin[sum] = 1;
    coin[sum+dimo[level]]= 1;
    return true;
  }
  else{
    coin[sum] = 1;
    coin[sum+dimo[level]]= 1;
    filter(level+1, sum + dimo[level]);
    filter(level+1, sum);
  }
}
