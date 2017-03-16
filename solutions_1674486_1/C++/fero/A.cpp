#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

const int maxn = 1000;

vector<int> edge[maxn];
bool vis[maxn];
int n;


bool diamond;

void up(int x) {
    if (vis[x]) {
	diamond = true;
	return;
    }

    vis[x] = true;
    FOREACH(y, edge[x])
	up(*y);
}
    

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
	cin >> n;
	REP(i, n) {
	    int m;
	    cin >> m;
	    edge[i].resize(m);
	    REP(j, m) {
		int x;
		cin >> x;
		edge[i][j] = x-1;
	    }
	}

	diamond = false;
	REP(i, n) {
	    CLEAR(vis);
	    up(i);
	    if (diamond)
		break;
	}
	    
	cout << "Case #" << cs << ": ";
	cout << (diamond ? "Yes" : "No");
	cout << endl;
    }
}
