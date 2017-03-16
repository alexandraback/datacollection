#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;

int64 INF = 1000*1000*1001;

int LIM = 2000000;

int cnt(int x, int B)  {
    int tmp = x;
    int p10 = 1;
    while (tmp >= 10) {
        tmp /= 10;
        p10 *= 10;
    }
    
    int ret = 0, next = x;
    do {
        next = (next % 10)*p10 + (next / 10);
        if (x < next && next <= B)   ret++;
    } while (next != x);
    return ret;
}

int go(int A, int B)    {
    int ret = 0;
    FOR (i, A, B + 1) {
        ret += cnt(i, B);
    }
    return ret;
}

int main(void)	{
 	int T, A, B;
	cin >> T;
	FOR (nc, 1, T+1)	{
        cin >> A >> B;
		cout << "Case #" << nc << ": " << go(A, B) << endl;
	}
}
