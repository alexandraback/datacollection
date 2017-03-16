// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 1005;
const int INF = 0x3f3f3f3f;
const bool debug=false;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int e[M][M];
int visited[M];
bool diamond;
int n;

void doit(int k) {
    DB(k); DB(visited[k]);
    if(visited[k] != 0) {
        diamond = true;
    }
    if(diamond) return;
    visited[k] = 1;
    for(int i=1;i<=n;++i) {
        DB(e[k][i]);DB(i);
        if(e[k][i] == 1)
            doit(i);
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        scanf("%d",&n);
        SET(e,0);
        for(int i=1;i<=n;++i) {
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;++j) {
                int x;
                scanf("%d",&x);
                e[i][x] = 1;
            }
        }
        bool found = false;
        for(int i=1;i<=n && !found;++i) {
            DB(i);
            diamond = false;
            SET(visited, 0);
            doit(i);
            if(diamond) {
                found = true;
            }
        }
        printf("Case #%d: %s\n",t,(found?"Yes":"No"));
    }
    return 0;
}

