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
void outr(int k) {
  for (int i = 0; i < k; i++) {
    cout << "2";
  }
}


void output(int t, int k, int& count) {
  for (int i = 0; i < k; i++) {
    cout << t;
    count++;
  }
  return;
}

void out2(int rest, int n2, int n4) {
  if (rest == 0) return;
  if (rest == 1) {
    if (n4 != 0) {
      cout << 4;
      return;
    } else if (n2 != 0) {
      cout << 2;
      return;
    } else {
      outr(1);
      return;
    }
  }
  if (rest == 2) {
    if (n4 == 2) {
      cout << "44";
      return;
    } else if (n2 == 3) {
      cout << "24";
      return;
    } else if (n2 == 2) {
      cout << "22";
      return;
    } else if (n2 == 1) {
      cout << "2";
      outr(1);
      return;
    } else {
      outr(2);
      return;
    }
  }
  if (rest == 3) {
    if (n2 == 6) {
      cout << "444";
      return;
    } else if (n2 == 5) {
      cout << "244";
      return;
    } else if (n2 == 4) {
      cout << "224";
      return;
    } else if (n2 == 3) {
      cout << "222";
    } else if (n2 == 2) {
      cout << "2";
      outr(2);
      return;
    } else {
      outr(3);
      return;
    }
  }
  return;
}

void solve(int N, int M, int K, VI& nums) {
  VI p(10, 0);

  for (int i = 0; i < K; i++) {
    for (int j = 2; j <= M; j++) {
      int count = 0;
      int t = nums[i];
      while (t % j == 0) {
	count++;
	t /= j;
      }
      p[j] = max(p[j], count);
    }
  }
  int ans = 0;
  output(5, p[5], ans);
  output(3, p[3], ans);
  if (ans == 3) return;
  out2(3 - ans, p[2], p[4]);
  return;
}

int main() {
  cout << "Case #1:" << endl;

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int R, N, M, K;
    cin >> R >> N >> M >> K;

    for (int j = 0; j < R; j++) {
      VI nums(K, 0);
      for (int k = 0; k < K; k++) {
	cin >> nums[k];
      }
      solve(N, M, K, nums);
      cout << endl;
    }
  }
  return 0;
}
