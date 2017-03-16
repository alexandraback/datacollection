#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define PI 3.141592653589793238462643
#define MOD 1000000009
#define eps 1e-8
const int inf = 1000000005;
const int dr[]={0,1,0,-1,1,1,-1,-1};
const int dc[]={1,0,-1,0,1,-1,1,-1};

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> mat; 
typedef pair<int,int> pii;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n) 
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

#define MAX_N	100
int X[MAX_N];

int calc(int n, int p) { // 0 imp, 1 pos, 2 need surp
	int r = n%3;
	int t = n/3;
	
	if (n == 0 && p == 1) return 0;
	
	if (t >= p) return 1;
	else if (t == p-1) {
		if (r == 0) return 2;
		else return 1;
	} else if (t == p-2) {
		if (r == 2) return 2;
		else return 0;
	} else {
		return 0;
	}
}	


int main() {
	int T, N, S, p;
	cin >> T;
	int loop = 1;
	while (loop <= T) {
		
		
		cin >> N >> S >> p;
		for (int i = 0; i < N; i++) cin >> X[i];
		
		sort(X,X+N);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int t = calc(X[i], p);
			//cout << t << endl;
			if (t == 1) ans++;
			else if (t == 2 && S > 0) {
				ans++;
				S--;
			}
			
		}
		
		cout << "Case #" << loop << ": " << ans << endl;
		loop++;
	}

	return 0;
}