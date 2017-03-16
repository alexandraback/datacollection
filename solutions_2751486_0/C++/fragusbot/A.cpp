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
#define foreach(it, v) for(__typeof (v).begin() it = (v).begin(); it != (v).end(); ++it)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x) * (x))
#define fill(v, c) memset((v), (c), sizeof (v))
#define DBG(x) cout << #x << " = " << x << endl

template<class T> T abs(T x) { return x > 0 ? x : -x; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1ll << 60;
const int MOD = 1e9 + 7;

int n;
string s;

bool is(char c){
	return (c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u');
}
bool can(string str){
	int cnt = 0;
	for(int i = 0; i < sz(str); i++){
		if(is(str[i])) cnt++;
		else cnt = 0;
		if(cnt == n) return true;
	}
	return false;
}

int main(){
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cin >> s;
		scanf("%d", &n);
		int m = sz(s);
		int ans = 0;
		for(int i = 0; i < m; i++){
			for(int j = 1; j <= m - i; j++){
				string k = s.substr(i, j);
				if(can(k)) ans++;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
