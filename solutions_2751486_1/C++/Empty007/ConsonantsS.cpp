#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

typedef long long ll;

int main() { 
	int T, c;
    string S;
    cin >> T;
    REP(tc, T) {
        cin >> S >> c;
        int L = S.length();
        ll fin = 0;
        int lg = -1, cnt = 0;
        REP(i, L) {
            if (S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u') cnt++;
            else cnt = 0;
            if (cnt >= c) {
                lg = i;
            }
            if (lg != -1)
                fin += lg+1-c+1;
        }
//        REP(i, L) REPN(j, i, L) {
//            int sz = j - i + 1;
//            string A = S.substr(i, sz);
//            int cnt = 0, good = 0;
//            REP(k, A.length()) {
//                if (A[k] != 'a' && A[k] != 'e' && A[k] != 'i' && A[k] != 'o' && A[k] != 'u') cnt++;
//                else cnt= 0;
//                if (cnt >= c) good = 1;
//            }
//            fin += good;
//        }
		printf("Case #%d: %lld\n", tc+1, fin);
	}
	
	return 0;
}
