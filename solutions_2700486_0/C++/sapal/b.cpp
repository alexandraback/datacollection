#define dbg if(0)
#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<utility>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FWD(i,b,n) for(int i=(b);i<(n);++i)
#define BWD(i,b,n) for(int i=(int)(n)-1;i>=(b);--i)
#define FOREACH(it,c) for(__typeof((c).end()) it=(c).begin();it!=(c).end();it++)
typedef long long LL;
const int MAXL = 10;
const int MIND = 5;
const int OO = (1<<30)-1;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;

double factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n-1);
}

double binom(int n, int k) {
  if (k > n) return 0;
  return factorial(n) / factorial(k) / factorial(n-k);
}

double solve() {
  int n, x, y;
  cin >> n >> x >> y;
  if (x < 0) x *= -1;
  int s = 1;
  int r = 1;
  while (s + 2*r+3 <= n) {
    s += 2*r+3; 
    r += 2;
  }
  if (x+y < r) return 1;
  if (x+y > r+1) return 0;
  int N = n - s;
  dbg cout << "N: " << N << ", r: "<< r << endl;
  while (N > r+1) {
    N -= 2;
    r -= 1;
    y -= 1;
  }
  dbg cout << "N: " << N << ", r: "<< r << endl;
  int NN = r+1;
  int K = max(0,y+1);
  double res = 0;
  FWD(k,K,NN+1) {
    res += binom(NN,k) / (1<<NN);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int z;
  cin >> z;
  cout.precision(6);
  FOR(i,z) {
    cout << "Case #" << i+1 << ": " << fixed << solve() << endl;
  }
  return 0;
}
