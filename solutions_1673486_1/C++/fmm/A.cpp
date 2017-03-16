#include <bits/stdc++.h>
#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define X first
#define Y second
using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 100000;
int A, B;
double p[maxn];

int main() {
	int T;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		cin >> A >> B;
		rep(i,A) cin >> p[i + 1];
		double correct = 1.0, res = B + 2.0;
		rep(i,A + 1) {
			if(i) correct *= p[i];
			double expected = ((A-i)+(B-i)+1)*correct + ((A-i)+(B-i)+1+(B+1))*(1-correct);
			if(expected < res) res = expected;
		}
		printf("Case #%d: %.6lf\n",caso,res);
	}
  return 0;
}

