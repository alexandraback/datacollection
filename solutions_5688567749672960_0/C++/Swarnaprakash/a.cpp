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

const int M = 1000000 + 5;
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

int memo[M];

int reverse_n(int n) {
    stringstream ss;
    ss<<n;

    string s;
    ss>>s;
    reverse(ALL(s));

    stringstream ss2;
    int rn;
    ss2<<s;
    ss2>>rn;

    return rn;
}

int compute(int n) {
    int &ans = memo[n];
    if(ans != -1) return ans;

    if(n == 1) return 1;

    int rn = reverse_n(n);
    ans = 1+compute(n-1);

    if(n%10 !=0 && rn < n) ans = min(ans, 1 + compute(rn));
    return ans;
}

int main() {

    SET(memo,-1);
    for(int i=1;i<1000000;++i) compute(i);

    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;++t) {
        int x;
        scanf("%d",&x);
        printf("Case #%d: %d\n",t,compute(x));
    }
    return 0;
}

