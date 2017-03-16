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
const bool debug = true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector < int >VI;
typedef vector < string > VS;
typedef vector < VI > VVI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;

int n;
vector < pair < string, string > >topics;

int memo[17][(1 << 17) + 5];

int best(int index, int mask)
{

    int &ans = memo[index][mask];

    if (ans != -1) {
	return ans;
    }

    bool first = false;
    for (int i = 0; i < n && !first; ++i) {
	if ((mask & (1 << i)) && topics[i].first == topics[index].first) {
	    first = true;
	}
    }

    bool second = false;
    for (int i = 0; i < n && !second; ++i) {
	if ((mask & (1 << i)) && topics[i].second == topics[index].second) {
	    second = true;
	}
    }

    bool fake = first && second;

    int cur = fake ? 1 : 0;
    ans = cur;

    for (int i = 0; i < n; ++i) {
	if (i != index && !(mask & (1 << i))) {
	    int new_mask = mask;
	    new_mask |= 1 << index;
	    ans = max(ans, cur + best(i, new_mask));
	}
    }

    return ans;
}

int main()
{

    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; ++t) {

        scanf("%d", &n);

	topics.clear();

	string x, y;
	for (int i = 0; i < n; ++i) {
	    cin >> x >> y;
	    topics.push_back(make_pair(x, y));


	}
        SET(memo, -1);

        int ans = best(0, 0);

        for(int i=1;i<n;++i) {
            ans = max(ans,best(i,0));
        }
        printf("Case #%d: %d\n", t, ans);

    }

    return 0;
}
