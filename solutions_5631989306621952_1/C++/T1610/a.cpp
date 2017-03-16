#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
 
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-7;


int main(){
	int mCase;
	scanf("%d", &mCase);
	int l;
	char c[1500];
	for(int Case = 1; Case <= mCase; Case++){
		scanf("%s", c);
		l = strlen(c);
		string s, t, u;
		s += c[0];
		for(int i = 1; i < l; i++){
			t = c[i] + s;
			u = s + c[i];
			s = (t<u?u:t);
		}
		printf("Case #%d: %s\n", Case, s.c_str());
	}
}