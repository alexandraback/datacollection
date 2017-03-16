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

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

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

int lawn[M][M];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;++t) {
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                scanf("%d", &lawn[i][j]);

        printf("Case #%d: ",t);

        while(1) {
            int minx=0, miny=0;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j) {
                    if(lawn[i][j] < lawn[minx][miny]) {
                        minx = i;
                        miny = j;
                    }
                }

            if(lawn[minx][miny] == INF) {
                puts("YES");
                break;
            }

            bool horizontal = true;
            for(int i=0;i<m && horizontal;++i)
                if(lawn[minx][i] != INF && lawn[minx][i] != lawn[minx][miny])
                    horizontal = false;

            if(horizontal)
                for(int i=0;i<m;++i)
                    lawn[minx][i] = INF;

            bool vertical = true;
            for(int i=0;i<n && vertical;++i)
                if(lawn[i][miny] != INF && lawn[i][miny] != lawn[minx][miny])
                    vertical = false;

            if(vertical)
                for(int i=0;i<n;++i)
                    lawn[i][miny] = INF;

            if(!horizontal && !vertical) {
                puts("NO");
                break;
            }
        }
    }
    return 0;
}

