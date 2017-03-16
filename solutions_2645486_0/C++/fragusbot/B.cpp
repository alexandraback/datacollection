#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i < (b); i++)
#define foreach(it, c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); ++it)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sqr(x) ((x) * (x))
#define clr(m, c) memset((m), (c), sizeof (m))
#define DBG(x) cout << #x << " = " << x << endl
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

template<class T> T abs(T x) { return x > 0 ? x : -x; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = -10000000;
const ll MOD = 1000000007;

int E, R, N;
int v[50];

int go(int i, int e){
	if(i == N) return 0;
	int ret = INF;
	for(int j = 0; j <= e; j++)
		ret = max(ret, go(i + 1, min(E, e - j + R)) + v[i] * j);
	return ret;
}

int main(){
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cin >> E >> R >> N;
		rep(i, N) cin >> v[i];
		printf("Case #%d: %d\n", t, go(0, E));
	}
	return 0;
}

