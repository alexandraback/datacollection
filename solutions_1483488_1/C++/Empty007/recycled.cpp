#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

bool vis[2000005];

int main() {
	int T, a, b;
	cin >> T;
	int nros[10];
	nros[0] = 1;
	for (int i = 1; i < 9; i++) nros[i] = 10 * nros[i-1];
	REP(tc, T) {
		CLR(vis, 0);
		cin >> a >> b;
		
		int diez = 0;
		for (int i = 0; i < 9; i++) if (a >= nros[i]) diez = i;
		
		int cnt = 0;
		for (int i = a; i < b; i++) if (!vis[i]) {
			if (i >= nros[diez+1]) diez++;
			int t = i;
			set <int> seti;
			seti.insert(t);
			for (int j = 0; j < diez; j++) {
				int less = t % 10;
				t /= 10;
				t += (less * nros[diez]);
				if (t > i && t <= b) {
					seti.insert(t);
				}
			}
			cnt += int(seti.size() - 1);
		}
		printf("Case #%d: %d\n", tc+1, cnt);
	}
	
	return 0;
}
