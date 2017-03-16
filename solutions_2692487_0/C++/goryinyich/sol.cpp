#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

int getAns (int a, vector<int>& s) {
    if (a == 1) return s.size();
    
    int bestAns = s.size();
    int adds = 0;
    while (true) {
        sort (s.begin(), s.end());
        int curr = a;
        int i = 0;
        while (i < s.size() && s[i] < curr) curr += s[i++];
        //not adding
        if (i == s.size()) {
            bestAns = min<int>(bestAns, adds);
            return bestAns;
        }
        bestAns = min<int>(bestAns, adds + (s.size() - i));
        //try add
        adds += 1;
        s.push_back(curr-1);
        sort (s.begin(), s.end());
        while (i < s.size() && s[i] < curr) curr += s[i++];
        if (i == s.size()) {
            bestAns = min<int>(bestAns, adds);
            return bestAns;
        }
        bestAns = min<int>(bestAns, adds + (s.size() - i));
    }
    return bestAns;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    REP(ic,tc) {
        int a, n;
        cin >> a >> n;
        vector<int> s(n, 0);
        REP(i,n) cin >> s[i];
        cout << "Case #" << ic+1 << ": " << getAns (a, s) << endl;
    }
	return 0;
};