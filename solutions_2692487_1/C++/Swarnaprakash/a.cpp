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

int A;
int mote[M];
int N;

vector< map<int, int> > memo;

int best(int ind, int curr) {
    if (ind == N) return 0;
    map<int, int>::iterator it = memo[ind].find(curr);
    if (it != memo[ind].end()) {
        return it->second;
    }

    int ans = INF;
    if (curr > mote[ind]) {
        ans = 0 + best(ind +1, curr + mote[ind]);
    } else {
        int ans1 = 1 + best(ind+1, curr);

        int ans2 = 0;
        if (curr != 1) {
            int curr_copy = curr;
            while(curr_copy <= mote[ind]) {
                curr_copy += curr_copy -1;
                ++ans2;
            }
            ans2 += best(ind+1, curr_copy + mote[ind]);
        } else {
            ans2 = INF;
        }
        ans = min(ans1, ans2);
    }

    memo[ind][curr] = ans;
    return ans;

}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        memo.clear();
        scanf("%d %d",&A, &N);
        for(int i=0;i<N;++i) memo.push_back(map<int,int> ());
        for(int i=0;i<N;++i) scanf("%d", &mote[i]);
        sort(mote, mote+N);
        int ans = best(0, A);
        printf("Case #%d: %d\n",t, ans);
    }
    return 0;
}

