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

int get_digits(int n) {
    if(n<10) {
        return 1;
    } else if(n<100) {
        return 2;
    } else if(n<1000) {
        return 3;
    } else if(n<10000) {
        return 4;
    } else if(n<100000) {
        return 5;
    } else if(n<1000000) {
        return 6;
    } else if(n<10000000) {
        return 7;
    } else {
        assert(0);
    }
}

int get(int a, int b) {
    int d = get_digits(a);
    if(d == 1) {
        return 0;
    }
    int p = 1;
    for(int k=0;k<d-1;++k)
        p*=10;

    int ans = 0;
    for(int i=a;i<=b;++i) {
        int x = i;
        int done[d-1];
        for(int k=0;k<d-1;++k) {
            int ld = x%10;
            x = ld * p + x/10;
            done[k] = x;
            bool flag= true;
            for(int j=0;j<k;++j)
                if(done[j] == x)
                    flag= false;
            if(flag && x > i && x >=a && x <= b) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        int a,b;
        scanf("%d %d",&a, &b);
        printf("Case #%d: %d\n",t,get(a,b));
    }
	return 0;
}

