// A esa persona que me hace sentir especial, mas vivo, mas libre.
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

int N;
vector<int> naomi, ken;

void solve() {
    cin >> N;
	ken = naomi = vector<int>(N);
    double aux;
    F(i, N) {
        cin >> aux;
        naomi[i] = int(aux*1000000.0);
    }
    F(i, N) {
        cin >> aux;
        ken[i] = int(aux*1000000.0);
    }
    sort(ALL(naomi));
    sort(ALL(ken));
    int y = 0, z = 0, j1 = 0, j2 = N-1;
    for(int i=N-1; i>=0 ;i--) {
        if(naomi[i] > ken[j2]) {
            z++;
            j1++;
        }
        else j2--;
    }
    j1 = 0, j2 = N-1;
    for(int i=0; i<N ;i++) {
        if(naomi[i] > ken[j1]) {
            y++;
            j1++;
        }
        else j2--;
    }
    cout << y << " " << z << endl;
}

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}
