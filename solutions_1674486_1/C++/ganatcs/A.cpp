#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <bitset>
#include <queue>
using namespace std;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

//constant
const double EPS = 1e-10;
const int MAXI = 1234567890;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



void printList(vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
	cout << v[i] << " ";
  }
  cout << endl;
}

void printMatrix(vector< vector<int> >& v) {
  for (size_t i = 0; i < v.size(); i++) {
	printList(v[i]);
  }
  cout << endl;
}

bool search(int a, int N, VVI& gra, vector<bool>& visited) {
  if (visited[a]) return false;
  visited[a] = true;
  for (int i = 0; i < SZ(gra[a]); i++) {
    bool t = search(gra[a][i], N, gra, visited);
    if (t == false) return false;
  }
  return true;
}


bool solve(int N, VVI& gra) {

  VI count(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < SZ(gra[i]); j++) {
      count[gra[i][j]]++;
    }
  }

  VI start;
  for (int i = 1; i <= N; i++) {
    if (count[i] == 0) start.PB(i);
  }

  for (int i = 0; i < SZ(start); i++) {
    vector<bool> visited(N + 1, false);
    bool t = search(start[i], N, gra, visited);
    if (t == false) return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    VVI gra(N + 1, VI());
    for (int j = 0; j < N; j++) {
      int M;
      cin >> M;
      for (int k = 0; k < M; k++) {
	int t;
	cin >> t;
	gra[j + 1].PB(t);
      }
    }
    bool ans = solve(N, gra);
    cout << "Case #" << i + 1 << ": ";
    if (ans == false) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
