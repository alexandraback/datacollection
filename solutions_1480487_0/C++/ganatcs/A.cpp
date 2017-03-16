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

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    VI ss(N, 0);
    int sum = 0;
    for (int j = 0; j < N; j++) {
      cin >> ss[j];
      sum += ss[j];
    }
    VI get(N, 0);

    int t = sum;
    while(t > 0) {
      int mini = 0;
      for (int j = 0; j < N; j++) {
	if (ss[mini] > ss[j]) mini = j;
      }
      t--;
      get[mini]++;
      ss[mini]++;
    }

    VI sorted = ss;
    sort(ALL(sorted));
    cout << "Case #" << i + 1 << ":";

    for (int j = 0; j < N; j++) {
      double ans = 0;
      if (ss[j] < sorted[1]) {
	ans = (get[j] + (sorted[1] - ss[j])) * 100.0 / sum;
      } else if (get[j] > 0 && ss[j] > sorted[0] && sorted[0] == sorted[1]) {
	ans = (get[j] - 1) * 100.0 / sum;
      } else {
	ans = get[j] * 100.0 / sum;
      }
      printf(" %f", ans);
    }
    cout << endl;
 }
  return 0;
}
