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

int num_digits(LL n) {

    stringstream ss;
    ss<<n;

    string s;
    ss>>s;

    return SZ(s);
}

LL reverse_n(LL n) {
    stringstream ss;
    ss<<n;

    string s;
    ss>>s;
    reverse(ALL(s));

    stringstream ss2;
    LL rn;
    ss2<<s;
    ss2>>rn;

    return rn;
}
LL step(int digit_size) {
    LL step_size = 1;

    for(int i=0;i<(digit_size+1)/2;++i) step_size *= (LL) 10;

    return step_size;
}

LL compute(LL n) {
    DB(n);

    if(n <21) return n;

    LL step_size = step(num_digits(n));


    LL near = (n/step_size) * step_size + 1;
    DB(near);

    LL rn = reverse_n(n);

    if(rn == n || near > n) return 1 + compute(n-1);

    if(n == near) return 1+ compute(rn);

    return n-near + compute(near);

}

int main() {

    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;++t) {
        LL x;
        scanf("%lld",&x);
        printf("Case #%d: %lld\n",t,compute(x));
    }
    return 0;
}

