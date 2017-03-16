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
    string t;
    string answer;

    cin >> t;

    for (int i = 0;i < t.size();i++) {
      if (answer.empty() || t[i] >= answer[0])
        answer.insert(answer.begin(), t[i]);
      else
        answer.push_back(t[i]);
    }

    cout << "Case #" << games << ": " << answer << endl;
  }

  return 0;
}
