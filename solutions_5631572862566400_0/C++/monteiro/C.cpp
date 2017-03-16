#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define pb push_back
#define pf push_front

#define fori(n)  for(int i=0;i<n;i++)
#define forj(n)  for(int j=0;j<n;j++)
#define fork(n)  for(int k=0;k<n;k++)
#define forit(v) for(it = v.begin();it != v.end();it++)

#define trace(x...) x
#define print(x...) trace(printf(x))
#define watch(x) trace(cout << #x" = " << x << "\n")

#define INF 0x3F3F3F3F // Signed int
//#define INF 0x3F3F3F3F3F3F3F3FLL // Signed int64
#define EPS 1e-10
#define PI 3.14159265358979323846

int cmpD(double a, double b){
	return (a <= b + EPS) ? (a + EPS < b) ? -1 : 0 : 1;
}

using namespace std;

typedef pair<int,int> pairii;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<bool> vbool;
typedef vector<string> vstring;
typedef long long int64;
typedef unsigned long long Uint64;
typedef unsigned int Uint;
typedef unsigned char Uchar;

int main() {

  int total;
  cin >> total;

  for (int games = 1;games <= total;games++) {
    int n;
    cin >> n;

    vector<int> bff(n, 0);
    vector<int> in(n, 0);
    vector<int> mybetter(n, 0);
    vector< vector<int> > counter(n, vector<int>(n, 0));

    fori(n) {
      int t;
      cin >> t;
      t--;
      bff[i] = t;
      in[t]++;
    }

    stack<int> st;

    fori(n)
      if (in[i] == 0)
        st.push(i);

    while (!st.empty()) {
      int t = st.top();
      st.pop();
      int better = 0;
      fori(n)
        better = max(better, counter[t][i]);

      if (--in[bff[t]] == 0) {
        st.push(bff[t]);
      }
      counter[bff[t]][t] = better + 1;
    }

    fori(n) {
      int better = 0;
      forj(n)
        better = max(better, counter[i][j]);
      mybetter[i] = better;
    }

    int answer = 0;

    fori (n) {
      if (in[i] == 1) {
        int c = 0;
        int t = i;
        if (in[t] > 1) cout << "fudeu" << endl;
        while (in[t] == 1) {
          in[t] = 0;
          c++;
          t = bff[t];
        }
        if (c == 2) {
          c += mybetter[i];
          c += mybetter[bff[i]];
        }

        answer = max(answer, c);
      }
    }

    cout << "Case #" << games << ": " << answer << endl;
  }

  return 0;
}
