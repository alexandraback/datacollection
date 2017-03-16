#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef tuple<int, int, int> TIII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

const double EPS = 1e-10;
const double PI  = acos(-1.0);

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	FOR(test, 1, T + 1){
		cout << "Case #" << test << ": ";

		int N;
		cin >> N;
		VI BFF(N), A(N);
		REP(i, N){
			int b;
			cin >> b;
			BFF[i] = b - 1;
			A[i] = i;
		}

		int ret = 0;
		do{
			FOR(i, 2, N){
				bool ok = true;
				REP(j, i + 1){
					if(j == 0){
						if(BFF[A[j]] != A[j + 1] && BFF[A[j]] != A[i]){
							ok = false;
							break;
						}
					}
					else if(j == i){
						if(BFF[A[j]] != A[0] && BFF[A[j]] != A[j - 1]){
							ok = false;
							break;
						}
					}
					else{
						if(BFF[A[j]] != A[j + 1] && BFF[A[j]] != A[j - 1]){
							ok = false;
							break;
						}
					}
				}
				if(ok){
					ret = max(ret, i + 1);
					//cout << ret << " : ";
					//EACH(a, A) cout << a + 1 << " ";
					//cout << endl;
				}
			}
		}while(next_permutation(ALL(A)));

		cout << ret << endl;


	}


	return 0;
}
