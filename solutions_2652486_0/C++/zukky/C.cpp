#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long lli;

const int MAXN = 10000000;
vector<lli> P;

bool isP[MAXN];

int Ps[7] = {2,2,2,3,3,5,7};

int need[10] = {0,
		0,
		(1<<0),
		(1<<3),
		(1<<0)|(1<<1),
		(1<<5),
		(1<<0)|(1<<3),
		(1<<6),
		(1<<0)|(1<<1)|(1<<2),
		(1<<3)|(1<<4)};


void make() {
  fill(isP, isP + MAXN, true);
  isP[0] = isP[1] = 0;
  for(int i = 2; i < MAXN; ++i) {
    if(!isP[i]) continue;
    P.push_back(i);
    for(int j = i*2; j < MAXN; j += i) {
      isP[j] = false;
    }
  }
}

int factorize(lli n) {
  int res = 0;
  for(int i = 0; i < 7; ++i) {
    if(n % Ps[i] == 0) {
      res |= (1<<i);
      n /= Ps[i];
    }
  }
  return res;
}

struct Random {
  unsigned int operator()(unsigned int max)
  {
    double tmp = static_cast<double>( rand() ) / static_cast<double>( RAND_MAX );
    return static_cast<unsigned int>( tmp * max );
  }
};

int main() {
  srand( static_cast<unsigned int>( time(NULL) ) );
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++ tc) {
    int R, N, M, K;
    cin >> R >> N >> M >> K;
    cout << "Case #" << tc+1 << ":" << endl;
    vector<lli> v(K);
    vector<int> r(K);
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < K; ++j) {
	cin >> v[j];
	r[j] = factorize(v[j]);
      }
      vector<int> res;
      for(int j = 0; j < K; ++j) {
	for(int k = 2; k <= M; ++k) {
	  if((need[k] & r[j]) == need[k]) {
	    res.push_back(k);
	  }
	}
      }
      while(res.size() < N) res.push_back(rand()%(M-2)+2);
      Random r;
      random_shuffle(res.begin(), res.end(), r);
      for(int j = 0; j < N; ++j) cout << res[j];
      cout << endl;
    }
  }
  return 0;
}
